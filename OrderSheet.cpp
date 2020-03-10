//OrderSheet.cpp

#include "OrderSheet.h"

//////////////////////////////////////////////////////////////////////////
OrderSheet::OrderSheet(Table* table, Order* order)
: details(1)
{
	this->amount = 0;
	this->table = table;
	this->payment = NULL;
	this->detail = NULL;
	this->order = order;
}

//////////////////////////////////////////////////////////////////////////
OrderSheet::OrderSheet()
: details()
{
	this->amount = 0;
	this->table = NULL;
	this->payment = NULL;
	this->detail = NULL;
	this->order = NULL;
}
//////////////////////////////////////////////////////////////////////////
OrderSheet::OrderSheet(int amount, Table* tablenumber, Payment* payment, Detail* detail, Order* order, int capacity)
: details(capacity)
{
	this->amount = amount;
	this->table  = tablenumber;
	this->payment = payment;
	this->detail = detail;
	this->order = order;
}
//////////////////////////////////////////////////////////////////////////
OrderSheet::OrderSheet(const OrderSheet& source)
{
	
}
//////////////////////////////////////////////////////////////////////////
OrderSheet::~OrderSheet()
{
}

