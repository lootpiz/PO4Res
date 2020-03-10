//Table.h

#ifndef _TABLE_H
#define _TABLE_H

class Table
{
public:
	Table();
	Table(int tableNumber, int maxPeople, int currentPeople);
	Table(const Table& source);
	~Table();

	int GetTableNumber() const;
	int GetTableMaxPeople() const;
	int GetTableCurentPeople() const;

	void SetTableMaxPeople(int people);
	void SetTableCurrentPeople(int people);
	
private:
	int tableNumber;
	int maxPeople;
	int currentPeople;
};

inline int Table::GetTableNumber() const
{
	return this->tableNumber;
}
inline int Table::GetTableMaxPeople() const
{
	return this->maxPeople;
}
inline int Table::GetTableCurentPeople() const
{
	return this->currentPeople;
}

inline void Table::SetTableMaxPeople(int people)
{
	this->maxPeople = people;
}

inline void Table::SetTableCurrentPeople(int people)
{
	this->currentPeople = people;
}

#endif