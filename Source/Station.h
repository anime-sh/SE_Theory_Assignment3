// Name: Animesh Jha
// Roll Number: 19CS10070

// Start of "Station.h"
#ifndef _STATION_H
#define _STATION_H
// Header file codes
#include <ostream>
#include <string>
class Station
{
    std::string Name_;

public:
    Station(const std::string &);
    Station(const Station &);
    ~Station();
    std::string GetName() const;
    friend std::ostream &operator<<(std::ostream &, const Station &);
    double GetDistance(const std::string &) const; 
    double GetDistance(const Station &) const;     
    static void UnitTestStation();
};

#endif

//_STATION_H
// End of "Station.h"