//PayCharge.cpp

#include "PayCharge.h"

//////////////////////////////////////////////////////////////////////////
PayCharge::PayCharge():Payment()
{
}
//////////////////////////////////////////////////////////////////////////
PayCharge::PayCharge(Date& date, int totalPrice, int pflag)
:Payment(date, totalPrice, pflag)
{
}
//////////////////////////////////////////////////////////////////////////
PayCharge::PayCharge(const PayCharge& source)
{
}
//////////////////////////////////////////////////////////////////////////
PayCharge::~PayCharge()
{
}