//BillManagement.h

#include "BillManagement.h"
#include "PayCash.h"
#include "PayCharge.h"

//////////////////////////////////////////////////////////////////////////
BillManagement::BillManagement()
: bills()
{
	this->count = 0;	
}
//////////////////////////////////////////////////////////////////////////
BillManagement::BillManagement(int capacity, int count)
: bills(capacity)
{
	this->count = count;
}
//////////////////////////////////////////////////////////////////////////
BillManagement::BillManagement(const BillManagement& source)
{
}
//////////////////////////////////////////////////////////////////////////
BillManagement::~BillManagement()
{
}
//////////////////////////////////////////////////////////////////////////
int BillManagement::Calculate(Date& beginDate, Date& endDate, int* cashTotal, int* chargeTotal, int* Total)
{
	int index = 0;

	*cashTotal = 0;
	*chargeTotal = 0;
	*Total = 0;

	while( index < this->count )
	{
		if( ((this->bills)[index]).GetDate() >= beginDate && ((this->bills)[index]).GetDate() <= endDate )
		{

			//if( (reinterpret_cast<PayCash*>( &(this->bills[index])) ) != NULL )
			//if( (dynamic_cast<PayCash*>( &(this->GetBills()[index])) ) != NULL)
			if(this->GetBills()[index].GetFlag() == 1)
			{
				*cashTotal += ((this->bills)[index]).GetTotalPrice();
				*Total += *cashTotal;
			}
			//else if( (reinterpret_cast<PayCharge*>(&(this->bills[index]))) != NULL )
			//else if ( (dynamic_cast<PayCharge*>( &(this->GetBills()[index])) ) != NULL)
			else if(this->GetBills()[index].GetFlag() == 2)
			{
				*chargeTotal += ((this->bills)[index]).GetTotalPrice();
				*Total += *chargeTotal;
			}

			
		}
		index++;
	}
	return count;
}
