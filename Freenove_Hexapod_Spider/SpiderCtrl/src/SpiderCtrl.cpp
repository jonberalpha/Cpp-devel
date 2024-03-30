#include <SpiderCtrl.hpp>
#include <RaspiLib.h>
#include <ErrorCode.h>
#include <IPin.h>

namespace Tundlbahn
{
  SpiderCtrl::SpiderCtrl()
  {
    // Instantiate spider- and distancesensor-object
    spider = new SpiderLib::Spider();
    spider->Init(); // init all servos and the RaspiLib-instance
    distancesensor = new PiLib::UltraSound(PiLib::PIN13_GPIO27_PCMD, PiLib::PIN15_GPIO22);
  }

  void SpiderCtrl::init(int calibx, int caliby)
  {
    // set calibration values
    this->calibx = calibx;
    this->caliby = caliby;

    // set buzzer pin
    PiLib::IPin &pin = PiLib::RaspiLib::GetInstance().GetPin(PiLib::PIN11_GPIO17);
    if (pin.GetGPIONumber() != PiLib::GPIO_DUMMY)
    {
      buzzer = &pin;
    }
    pin.SetPinMode(PiLib::FSEL_OUTP);

    spider->Raise(-60); // Raise the Spider
  }

  void SpiderCtrl::run(int velocity)
  {
    double distance = 0;
    int i = 0;

    while (true)
    {
      distance = getDistance();
      std::cout << distance << "\n"; // print out distance
      if (distance < 40)
      {
        distance = getDistance();
        if (distance < 40)
        {
          distance = getDistance();
          if (distance < 40)
          {
            distance = getDistance();
            if (distance < 40)
            {
              doSound(750);
              for (i = 0; i < 8; i++)
              {
                distance = getDistance();
                std::cout << distance << "\n";                   // print out distance
                spider->run(caliby, calibx + 1, velocity, 0, 1); // step right
              }
              doSound(750);
            }
          }
        }  
      }
      else
      {
        spider->run(calibx, caliby, velocity, 0, 1); // checkObsticle() not implemented
      }
      // Utils::delay_ms(10);
    }
  }

  double SpiderCtrl::getDistance()
  {
    return distancesensor->GetDistance();
  }

  void SpiderCtrl::doSound(int time_ms)
  {
    buzzer->WriteBool(true);
    Utils::delay_ms(time_ms);
    buzzer->WriteBool(false);
  }
}
