// Name: Animesh Jha
// Roll Number: 19CS10070

// Start of "BookingClass.h"
#ifndef _BOOKINGCLASS_H
#define _BOOKINGCLASS_H
// Header file codes
#include <ostream>
#include <string>
class BookingClass
{

    const bool Berth_;
    const int NumTiers_;

public:
    BookingClass(const bool &Berth, const int &NumTiers) : Berth_(Berth), NumTiers_(NumTiers) {}
    virtual ~BookingClass() {}
    virtual std::string GetName() const = 0;
    virtual bool IsAC() const = 0;
    virtual bool IsLuxury() const = 0;
    virtual double GetLoadFactor() const = 0;
    bool IsSitting() const;
    int GetNumberOfTiers() const;
    friend std::ostream &operator<<(std::ostream &os, const BookingClass &lo);
    static void UnitTestBookingClass();
};

class SittingClass : public BookingClass
{
public:
    SittingClass(const int &NumTiers) : BookingClass(false, NumTiers) {}
    ~SittingClass() {}
    static void UnitTestSittingClass();
};

class SleepingClass : public BookingClass
{
public:
    SleepingClass(const int &NumTiers) : BookingClass(true, NumTiers) {}
    ~SleepingClass() {}
    static void UnitTestSleepingClass();
};

class Sitting0Tier : public SittingClass
{
public:
    Sitting0Tier() : SittingClass(0) {}
    ~Sitting0Tier() {}
    static void UnitTestSitting0Tier();
};
class SecondSitting : public Sitting0Tier
{
public:
    SecondSitting() : Sitting0Tier() {}
    ~SecondSitting() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const SecondSitting &Type()
    {
        static const SecondSitting sSecondSitting;
        return sSecondSitting;
    }
    static void UnitTestSecondSitting();
};
class ACChairCar : public Sitting0Tier
{
public:
    ACChairCar() : Sitting0Tier() {}
    ~ACChairCar() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const ACChairCar &Type()
    {
        static const ACChairCar sACChairCar;
        return sACChairCar;
    }
    static void UnitTestACChairCar();
};

class Sleeping2Tier : public SleepingClass
{
public:
    Sleeping2Tier() : SleepingClass(2) {}
    ~Sleeping2Tier() {}
    static void UnitTestSleeping2Tier();
};
class ACFirstClass : public Sleeping2Tier
{
public:
    ACFirstClass() : Sleeping2Tier() {}
    ~ACFirstClass() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const ACFirstClass &Type()
    {
        static const ACFirstClass sACFirstClass;
        return sACFirstClass;
    }
    static void UnitTestACFirstClass();
};
class AC2Tier : public Sleeping2Tier
{
public:
    AC2Tier() : Sleeping2Tier() {}
    ~AC2Tier() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const AC2Tier &Type()
    {
        static const AC2Tier sAC2Tier;
        return sAC2Tier;
    }
    static void UnitTestAC2Tier();
};
class FirstClass : public Sleeping2Tier
{
public:
    FirstClass() : Sleeping2Tier() {}
    ~FirstClass() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const FirstClass &Type()
    {
        static const FirstClass sFirstClass;
        return sFirstClass;
    }
    static void UnitTestFirstClass();
};

class Sleeping3Tier : public SleepingClass
{
public:
    Sleeping3Tier() : SleepingClass(3) {}
    ~Sleeping3Tier() {}
    static void UnitTestSleeping3Tier();
};
class AC3Tier : public Sleeping3Tier
{
public:
    AC3Tier() : Sleeping3Tier() {}
    ~AC3Tier() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const AC3Tier &Type()
    {
        static const AC3Tier sAC3Tier;
        return sAC3Tier;
    }
    static void UnitTestAC3Tier();
};
class Sleeper : public Sleeping3Tier
{
public:
    Sleeper() : Sleeping3Tier() {}
    ~Sleeper() {}
    std::string GetName() const override;
    bool IsAC() const override;
    bool IsLuxury() const override;
    double GetLoadFactor() const override;
    static const Sleeper &Type()
    {
        static const Sleeper sSleeper;
        return sSleeper;
    }
    static void UnitTestSleeper();
};

#endif

//_BOOKINGCLASS_H
// End of "BookingClass.h"