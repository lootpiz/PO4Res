//PayCharge.h

#ifndef _PAYCHARGE_H
#define _PAYCHARGE_H

#include "Payment.h"

class PayCharge : public Payment
{
public:
	PayCharge();
	PayCharge(Date& date, int totalPrice, int pflag);
	PayCharge(const PayCharge& source);
	~PayCharge();
};
#endif