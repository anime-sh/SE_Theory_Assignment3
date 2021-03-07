// Name: Animesh Jha
// Roll Number: 19CS10070

// Start of "Date.h"
#ifndef _DATE_H
#define _DATE_H

#include <vector>
#include <string>
#include <ostream>
class Date
{

    static const std::vector<std::string> sMonths;
    static const std::vector<std::string> sDays;
    unsigned int date_, month_, year_;

public:
    Date(unsigned int, unsigned int, unsigned int);
    Date(const Date &);
    ~Date();
    friend std::ostream &operator<<(std::ostream &, const Date &);
    static void UnitTestDate();
};
#endif