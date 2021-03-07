// Name: Animesh Jha
// Roll Number: 19CS10070
#include "Booking.h"
#include <iostream>
Booking::~Booking() {} //destructor
Booking::Booking(const Station &fromStation, const Station &toStation, const Date &date, const BookingClass &bookingClass, const Person *person)
    : FromStation_(fromStation), ToStation_(toStation), Date_(date), BookingClass_(bookingClass), Passenger_(person)
{
    Fare_ = 0;
    Pnr_ = sBookingPNRSerial++;  //increse pnr for future bookings
    sBookings.push_back(this);  //add this pointer into the vector
    this->ComputeFare();       // compute the fare
    BookingStatus_ = true;     // manually set this for now
    BookingMessage_ = "BOOKING SUCCEEDED"; // manually set this for now
}
void Booking::ComputeFare()
{
    //normal fare computation math
    double LoFare = (FromStation_.GetDistance(ToStation_)) * sBaseFarePerKM;
    LoFare *= BookingClass_.GetLoadFactor();
    if (BookingClass_.IsAC())
    {
        LoFare += sACSurcharge;
    }
    if (BookingClass_.IsLuxury())
    {
        LoFare += (LoFare * (sLuxuryTaxPercent / 100));
    }
    Fare_ = static_cast<int>(std::round(LoFare));
}
std::ostream &operator<<(std::ostream &os, const Booking &lo)
{
    //output operator closely follows the format in Section C.1 in the pdf
    os << lo.BookingMessage_ << ":\n";
    os << "PNR Number = " << lo.Pnr_ << "\n";
    os << "From Station = " << lo.FromStation_.GetName() << "\n";
    os << "To Station = " << lo.ToStation_.GetName() << "\n";
    os << "Travel Date = " << lo.Date_ << "\n";
    os << "Travel Class = " << lo.BookingClass_.GetName() << "\n";
    os << " 1) Mode: " << (lo.BookingClass_.IsSitting() ? "Sitting\n" : "Sleeping\n");
    os << " 2) Comfort: " << (lo.BookingClass_.IsAC() ? "AC\n" : "Non-AC\n");
    os << " 3) Bunks: " << lo.BookingClass_.GetNumberOfTiers() << "\n";
    os << " 4) Luxury: " << (lo.BookingClass_.IsLuxury() ? "Yes\n" : "No\n");
    os << "Fare = " << lo.Fare_ << "\n\n";
    return os;
}
void Booking::UnitTestBooking()
{
    // unit testing, read testplan.md for more info
    //constructor tested
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    //output streaming tested
    std::cout << b1 << std::endl;
    //other variables printed
    std::cout << "BookingStatus_ = " << b1.BookingStatus_ << "\n";
    std::cout << "sBaseFarePerKM = " << Booking::sBaseFarePerKM << "\n";
    std::cout << "sACSurcharge = " << Booking::sACSurcharge << "\n";
    std::cout << "sLuxuryTaxPercent = " << Booking::sLuxuryTaxPercent << "\n";
    std::cout << "sBookingPNRSerial = " << Booking::sBookingPNRSerial << "\n";
}