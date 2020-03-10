//OrderSheetBinder.h

#ifndef _ORDERSHEETBINDER_H
#define _ORDERSHEETBINDER_H

#include "TArray.h"
#include "OrderSheet.h"

class OrderSheetBinder
{
public:
	OrderSheetBinder();
	OrderSheetBinder(int capacity, int count);
	OrderSheetBinder(const OrderSheetBinder& source);
	~OrderSheetBinder();

	void Append(OrderSheet& source);

	int GetCount() const;
	Array<OrderSheet>& GetOrders() const;

	int Search(int numberOfPeople);

private:
	Array<OrderSheet> orders;
	int count;	
};

inline Array<OrderSheet>& OrderSheetBinder::GetOrders() const
{
	return const_cast< Array<OrderSheet>& >(this->orders);
}
inline int OrderSheetBinder::GetCount() const
{
	return this->count;
}

#endif