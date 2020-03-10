//Dish.cpp

#include "Dish.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////////
Dish::Dish()
{
	strcpy(this->foodName, "");
	this->price = 0;
}
//////////////////////////////////////////////////////////////////////////
Dish::Dish(char* foodName, int price)
{
	strcpy(this->foodName, foodName);
	this->price = price;
}
//////////////////////////////////////////////////////////////////////////
Dish::Dish(const Dish& source)
{
	strcpy(this->foodName, source.foodName);
	this->price = source.price;
}
//////////////////////////////////////////////////////////////////////////
Dish::~Dish()
{
}