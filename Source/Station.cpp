// Name: Animesh Jha
// Roll Number: 19CS10070
#include "Station.h"
#include "Railways.h"
#include <iostream>
Station::Station(const std::string &Name) : Name_(Name) {}
Station::Station(const Station &cp) : Name_(cp.Name_) {}
Station::~Station() {}
std::string Station::GetName() const
{
    return this->Name_;
}
std::ostream &operator<<(std::ostream &os, const Station &lo)
{
    os << "Station Name: " << lo.Name_ << "\n";
    return os;
}
double Station::GetDistance(const Station &Dest) const
{
    return Railways::IndianRailways().GetDistance(this->GetName(), Dest.GetName());
}
double Station::GetDistance(const std::string &Dest) const
{
    return Railways::IndianRailways().GetDistance(this->GetName(), Dest);
}
// To unit test class Station
void Station::UnitTestStation()
{
    // Check Constructors
    Station s1("Mumbai");
    Station s2(s1);

    //check output stream operator
    std::cout << s1;
    std::cout << s2;

    //check GetName
    std::cout << s1.GetName() << " " << s2.GetName() << std::endl;

    //Check GetDistance
    std::cout << "Distance between Mumbai and Delhi " << s1.GetDistance("Delhi") << std::endl;
    std::cout << "Distance between Mumbai and Chennai " << s2.GetDistance("Chennai") << std::endl;
}