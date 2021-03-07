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
    1. Private:
        1.  `static double sBaseFarePerKM` , used in fare calculation, initialised in `Application.cpp`
        1.  `static double sACSurcharge`,  used in fare calculation, initialised in `Application.cpp`
        1.  `static double sLuxuryTaxPercent` ,  used in fare calculation, initialised in `Application.cpp`
        1.  `static int sBookingPNRSerial` shared by all bookings to generate PNR
    1. Public:
        1.   `static vector<Booking *> sBookings` vector storing all bookings made
2. Non Static Members
    1. Private:
        1. `int Pnr_` , Pnr of the booking
        1.    `string BookingMessage_`, booking message
        1.  `int Fare_ `, fare
        1.  `boolean BookingStatus_`, status
        1.  `Station FromStation_`, source station
        1. `Station ToStation_ `, destination
        1.  `Date Date_ `, date of travel
        1.   `const BookingClass& BookingClass_ `, type of booking
        1.  `const Person* Passenger_`
2. Methods
    1. Public:
        1.  `Booking(const Station &, const Station &, const Date &, const BookingClass &, const Person * = NULL)` Constructor
        1. `~Booking()` Destructor
        1. `void ComputeFare()` computes fare and stores it in Fare_  
        1. `friend std::ostream &operator<<(std::ostream &, const Booking &)`implements output stream 
        1. `static void UnitTestBooking()`   implements unit test  
        

## Station ##
1. Non Static Members:
    1. Private:
        1. `std::string Name_` : name of the station
2. Methods: 
    1. Public:
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
        1. `Railways()` : constructor for singleton
        1. `~Railways()`: destructor for singleton
    2. Public: 
        1. `Railways(Railways &) = delete` : c++11 code
        1. `void operator=(const Railways &) = delete` : c++11 code 
        1. `static const Railways &IndianRailways()` : singleton implementation
        1. `double GetDistance(const Station &, const Station &) const` : returns distance between two stations
        1. `double GetDistance(const std::string &, const std::string &) const` :   returns distance between two stations
        1. `friend std::ostream &operator<<(std::ostream &, const Railways &)` : implements output streaming
        1. `static void UnitTestRailways()` : implements unit tests


## Booking Class ##

### Designing the Hierachy ###   
1. Berth, AC, and NumberOfTiers will not change with time
2. LoadFactors and Luxury may change from time to time
3. Therefore, Berth and its closest associate NumberOfTiers are the best candidates for the hierarchy design

### Members and Methods ###
1. Berth and NumberOfTiers are data members of the abstract base class `BookingClass`
2. Other attributes (AC, LoadFactor, Luxury, Name) are implemented via methods, these methods are pure virtual in the abstract base class, and are implemented by the concrete classes
3. The output operator is implemented for the abstact base class
4. static functions for unit testing are provided for each class

### Hierachy ###
1. BookingClass
    1. SittingClass
        1. Sitting0Tier
            1. ACChairCar
            1. SecondSitting
    1. SleepingClass
        1. Sleeping2Tier
            1. ACFirstClass
            1. AC2Tier
            1. FirstClass
        1. Sleeping3Tier
            1. AC3Tier
            1. Sleeper

### BookingClass ###
1. Members
    1. Private
        1. `const bool Berth_`  : Berth/Sitting
        1. `const int NumTiers_`: NumberOfTiers
1. Methods
    1. Public:
        1. `BookingClass(const bool &Berth, const int &NumTiers)` : Constructor
        1. `virtual ~BookingClass()` : Virtual Destructor
        1. `virtual std::string GetName() const = 0`: Pure virtual function to return Name
        1. `virtual bool IsAC() const = 0`: Pure virtual function to return AC/NonAC
        1. `virtual bool IsLuxury() const = 0`: Pure virtual function to return Luxury/NonLuxury
        1. `virtual double GetLoadFactor() const = 0`: : Pure virtual function to return LoadFactor
        1. `bool IsSitting() const`: Concrete function returns `!Berth_`
        1. `int GetNumberOfTiers() const`: Concrete function returns `NumTier_`
        1. `friend std::ostream &operator<<(std::ostream &os, const BookingClass &lo)`: Implements output stream for all classes in this hierachy
        1. `static void UnitTestBookingClass()`: Unit Tests this class

### SittingClass (Publicly inherits BookingClass) ###
1. Methods
    1. Public:
        1. `SittingClass(const int &NumTiers)` : Constructor
        2. `~SittingClass()` : Destructor
        1. `static void UnitTestSittingClass()`: Unit Tests this class

### SleepingClass (Publicly inherits BookingClass) ###
1. Methods
    1. Public:
        1. `SleepingClass(const int &NumTiers)` : Constructor
        2. `~SleepingClass()` : Destructor
        1. `static void UnitTestSleepingClass()`: Unit Tests this class

### Sitting0Tier (Publicly inherits SittingClass) ###
1. Methods
    1. Public:
        1. `Sitting0Tier()` : Constructor
        2. `~Sitting0Tier()` : Destructor
        1. `static void UnitTestSitting0Tier()`: Unit Tests this class

### Sleeping2Tier (Publicly inherits SleepingClass) ###
1. Methods
    1. Public:
        1. `Sleeping2Tier()` : Constructor
        2. `~Sleeping2Tier()` : Destructor
        1. `static void UnitTestSleeping2Tier()`: Unit Tests this class

### Sleeping3Tier (Publicly inherits SleepingClass) ###
1. Methods
    1. Public:
        1. `Sleeping3Tier()` : Constructor
        2. `~Sleeping3Tier()` : Destructor
        1. `static void UnitTestSleeping3Tier()`: Unit Tests this class

### ACChairCar (Publicly inherits Sitting0Tier) ###
1. Methods
    1. Public
        1. `ACChairCar() : Sitting0Tier() {}` : Constructor
        1. `~ACChairCar() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const ACChairCar &Type()`:implements singleton
        1. `static void UnitTestACChairCar()` Unit Tests this class
### SecondSitting (Publicly inherits Sitting0Tier) ###
1. Methods
    1. Public
        1. `SecondSitting() : Sitting0Tier() {}` : Constructor
        1. `~SecondSitting() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const SecondSitting &Type()`:implements singleton
        1. `static void UnitTestSecondSitting()` Unit Tests this class
### ACFirstClass (Publicly inherits Sleeping2Tier) ###
1. Methods
    1. Public
        1. `ACCFirstClass() : Sleeping2Tier() {}` : Constructor
        1. `~ACCFirstClass() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const ACCFirstClass &Type()`:implements singleton
        1. `static void UnitTestACCFirstClass()` Unit Tests this class
### AC2Tier (Publicly inherits Sleeping2Tier) ###
1. Methods
    1. Public
        1. `AC2Tier() : Sleeping2Tier() {}` : Constructor
        1. `~AC2Tier() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const AC2Tier &Type()`:implements singleton
        1. `static void UnitTestAC2Tier()` Unit Tests this class

### FirstClass (Publicly inherits Sleeping2Tier) ###
1. Methods
    1. Public
        1. `FirstClass() : Sleeping2Tier() {}` : Constructor
        1. `~FirstClass() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const FirstClass &Type()`:implements singleton
        1. `static void UnitTestFirstClass()` Unit Tests this class

### AC3Tier (Publicly inherits Sleeping3Tier) ###
1. Methods
    1. Public
        1. `AC3Tier() : Sleeping3Tier() {}` : Constructor
        1. `~AC3Tier() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const AC3Tier &Type()`:implements singleton
        1. `static void UnitTestAC3Tier()` Unit Tests this class
### Sleeper (Publicly inherits Sleeping3Tier) ###
1. Methods
    1. Public
        1. `Sleeper() : Sleeping3Tier() {}` : Constructor
        1. `~Sleeper() {}` :Destructor
        1. `std::string GetName() const override` : implements GetName
        1. `bool IsAC() const override` :implements AC/NonAC
        1. `bool IsLuxury() const override`implements Luxury/NonLuxury
        1. `double GetLoadFactor() const override` implements LoadFactor
        1. `static const Sleeper &Type()`:implements singleton
        1. `static void UnitTestSleeper()` Unit Tests this class