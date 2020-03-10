//BillManagement.h

#ifndef _BILLMANAGEMENT_H
#define _BILLMANAGEMENT_H

#include "TArray.h"
#include "Date.h"
#include "Payment.h"

class BillManagement
{
public:
	BillManagement();
	BillManagement(int capacity, int count);
	BillManagement(const BillManagement& source);
	~BillManagement();

	Array<Payment>& GetBills() const;
	int GetCount() const;
	void SetCount(int count);

	int Calculate(Date& beginDate, Date& endDate, int* cashTotal, int* chargeTotal, int* Total);
	
private:
	Array<Payment> bills;
	int count;
};

inline Array<Payment>& BillManagement::GetBills() const
{
	return const_cast< Array<Payment>& >(this->bills);
}
inline int BillManagement::GetCount() const
{
	return this->count;
}

inline void BillManagement::SetCount(int count)
{
	this->count = count;
}


#endif