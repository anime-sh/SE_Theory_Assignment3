// Name: Animesh Jha
// Roll Number: 19CS10070
#include "BookingClass.h"
#include "Booking.h"
#include <iostream>
bool BookingClass::IsSitting() const
{
    return !Berth_;
}
int BookingClass::GetNumberOfTiers() const
{
    return NumTiers_;
}
std::ostream &operator<<(std::ostream &os, const BookingClass &lo)
{
    os << lo.GetName() << "\n";
    os << "AC: " << (lo.IsAC() ? "Yes" : "No") << "\n";
    os << "Sitting: " << (lo.IsSitting() ? "Yes" : "No") << "\n";
    os << "Luxury: " << (lo.IsLuxury() ? "Yes" : "No") << "\n";
    os << "Tiers: " << lo.GetNumberOfTiers() << "\n";
    os << "Load Factor: " << lo.GetLoadFactor() << "\n";
    return os;
}

//Unit Tests for non concrete classes///
void BookingClass::UnitTestBookingClass()
{
    std::cout << "Unit Testing BookingClass" << std::endl;
    ACFirstClass a1;
    BookingClass &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

void SittingClass::UnitTestSittingClass()
{
    std::cout << "Unit Testing SittingClass" << std::endl;
    SecondSitting a1;
    SittingClass &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

void SleepingClass::UnitTestSleepingClass()
{
    std::cout << "Unit Testing SleepingClass" << std::endl;
    FirstClass a1;
    SleepingClass &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

void Sitting0Tier::UnitTestSitting0Tier()
{
    std::cout << "Unit Testing Sitting0Tier" << std::endl;
    SecondSitting a1;
    Sitting0Tier &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

void Sleeping2Tier::UnitTestSleeping2Tier()
{
    std::cout << "Unit Testing Sleeping2Tier" << std::endl;
    FirstClass a1;
    Sleeping2Tier &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

void Sleeping3Tier::UnitTestSleeping3Tier()
{
    std::cout << "Unit Testing Sleeping3Tier" << std::endl;
    Sleeper a1;
    Sleeping3Tier &ut1 = a1;
    std::cout << "Sitting: " << (ut1.IsSitting() ? "Yes" : "No") << "\n";
    std::cout << "Tiers: " << ut1.GetNumberOfTiers() << "\n";
}

//Unit Tests for non concrete classes ends///

//Unit Tests for concrete classes Starts///
void SecondSitting::UnitTestSecondSitting()
{

    const SecondSitting &lo = SecondSitting::Type();
    const SecondSitting &lo_ = SecondSitting::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}

void ACChairCar::UnitTestACChairCar()
{
    
    const ACChairCar &lo = ACChairCar::Type();
    const ACChairCar &lo_ = ACChairCar::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}
void ACFirstClass::UnitTestACFirstClass()
{
    const ACFirstClass &lo = ACFirstClass::Type();
    const ACFirstClass &lo_ = ACFirstClass::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}

void AC2Tier::UnitTestAC2Tier()
{
    const AC2Tier &lo = AC2Tier::Type();
    const AC2Tier &lo_ = AC2Tier::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}

void FirstClass::UnitTestFirstClass()
{
    const FirstClass &lo = FirstClass::Type();
    const FirstClass &lo_ = FirstClass::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}

void AC3Tier::UnitTestAC3Tier()
{
    const AC3Tier &lo = AC3Tier::Type();
    const AC3Tier &lo_ = AC3Tier::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}

void Sleeper::UnitTestSleeper()
{
    const Sleeper &lo = Sleeper::Type();
    const Sleeper &lo_ = Sleeper::Type();

    // check for singleton
    std::cout<<(((&lo != &lo_)?"Not Singleton":"Singleton"))<<std::endl;

    //check output operator
    std::cout << lo << std::endl;
}
//Unit Tests for concrete classes ends///

//implementing methods for concrete classes starts///
std::string Sleeper::GetName() const
{
    return "Sleeper";
}
bool Sleeper::IsAC() const
{
    return false;
}
bool Sleeper::IsLuxury() const
{
    return false;
}
double Sleeper::GetLoadFactor() const
{
    return 1.0;
}

std::string AC3Tier::GetName() const
{
    return "AC3Tier";
}
bool AC3Tier::IsAC() const
{
    return true;
}
bool AC3Tier::IsLuxury() const
{
    return false;
}
double AC3Tier::GetLoadFactor() const
{
    return 1.75;
}

std::string FirstClass::GetName() const
{
    return "FirstClass";
}
bool FirstClass::IsAC() const
{
    return false;
}
bool FirstClass::IsLuxury() const
{
    return true;
}
double FirstClass::GetLoadFactor() const
{
    return 2;
}

std::string AC2Tier::GetName() const
{
    return "AC2Tier";
}
bool AC2Tier::IsAC() const
{
    return true;
}
bool AC2Tier::IsLuxury() const
{
    return false;
}
double AC2Tier::GetLoadFactor() const
{
    return 2;
}

std::string ACFirstClass::GetName() const
{
    return "ACFirstClass";
}
bool ACFirstClass::IsAC() const
{
    return true;
}
bool ACFirstClass::IsLuxury() const
{
    return true;
}
double ACFirstClass::GetLoadFactor() const
{
    return 3;
}

std::string ACChairCar::GetName() const
{
    return "ACChairCar";
}
bool ACChairCar::IsAC() const
{
    return true;
}
bool ACChairCar::IsLuxury() const
{
    return false;
}
double ACChairCar::GetLoadFactor() const
{
    return 1.25;
}

std::string SecondSitting::GetName() const
{
    return "SecondSitting";
}
bool SecondSitting::IsAC() const
{
    return false;
}
bool SecondSitting::IsLuxury() const
{
    return false;
}
double SecondSitting::GetLoadFactor() const
{
    return 0.50;
}

//implementing methods for concrete classes ends///
