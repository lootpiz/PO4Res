//Payment.h

#include "Payment.h"

//////////////////////////////////////////////////////////////////////////
Payment::Payment()
{
}
//////////////////////////////////////////////////////////////////////////
Payment::Payment(Date& date, int totalPrice, int pflag)
{
	this->date = date;
	this->totalPrice = totalPrice;
	this->flag = pflag;
}
//////////////////////////////////////////////////////////////////////////
Payment::Payment(const Payment& source)
{
	this->date = source.date;
	this->totalPrice = source.totalPrice;
}
//////////////////////////////////////////////////////////////////////////
Payment::~Payment()
{
}