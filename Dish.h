//Dish.h

#ifndef _DISH_H
#define _DISH_H

class Dish
{
public:
	Dish();
	Dish(char* foodName, int price);
	Dish(const Dish& source);
	~Dish();

	char* GetFoodName() const;
	int GetPrice() const;

	void SetPrice(int price);

private:
	char foodName[13];
	int price;
};

inline char* Dish::GetFoodName() const
{
	return const_cast<char*>(this->foodName);
}
inline int Dish::GetPrice() const
{
	return this->price;
}
inline void Dish::SetPrice(int price)
{
	this->price = price;
}

#endif