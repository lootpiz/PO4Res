//MenuInformation.cpp

#include "MenuInformation.h"
#include "Dish.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////////
MenuInformation::MenuInformation()
: menu()
{
	this->count = 0;

	Dish dish1("�� ��(600g)", 10000);
	this->menu.AppendRear(dish1);
	this->count++;

	Dish dish2("�ѿ���(600g)", 8000);
	this->menu.AppendRear(dish2);
	this->count++;

	Dish dish3("���ø�", 2500);
	this->menu.AppendRear(dish3);
	this->count++;
	
	Dish dish4("����ø�", 2800);
	this->menu.AppendRear(dish4);
	this->count++;	

	Dish dish5("�����", 100);
	this->menu.AppendRear(dish5);
	this->count++;	
}
//////////////////////////////////////////////////////////////////////////
MenuInformation::MenuInformation(int capacity, int count)
: menu(capacity)
{
	this->count = count;
}
//////////////////////////////////////////////////////////////////////////
MenuInformation::MenuInformation(MenuInformation& source)
{
}
//////////////////////////////////////////////////////////////////////////
MenuInformation::~MenuInformation()
{
}
//////////////////////////////////////////////////////////////////////////
int MenuInformation::Search(char* foodname)
{
	int flag = 0;
	int index = 0;
	int returnPrice;

	while (flag != 1 && index < this->count)
	{
		if ( strcmp(this->menu[index].GetFoodName(), foodname) == 0 )
		{
			flag = 1;
		}
		index++;
	}
	returnPrice = this->menu[index-1].GetPrice();
	
	return returnPrice;
}