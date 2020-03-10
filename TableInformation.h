//TableInformation.h

#ifndef _TABLEINFORMATION_H
#define _TABLEINFORMATION_H

#include "TArray.h"
#include "Table.h"

class TableInformation
{
public:
	TableInformation();
	TableInformation(int capacity, int count);
	TableInformation(const TableInformation& source);
	~TableInformation();

	int GetCount() const;
	void SetCount(int pcount);
	Array<Table>& GetTables() const;

	int Search(int numberOfPeople);

	

private:
	Array<Table> tables;
	int count;	
};

inline Array<Table>& TableInformation::GetTables() const
{
	return const_cast< Array<Table>& >(this->tables);
}
inline int TableInformation::GetCount() const
{
	return this->count;
}

inline void TableInformation::SetCount(int pcount)
{
	this->count = pcount;
}

#endif