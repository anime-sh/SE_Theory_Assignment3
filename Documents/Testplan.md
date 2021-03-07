# Test Plan #
### Animesh Jha  19CS10070 ###
(Assuming all input is correct, haven't implemented exception and error handling)

NOTE: All checking is done against golden outputs, the unit testing code by itself **doesnt** check correctness, to automate the checking I have provided bash scripts under `../Source/TestingScripts`
# Unit Tests Source Files #
Number | Header File | Unit Test Implementation
| :--- | :--- | :---
1| `Booking.h` | `Booking.cpp` and `UnitTestBooking.cpp` 
2| `Date.h` |`Date.cpp` and `UnitTestDate.cpp`
3| `Railways.h` |`Railways.cpp` and `UnitTestRailways.cpp`
4| `Station.h` |`Station.cpp` and `UnitTestStation.cpp`
5| `BookingClass.h` |`BookingClass.cpp` and `UnitTestBookingClass.cpp`
5| All |`testing.cpp` and `customtesting.cpp`

# Running the Tests
Go to `../Source/TestingScripts/` and run the relevant bash script, the script compiles the relevant code, runs it, stores it in `../Outputs/` using a `DD_MM_YYYY_<testname>.log` format, after this it checks the output against the golden output provided in `../Outputs/GoldenOutputs/` and tells you if the code passed the unit test 

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

## Railways ##

1. Checked for singleton property
2. Checked list of stations (and output operator)
3. Checked distances between stations (and output operator)
```cpp
    // (from Railways.cpp)
    void Railways::UnitTestRailways()
    { 
        //get instance
        const Railways &instance = Railways::IndianRailways();
        
        // check for singleton property
        const Railways &instanceCopy = Railways::IndianRailways();
        std::cout << ((&instance != &instanceCopy)?"Not a Singleton":"Singleton") << std::endl;  // POINT 1
        
        //check output operator
        std::cout << Railways::IndianRailways() << std::endl;  //POINT 2 and 3
    }
```

## Station ##

1. Checked constructor and copy constructor
1. Checked output operator
1. Checked method GetName()
1. Checked method GetDistance()

```cpp
    // (from Station.cpp)
    void Station::UnitTestStation()
    {
        // Check Constructors POINT 1
        Station s1("Mumbai");
        Station s2(s1);

        //check output stream operator POINT 2
        std::cout << s1;
        std::cout << s2;

        //check GetName POINT 3
        std::cout << s1.GetName() << " " << s2.GetName() << std::endl;

        //Check GetDistance POINT 4
        std::cout << "Distance between Mumbai and Delhi " << s1.GetDistance("Delhi") << std::endl;
        std::cout << "Distance between Mumbai and Chennai " << s2.GetDistance("Chennai") << std::endl;
    }
```

## Date ##

1. Checked Constructor
1. Checked copy constructor
1. Checked output operator

```cpp
    // (from Date.cpp)
    void Date::UnitTestDate()
    {
        //checking constructors 
        Date d1(30, 8, 2001); //POINT 1
        Date d2(d1); //POINT 2

        //checking output stream
        std::cout << d1 << " " << d2 << std::endl; //POINT 3
    }
```


## Booking Class ##

1. Checked Non Concrete Classes, I did this by passing a relevant derieved concrete class to a non concrete class reference  checking `NumTiers_` and `Berth_`
```cpp
    // (from BookingClass.cpp)
    void SittingClass::UnitTestSittingClass()
    {
        std::cout << "Unit Testing SittingClass" << std::endl;
        SecondSitting a1;
        SittingClass &ut1 = a1;
        std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
        std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
    }
```
2. Checked Concrete Classes attributes via the  output operator and singleton property 
```cpp
    // (from BookingClass.cpp)    
    void AC3Tier::UnitTestAC3Tier()
    {
        const AC3Tier &lo = AC3Tier::Type();
        const AC3Tier &lo_ = AC3Tier::Type();

        // check for singleton
        std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

        //check output operator
        std::cout << lo << std::endl;
    }
```

## Application Testing ##
1. Provided tests: ran the code given in section C, **CHANGED BookingClasses to BookingClass** (please refer to ../Source/README.md for more info). Use the script `../Source/TestingScripts/testing.sh` for running these tests.
2. Custom tests: Checked the bookings for 28 cases (2 x 2) stations and all 7 booking classes.  Use the script `../Source/TestingScripts/customtesting.sh` for running these tests.
    