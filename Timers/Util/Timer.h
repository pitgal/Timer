#pragma once

#include <chrono>         // chrono::seconds
#include <thread>         // this_thread::sleep_for

class Timer {
private:
  bool abort = false;
  bool aborted = true;
  bool oneShoot;
  int  interval;
  int  delay;

public:
  Timer(const int interval, const bool oneShot = true, const int delay = 0) :
      interval(interval)
    , oneShoot(oneShot)
    , delay(delay) {}

  template<typename Function>
  void run(Function function) {
    aborted = abort = false;
    std::thread t([=] {
      int tmpDelay = delay;
      do {
        if (abort)
          break;
        this_thread::sleep_for(chrono::milliseconds(interval + tmpDelay));
        tmpDelay = 0;
        if (abort)
          break;
        function();
      } while (!oneShoot);
      aborted = true;
      });
    t.detach();
  }

  void stop() {
    abort = true;
  }

  bool isRun() const {
    return !aborted;
  }

  void setTimeout(const int delay) {
    this->delay = delay;
  }
};