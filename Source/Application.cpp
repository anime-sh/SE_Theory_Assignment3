// Name: Animesh Jha
// Roll Number: 19CS10070
#include <iostream>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClass.h"
#include "Booking.h"


// Have initialised static data here using the values given in the pdf
int Booking::sBookingPNRSerial = 1;
double Booking::sBaseFarePerKM = 0.50;
double Booking::sACSurcharge = 50.00;
double Booking::sLuxuryTaxPercent = 25;
std::vector<Booking *> Booking::sBookings;

const std::vector<Station> Railways::sStations = Railways::InitSta();
const std::map<std::pair<std::string, std::string>, double> Railways::sDistStations = Railways::InitDis();
std::vector<Station> Railways::InitSta()
{
    std::vector<Station> Ret = {{"Mumbai"}, {"Delhi"}, {"Bangalore"}, {"Kolkata"}, {"Chennai"}};
    return Ret;
}
std::map<std::pair<std::string, std::string>, double> Railways::InitDis()
{
    std::map<std::pair<std::string, std::string>, double> Ret;
    Ret[{"Mumbai", "Delhi"}] = Ret[{"Delhi", "Mumbai"}] = 1447;
    Ret[{"Mumbai", "Bangalore"}] = Ret[{"Bangalore", "Mumbai"}] = 981;
    Ret[{"Mumbai", "Kolkata"}] = Ret[{"Kolkata", "Mumbai"}] = 2014;
    Ret[{"Mumbai", "Chennai"}] = Ret[{"Chennai", "Mumbai"}] = 1338;
    Ret[{"Bangalore", "Delhi"}] = Ret[{"Delhi", "Bangalore"}] = 2150;
    Ret[{"Bangalore", "Kolkata"}] = Ret[{"Kolkata", "Bangalore"}] = 1871;
    Ret[{"Bangalore", "Chennai"}] = Ret[{"Chennai", "Bangalore"}] = 350;
    Ret[{"Kolkata", "Delhi"}] = Ret[{"Delhi", "Kolkata"}] = 1472;
    Ret[{"Kolkata", "Chennai"}] = Ret[{"Chennai", "Kolkata"}] = 1659;
    Ret[{"Chennai", "Delhi"}] = Ret[{"Delhi", "Chennai"}] = 2180;
    return Ret;
}
const Railways &Railways::IndianRailways()
{
    static const Railways Instance; //since this is static it would be constructed only once
    return Instance;
}