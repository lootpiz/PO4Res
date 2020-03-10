//MenuInformation.h

#ifndef _MENUINFORMATION_H
#define _MENUINFORMATION_H

#include "TArray.h"
#include "Dish.h"

class MenuInformation
{
public:
	MenuInformation();
	MenuInformation(int capacity, int count);
	MenuInformation(MenuInformation& source);
	~MenuInformation();

	Array<Dish>& GetMenu() const;
	int GetCount() const;
	void SetCount(int count);
	
	int Search(char* foodname);	
	
private:
	Array <Dish> menu;
	int count;
};

inline Array<Dish>& MenuInformation::GetMenu() const
{
	return const_cast<Array<Dish>&>(this->menu);
}
inline int MenuInformation::GetCount() const
{
	return this->count;
}
inline void MenuInformation::SetCount(int count)
{
	this->count = count;
}


#endif
