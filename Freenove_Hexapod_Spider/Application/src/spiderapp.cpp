#include <SpiderCtrl.hpp>

int main()
{
  Tundlbahn::SpiderCtrl spider = Tundlbahn::SpiderCtrl();

  spider.init(-2, -10); // forword -2,-10; backward 2,10; right -10,-2, left 10,2

  spider.doSound(750); // do sound

  spider.run(1000); // run with low velocity

  return 0;
}
