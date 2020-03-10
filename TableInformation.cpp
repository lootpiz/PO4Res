//TableInformation.cpp

#include "TableInformation.h"
#include "Table.h"

//////////////////////////////////////////////////////////////////////////
TableInformation::TableInformation() 
: tables()
{
	this->count = 0;

	Table table1(1,5,0);
	this->tables.AppendRear(table1);
	this->count++;

	Table table2(2,4,0);
	this->tables.AppendRear(table2);
	this->count++;

	Table table3(3,5,0);
	this->tables.AppendRear(table3);
	this->count++;

	Table table4(4,4,0);
	this->tables.AppendRear(table4);
	this->count++;

	Table table5(5,10,0);
	this->tables.AppendRear(table5);
	this->count++;
}
//////////////////////////////////////////////////////////////////////////
TableInformation::TableInformation(int capacity, int count) 
: tables(capacity)
{
	this->count = count;
}
//////////////////////////////////////////////////////////////////////////
TableInformation::TableInformation(const TableInformation& source) 
{	
}
//////////////////////////////////////////////////////////////////////////
TableInformation::~TableInformation()
{
}
//////////////////////////////////////////////////////////////////////////
int TableInformation::Search(int numberofpeople)
{
	int flag = 0;
	int index = 0;

	while (flag != 1 && index < this->count)
	{
		if (this->tables[index].GetTableCurentPeople() == 0 && this->tables[index].GetTableMaxPeople() >= numberofpeople)
		{
			flag = 1;
		}
		index++;
	}
	index--;

	if( flag == 0 )
	{
		index = -1;
	}
	return index;
}