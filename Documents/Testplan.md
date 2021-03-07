# Test Plan #
### Animesh Jha  19CS10070 ###
(Assuming all input is correct, haven't implemented exception and error handling)

NOTE: All checking is done against golden outputs, the unit testing code by itself doesnt check correctness, to automate the checking I have provided bash scripts under `../Source/TestingScripts`
# Unit Tests Source Files #
Number | Header File | Unit Test Implementation
| :--- | :--- | :---
1| `Booking.h` | `Booking.cpp` and `UnitTestBooking.cpp` 
2| `Date.h` |`Date.cpp` and `UnitTestDate.cpp`
3| `Railways.h` |`Railways.cpp` and `UnitTestRailways.cpp`
4| `Station.h` |`Station.cpp` and `UnitTestStation.cpp`
5| `BookingClass.h` |`BookingClass.cpp` and `UnitTestBookingClass.cpp`
5| All |`testing.cpp` and `customtesting.cpp`

# Class-wise Scenario Description

## Booking ##
1. Checked working of constructor with all possible Booking Classes 
```cpp
    // (from customtesting.cpp)
    Booking lo0_0(FromS[0], ToS[0], Date(1, 1, 2021), SecondSitting::Type());
    Booking lo0_1(FromS[0], ToS[0], Date(1, 1, 2021), ACChairCar::Type());
    Booking lo0_2(FromS[0], ToS[0], Date(1, 1, 2021), ACFirstClass::Type());
    Booking lo0_3(FromS[0], ToS[0], Date(1, 1, 2021), AC2Tier::Type());
    Booking lo0_4(FromS[0], ToS[0], Date(1, 1, 2021), FirstClass::Type());
    Booking lo0_5(FromS[0], ToS[0], Date(1, 1, 2021), AC3Tier::Type());
    Booking lo0_6(FromS[0], ToS[0], Date(1, 1, 2021), Sleeper::Type());
    // ... 
```
2. Checked output (output stream and pnr, fare calculation )
```cpp
    // (from Booking.cpp)
    void Booking::UnitTestBooking()
    {

        Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
        std::cout << b1 << std::endl; // RELEVANT LINE
    // ...
```
3. Checked if static members are correctly initialised and other data members not displayed in output (`BookingStatus_`) are correctly initialised
```cpp
    // (from Booking.cpp)
    void Booking::UnitTestBooking()
    {

        Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
        std::cout << b1 << std::endl;
        std::cout << "BookingStatus_ = " << b1.BookingStatus_ << "\n";
        std::cout << "sBaseFarePerKM = " << Booking::sBaseFarePerKM << "\n";
        std::cout << "sACSurcharge = " << Booking::sACSurcharge << "\n";
        std::cout << "sLuxuryTaxPercent = " << Booking::sLuxuryTaxPercent << "\n";
        std::cout << "sBookingPNRSerial = " << Booking::sBookingPNRSerial << "\n";
    }
```

## Booking Classes ##

