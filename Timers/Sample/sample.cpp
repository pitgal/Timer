#include <iostream>       // cout 
#include <chrono>         // chrono::seconds
#include <thread>         // this_thread::sleep_for
#include "../Util/Timer.h"

using namespace std;

int main()
{
  Timer timer1(332, false, 1500);
  timer1.run([] {
    cout << "repetitive action" << endl;
    });

  Timer timer2(4000);
  timer2.run([&]() {
    cout << "timer2 stops timer1" << endl;
    timer1.stop();
    });

  Timer timer3(7000);
  timer3.run([&]() {
    cout << "timer3 run timer1" << endl;
    timer1.run([] {
      cout << "repetitive another action" << endl;
      });
    });

  for (int i = 0; i < 15; ++i) {
    cout << i << endl;

    if (i == 12 && timer1.isRun()) {
      cout << "main() stops timer1" << endl;
      timer1.stop();
    }

    this_thread::sleep_for(chrono::seconds(1));
  }

  return 0;
}