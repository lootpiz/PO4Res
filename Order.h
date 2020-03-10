//Order.h

#ifndef _ORDER_H
#define _ORDER_H

#include "Date.h"

class Order
{
public:
	Order();
	Order(Date& date, char* serialNumber);
	Order(const Order& source);
	~Order();

	Date& GetDate() const;
	char* GetSerialNumber() const;



private:
	Date date;
	char serialNumber[12];
};

inline Date& Order::GetDate() const
{
	return const_cast<Date&>(this->date);
}
inline char* Order::GetSerialNumber() const
{
	return const_cast<char*>(this->serialNumber);
}

#endif