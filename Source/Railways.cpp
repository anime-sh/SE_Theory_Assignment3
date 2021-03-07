// Name: Animesh Jha
// Roll Number: 19CS10070
#include "Railways.h"
#include<iostream>
Railways::Railways() {}
Railways::~Railways() {}
std::ostream &operator<<(std::ostream &os, const Railways &IR)
{
    os << "Stations:\n";
    int i = 1;
    for (auto station : IR.sStations)
    {
        os << i << ") " << station.GetName() << "\n";
        i++;
    }
    os << "\n Distances:\n";
    i = 1;
    for (auto entry : IR.sDistStations)
    {
        os << i << ") [ From: " << entry.first.first << ", To: " << entry.first.second << " ] = " << entry.second << "\n";
        i++;
    }
    os << "\n";
    return os;
}

double Railways::GetDistance(const Station &from, const Station &to) const
{
    return sDistStations.find({from.GetName(), to.GetName()})->second;
}
double Railways::GetDistance(const std::string &from, const std::string &to) const
{
    return sDistStations.find({from, to})->second;
}
void Railways::UnitTestRailways()
{
    std::cout<<Railways::IndianRailways()<<std::endl;
}