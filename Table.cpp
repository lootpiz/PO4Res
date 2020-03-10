//Table.cpp

#include "Table.h"

//////////////////////////////////////////////////////////////////////////
Table::Table()
{
	this->tableNumber = 0;
	this->maxPeople = 0;
	this->currentPeople = 0;
}
//////////////////////////////////////////////////////////////////////////
Table::Table(int tableNumber, int maxPeople, int currentPeople)
{
	this->tableNumber = tableNumber;
	this->maxPeople = maxPeople;
	this->currentPeople = currentPeople;
}
//////////////////////////////////////////////////////////////////////////
Table::Table(const Table& source)
{
	this->tableNumber = source.tableNumber;
	this->maxPeople = source.maxPeople;
	this->currentPeople = source.currentPeople;
}
//////////////////////////////////////////////////////////////////////////
Table::~Table()
{
}