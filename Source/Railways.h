// Name: Animesh Jha
// Roll Number: 19CS10070

// Start of "Railways.h"
#ifndef _RAILWAYS_H
#define _RAILWAYS_H
// Header file codes
#include <vector>
#include <string>
#include <map>
#include "Station.h"
class Railways //singleton class using c++11 code
{

    static const std::vector<Station> sStations;
    static const std::map<std::pair<std::string, std::string>, double> sDistStations;
    static std::vector<Station> InitSta();
    static std::map<std::pair<std::string, std::string>, double> InitDis();
    Railways();
    ~Railways();

public:
    Railways(Railways &) = delete;
    void operator=(const Railways &) = delete;
    static const Railways &IndianRailways();
    double GetDistance(const Station &, const Station &) const;
    double GetDistance(const std::string &, const std::string &) const;
    friend std::ostream &operator<<(std::ostream &, const Railways &);
    static void UnitTestRailways();
};


#endif

//_RAILWAYS_H
// End of "Railways.h"
