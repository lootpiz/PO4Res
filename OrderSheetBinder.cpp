//OrderSheetBinder.cpp

#include "OrderSheetBinder.h"

//////////////////////////////////////////////////////////////////////////
OrderSheetBinder::OrderSheetBinder()
: orders()
{
	this->count = 0;
}
//////////////////////////////////////////////////////////////////////////
OrderSheetBinder::OrderSheetBinder(int capacity, int count) 
: orders(capacity)
{
	this->count = count;

}
//////////////////////////////////////////////////////////////////////////
OrderSheetBinder::OrderSheetBinder(const OrderSheetBinder& source)
{
	
}
//////////////////////////////////////////////////////////////////////////
OrderSheetBinder::~OrderSheetBinder()
{
}

void OrderSheetBinder::Append(OrderSheet& source)
{
	this->GetOrders().AppendRear(source);
	this->count++;
}
