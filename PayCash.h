//PayCash.h

#ifndef _PAYCASH_H
#define _PAYCASH_H

#include "Payment.h"

class PayCash : public Payment
{
public:
	PayCash();
	PayCash(Date& date, int totalPrice, int pflag);
	PayCash(const PayCash& source);
	~PayCash();
};
#endif