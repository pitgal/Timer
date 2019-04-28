#include "gtest/gtest.h"
#include "../Util/Timer.h"

using namespace std;

struct Tests : testing::Test {
  Timer timer1{ 1000 };
  Timer* timer2 = new Timer(1000);
};

TEST_F(Tests, Timer1IsNotRunning) {
//  EXPECT_EQ(1, 1);
  EXPECT_TRUE(timer1.isRun()==false);
}

TEST_F(Tests, Timer1IsRunning) {
  timer1.run([] {
    cout << "Action" << endl;
  });  
  EXPECT_TRUE(timer1.isRun());
}

TEST_F(Tests, Timer2IsNotRunning) {
  //  EXPECT_EQ(1, 1);
  EXPECT_TRUE(timer2->isRun() == false);
}

TEST_F(Tests, Timer2IsRunning) {
  timer2->run([] {
    cout << "Action" << endl;
    });
  EXPECT_TRUE(timer2->isRun());
}