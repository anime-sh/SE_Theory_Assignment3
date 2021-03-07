#include <iostream>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClass.h"
#include "Booking.h"

void BookingApplication()
{
    std::vector<Station> FromS = {static_cast<Station>("Mumbai"), static_cast<Station>("Delhi")};
    std::vector<Station> ToS = {static_cast<Station>("Kolkata"), static_cast<Station>("Chennai")};


//Mumbai to Kolkata
    Booking lo0_0(FromS[0], ToS[0], Date(1, 1, 2021), SecondSitting::Type());
    Booking lo0_1(FromS[0], ToS[0], Date(1, 1, 2021), ACChairCar::Type());
    Booking lo0_2(FromS[0], ToS[0], Date(1, 1, 2021), ACFirstClass::Type());
    Booking lo0_3(FromS[0], ToS[0], Date(1, 1, 2021), AC2Tier::Type());
    Booking lo0_4(FromS[0], ToS[0], Date(1, 1, 2021), FirstClass::Type());
    Booking lo0_5(FromS[0], ToS[0], Date(1, 1, 2021), AC3Tier::Type());
    Booking lo0_6(FromS[0], ToS[0], Date(1, 1, 2021), Sleeper::Type());

//Delhi to Kolkata
    Booking lo1_0(FromS[1], ToS[0], Date(2, 2, 2021), SecondSitting::Type());
    Booking lo1_1(FromS[1], ToS[0], Date(2, 2, 2021), ACChairCar::Type());
    Booking lo1_2(FromS[1], ToS[0], Date(2, 2, 2021), ACFirstClass::Type());
    Booking lo1_3(FromS[1], ToS[0], Date(2, 2, 2021), AC2Tier::Type());
    Booking lo1_4(FromS[1], ToS[0], Date(2, 2, 2021), FirstClass::Type());
    Booking lo1_5(FromS[1], ToS[0], Date(2, 2, 2021), AC3Tier::Type());
    Booking lo1_6(FromS[1], ToS[0], Date(2, 2, 2021), Sleeper::Type());

//Mumbai to Chennai
    Booking lo2_0(FromS[0], ToS[1], Date(3, 3, 2021), SecondSitting::Type());
    Booking lo2_1(FromS[0], ToS[1], Date(3, 3, 2021), ACChairCar::Type());
    Booking lo2_2(FromS[0], ToS[1], Date(3, 3, 2021), ACFirstClass::Type());
    Booking lo2_3(FromS[0], ToS[1], Date(3, 3, 2021), AC2Tier::Type());
    Booking lo2_4(FromS[0], ToS[1], Date(3, 3, 2021), FirstClass::Type());
    Booking lo2_5(FromS[0], ToS[1], Date(3, 3, 2021), AC3Tier::Type());
    Booking lo2_6(FromS[0], ToS[1], Date(3, 3, 2021), Sleeper::Type());

//Delhi to Chennai
    Booking lo3_0(FromS[1], ToS[1], Date(4, 4, 2021), SecondSitting::Type());
    Booking lo3_1(FromS[1], ToS[1], Date(4, 4, 2021), ACChairCar::Type());
    Booking lo3_2(FromS[1], ToS[1], Date(4, 4, 2021), ACFirstClass::Type());
    Booking lo3_3(FromS[1], ToS[1], Date(4, 4, 2021), AC2Tier::Type());
    Booking lo3_4(FromS[1], ToS[1], Date(4, 4, 2021), FirstClass::Type());
    Booking lo3_5(FromS[1], ToS[1], Date(4, 4, 2021), AC3Tier::Type());
    Booking lo3_6(FromS[1], ToS[1], Date(4, 4, 2021), Sleeper::Type());

//use type deduction
    for (auto booking : Booking::sBookings)
    {
        std::cout << *booking;
    }
}
int main()
{
    BookingApplication();
    return 0;
}