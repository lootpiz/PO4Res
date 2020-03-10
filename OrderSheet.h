//OrderSheet.h

#ifndef _ORDERSHEET_H
#define _ORDERSHEET_H

#include "TArray.h"
#include "Table.h"
#include "Payment.h"
#include "Detail.h"
#include "Order.h"

class OrderSheet
{
public:
	OrderSheet();
	OrderSheet(Table* table, Order* order);
	OrderSheet(int amount, Table* tablenumber, Payment* payment, Detail* detail, Order* order, int capacity);
	OrderSheet(const OrderSheet& source);
	~OrderSheet();

	/*
	void Record(Table* tablenumber);
	void Record(Date& date);
	void Record(char* foodName, int quantity);
	void Append(char* foodName, int quantity);
	*/
	//int Calculate(Detail* detail);

	int GetAmount() const;
	Table* GetTable() const;
	Payment* GetPayment() const;
	Detail* GetDetail() const;
	Order* GetOrder() const;

	Array<Detail>& GetDetails() const;

	void SetTable(Table* table);
	void SetOrder(Order* order);

	void SetAmount(int amount);

	
private:
	int amount;
	Table* table;
	Payment* payment;
	Detail* detail;
	Order* order;
	Array<Detail> details;
};
inline Array<Detail>& OrderSheet::GetDetails() const
{
	return const_cast< Array<Detail>& >(this->details);
}
inline void OrderSheet::SetOrder(Order* order)
{
	this->order = order;
}
inline void OrderSheet::SetTable(Table* table)
{
	this->table = table;
}
inline int OrderSheet::GetAmount() const
{
	return this->amount;
}
inline Table* OrderSheet::GetTable() const
{
	return const_cast<Table*>(this->table);
}
inline Payment* OrderSheet::GetPayment() const
{
	return const_cast<Payment*>(this->payment);
}
inline Detail* OrderSheet::GetDetail() const
{
	return const_cast<Detail*>(this->detail);
}
inline Order* OrderSheet::GetOrder() const
{
	return const_cast<Order*>(this->order);
}
inline void OrderSheet::SetAmount(int amount)
{
}

#endif
