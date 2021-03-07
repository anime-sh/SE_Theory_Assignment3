# Design File
### Animesh Jha  19CS10070 ###
NOTE: In my solution I have used  `BookingClass` instead of `BookingClasses` please note the slight difference in naming while evaluating.

# High Level Design (HLD)
## Design Principles ##
The following design principles were adhered to in HLD:
1. Flexible & Extensible Design
    1. The design should be flexible. It should be easy to change the changeable parameters (like
        base rate, load factor etc.) easily from the application space. This should not need re-building
        of the library of classes.
    2. The design should be extensible. It should be easy to add new classes anywhere. Should not
        require a re-coding.
2. Minimal Design
    1. Used type deduction `auto` wherever possible to improve readability
    2. Only the stated models and behaviour should be coded. No extra class or method should be coded.
    3. Less code, less error principle to be followed.
3. Reliable Design
    1. Reliability should be a priority. Everything should work as designed and coded.
    2. Data members, methods and objects should be made constant wherever possible.
    3. Parameters should be appropriately defaulted wherever possible
4. Testable Design
    1. Every class should support the output streaming operator for checking intermittent output if needed.
    2. Every class should be unit tested.
    3. Test Applications should be designed for testing the application on different scenarios of use.
##  Coding Guidelines ##
The following guidelines were adhered to while coding:
1. Use CamelCase for naming variables, classes, types and functions
1. Every name should be indicative of its semantics
1. Start every variable with a lower case letter
1. Start every function and class with an upper case letter
1. Use a trailing underscore `_` for every  data member
1. Use a leading ’s’ for every static data member
1. Do not use any global variable or function (except main(), and friends)
1. No constant value should be written within the code - should be put in the application as static
1. Prefer to pass parameters by value for build-in type and by const reference for UDT
1. Every polymorphic hierarchy must provide a virtual destructor in the base class
1. Prefer C++ style casting (like static cast<int>(x) over C Style casting (like (int))
1. The project should compile without any compiler warning
1. Indent code properly

# Low Level Design (LLD)

## Booking ##
1. Static Members
    1. sBaseFarePerKM : `static double` , used in fare calculation, initialised in `Application.cpp`
    1. sACSurcharge : `static double`,  used in fare calculation, initialised in `Application.cpp`
    1. sLuxuryTaxPercent : `static double` ,  used in fare calculation, initialised in `Application.cpp`
    1. sBookingPNRSerial : `static int` shared by all bookings to generate PNR
    1. sBookings : `static vector<Booking *>` vector storing all bookings made
2. Non Static Members
    1. Pnr_ :  `int` , Pnr of the booking
    1. BookingMessage_ :  `string`, booking message
    1. Fare_ : `int`, fare
    1. BookingStatus_ :  `boolean`, status
    1. FromStation_: `Station`, source station
    1. ToStation_ :`Station`, destination
    1. Date_ :  `Date`, date of travel
    1. BookingClass_ :  `const BookingClass&`, type of booking
    1. Passenger_:  `const Person*`
2. Methods
    1. Booking(): Constructor
    1. ~Booking(): Destructor
    1. ComputeFare() : computes fare and stores it in Fare_ <br>
        Return - void  <br>
        Params - None <br>
        Access - public 
    1. UnitTestBooking(): `static`, implements unit test  <br>
        Return - void <br>
        Params - None <br>
        Access - public
    1. operator<< : `friend` function, implements output stream  <br>
        Return - ostream & <br>
        Params - ostream &, const Booking &

## Station ##
1. Non Static Members:
    1. Name_: `std::string`, name of the station
2. Methods: 
    1. `Station(const std::string &)` : Constructor 
    1. `Station(const Station &)` : Copy constructor
    1. `~Station()` : Destructor
    1. `std::string GetName() const` : returns Name_
    1. `friend std::ostream &operator<<(std::ostream &, const Station &)` : implements output stream
    1. `double GetDistance(const std::string &) const ` : returns distance between 2 stations
    1. `double GetDistance(const Station &) const` : returns distance between 2 stations
    1. `static void UnitTestStation()` : implements unit test

## Date ##
1. Static Members:
    1. Private:
        1. `static const std::vector<std::string> sDays` : vector of strings with day names
        1. `static const std::vector<std::string> sMonths` : vector of strings with month names
2. Non Static Members:
    1. Private:
        1. `unsigned int date_` : DD part of the date object
        1. `unsigned int month_` : MM part of the date object
        1. `unsigned int year_` :YYYY part of the date object
3. Methods: 
    1. Public:
        1. `Date(unsigned int, unsigned int, unsigned int)`: Constructor
        1. `Date(const Date &)` : Copy Constructor
        1. `~Date()` : Destructor
        1. `friend std::ostream &operator<<(std::ostream &, const Date &)` : implements output streaming
        1. `static void UnitTestDate()`: implements unit test

## Railways (singleton) ##
1. Static Members:
    1. Private:
        1. `static const std::vector<Station> sStations` : List of Stations
        1. `static const std::map<std::pair<std::string, std::string>, double> sDistStations` : Stores distance between two stations
2. Methods:
    1. Private:
        1. `static std::vector<Station> InitSta()` : initialise stations
        1. `static std::map<std::pair<std::string, std::string>, double> InitDis()` : initialises distances between stations
        1. `Railways()` : private constructor for singleton
        1. `~Railways()`: private destructor for singleton
    2. Public: 
        1. `Railways(Railways &) = delete` : c++11 code
        1. `void operator=(const Railways &) = delete` : c++11 code 
        1. `static const Railways &IndianRailways()` : singleton implementation
        1. `double GetDistance(const Station &, const Station &) const` : returns distance between two stations
        1. `double GetDistance(const std::string &, const std::string &) const` :   returns distance between two stations
        1. `friend std::ostream &operator<<(std::ostream &, const Railways &)` : implements output streaming
        1. `static void UnitTestRailways()` : implements unit tests
