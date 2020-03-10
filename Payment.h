//Payment.h

#ifndef _PAYMENT_H
#define _PAYMENT_H

#include "Date.h"

class Payment
{
public:
	Payment();
	Payment(Date& date, int totalPrice, int pflag);
	Payment(const Payment& source);
	~Payment();

	Date& GetDate() const;
	int GetTotalPrice() const;
	int GetFlag() const;
	void SetFlag(int pflag);

private:
	Date date;
	int totalPrice;
	int flag;
};

inline Date& Payment::GetDate() const
{
	return const_cast<Date&>(this->date);
}
inline int Payment::GetTotalPrice() const
{
	return this->totalPrice;
}

inline int Payment::GetFlag() const
{
	return this->flag;
}

inline void Payment::SetFlag(int pflag)
{
	this->flag = pflag;
}

#endif