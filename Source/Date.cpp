// Name: Animesh Jha
// Roll Number: 19CS10070
#include "Date.h"
#include <iostream>
const std::vector<std::string> Date::sMonths = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const std::vector<std::string> Date::sDays = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

Date::Date(unsigned int date, unsigned int month, unsigned int year) : date_(date), month_(month), year_(year) {}
Date::Date(const Date &cp) : date_(cp.date_), month_(cp.month_), year_(cp.year_) {}
Date::~Date() {}
std::ostream &operator<<(std::ostream &os, const Date &d)
{
    os << d.date_ << "/" << Date::sMonths[d.month_] << "/" << d.year_;
    return os;
}
void Date::UnitTestDate()
{
    //checking constructors
    Date d1(30, 8, 2001);
    Date d2(d1);

    //checking output stream
    std::cout << d1 << " " << d2 << std::endl;
}