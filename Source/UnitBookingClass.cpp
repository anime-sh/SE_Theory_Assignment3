#include "BookingClass.h"
int main()
{
    //non concrete
    BookingClass::UnitTestBookingClass();
    SittingClass::UnitTestSittingClass();
    SleepingClass::UnitTestSleepingClass();
    Sitting0Tier::UnitTestSitting0Tier();
    Sleeping2Tier::UnitTestSleeping2Tier();
    Sleeping3Tier::UnitTestSleeping3Tier();

    // concrete
    SecondSitting::UnitTestSecondSitting();
    ACChairCar::UnitTestACChairCar();
    ACFirstClass::UnitTestACFirstClass();
    AC2Tier::UnitTestAC2Tier();
    FirstClass::UnitTestFirstClass();
    AC3Tier::UnitTestAC3Tier();
    Sleeper::UnitTestSleeper();
}