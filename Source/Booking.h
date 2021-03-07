// Name: Animesh Jha
// Roll Number: 19CS10070

// Start of "Booking.h"
#ifndef _BOOKING_H
#define _BOOKING_H
#include "Station.h"
#include "Railways.h"
#include "BookingClass.h"
#include "Date.h"
#include <vector>
#include <string>
#include <ostream>
#include <cmath>
class Person;
class Booking
{
    static double sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;
    static int sBookingPNRSerial;

    int Pnr_;
    std::string BookingMessage_;
    int Fare_;
    bool BookingStatus_;

    Station FromStation_;
    Station ToStation_;
    Date Date_;
    const BookingClass &BookingClass_;
    const Person *Passenger_;

public:
    static std::vector<Booking *> sBookings;
    Booking(const Station &, const Station &, const Date &, const BookingClass &, const Person * = NULL);
    ~Booking();
    void ComputeFare();
    friend std::ostream &operator<<(std::ostream &, const Booking &);
    static void UnitTestBooking();
};

//send to Application.cpp

#endif
