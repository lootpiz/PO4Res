//Detail.h

#ifndef _DETAIL_H
#define _DETAIL_H

#include "Dish.h"

class Detail
{
public:
	Detail();
	Detail(int count);
	Detail(const Detail& source);
	~Detail();

	int GetCount() const;
	void SetCount(int count);
	Dish* GetDish() const;

	void SetDish(Dish* dish);

private:
	int count;
	Dish* dish;
};
inline void Detail::SetDish(Dish* dish)
{
	this->dish = dish;
}
inline int Detail::GetCount() const
{
	return this->count;
}
inline void Detail::SetCount(int count)
{
	this->count = count;
}
inline Dish* Detail::GetDish() const
{
	return const_cast<Dish*>(this->dish);
}
#endif