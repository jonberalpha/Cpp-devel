#pragma once

#include <iostream>
#include <Spider.h>
#include <UltraSound.h>
#include <Utils.h>

namespace Tundlbahn
{
  class SpiderCtrl
  {
  private:
    SpiderLib::Spider *spider;
    PiLib::UltraSound *distancesensor;
    PiLib::IPin *buzzer;
    int calibx;
    int caliby;

  public:
    // Ctor
    SpiderCtrl();
    // Dtor
    ~SpiderCtrl()
    {
      delete spider;
      delete distancesensor;
      buzzer = nullptr;
    }

    void init(int calibx, int caliby);
    void run(int velocity);

    double getDistance();
    void doSound(int time_ms);
  };
}
