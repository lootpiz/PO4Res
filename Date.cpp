//Date.cpp

#include"Date.h"
#include<time.h>
#include<stdio.h>

/************************************************************************/
/* Date Default Constructor                                             */
/************************************************************************/
Date::Date()
{
	this->year = (ShortInt)1900;
	this->month = (Month)0;
	this->day = (ShortInt)0;
	this->weekday = (Weekday)0;
}
/************************************************************************/
/* Date Constructor                            Type Casting Constructor */
/************************************************************************/
Date::Date(char* date)
{
	struct tm currentDate = {0,};
	
	sscanf(date,"%4d-%2d-%2d",&this->year, &this->month, &this->day);
	currentDate.tm_year = this->year - 1900;
	currentDate.tm_mon = this->month - 1;
	currentDate.tm_mday = this->day;

	mktime(&currentDate);

	this->weekday = (Weekday)currentDate.tm_wday;
}
/************************************************************************/
/* Date Copy Constructor                                                */
/************************************************************************/
Date::Date(Date& source)
{
	this->year = source.year;
	this->month = source.month;
	this->day = source.day;
	this->weekday = source.weekday;
}
/************************************************************************/
/* Destructor                                                           */
/************************************************************************/
Date::~Date()
{

}
/************************************************************************/
/* Static Member Function                                               */
/************************************************************************/
Date Date::GetCurrentDate()
{
	Date returnDate;
	struct tm* currentTime;
	time_t now;

	time(&now);
	currentTime = localtime(&now);

	returnDate.year = (ShortInt)(currentTime->tm_year + 1900);
	returnDate.month = (Month)(currentTime->tm_mon + 1);
	returnDate.day = (ShortInt)currentTime->tm_mday;
	returnDate.weekday = (Weekday)currentTime->tm_wday;

	return returnDate;
}
/************************************************************************/
/* Today                                                                */
/************************************************************************/
void Date::Today()
{
	struct tm* currentTime;
	time_t now;

	time(&now);
	currentTime = localtime(&now);

	this->year = (ShortInt)(currentTime->tm_year + 1900);
	this->month = (Month)(currentTime->tm_mon + 1);
	this->day = (ShortInt)currentTime->tm_mday;
	this->weekday = (Weekday)currentTime->tm_wday;
}
/************************************************************************/
/* Tomorrow                                                             */
/************************************************************************/
void Date::Tomorrow(Date& getDate)
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day + 1;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
}
/************************************************************************/
/* Yesterday                                                            */
/************************************************************************/
void Date::Yesterday(Date& getDate)
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day - 1;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
}
/************************************************************************/
/* Previousday                                                          */
/************************************************************************/
void Date::Previousday(ShortInt days, Date& getDate)
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day - days;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
}
/************************************************************************/
/* Nextday                                                              */
/************************************************************************/
void Date::Nextday(ShortInt days, Date& getDate)
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day + days;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
}
/************************************************************************/
/* IsEuqal                                                              */
/************************************************************************/
bool Date::IsEqual(Date& otherDate)
{
	bool returnValue = false;
	
	if(this->year == otherDate.year)
	{
		if(this->month == otherDate.month - 1)
		{
			if(this->day == otherDate.day)
			{
				returnValue = true;
			}
		}
	}
	return returnValue;
}
/************************************************************************/
/* InNotEqual                                                           */
/************************************************************************/
bool Date::IsNotEqual(Date& otherDate)
{
	bool returnValue = false;
	
	if(this->year != otherDate.year || this->month != (otherDate.month - 1) || this->day != otherDate.day)
	{
		returnValue = true;
	}
	
	return returnValue;
}
/************************************************************************/
/* IsLessThan                                                           */
/************************************************************************/
bool Date::IsLessThan(Date& otherDate)
{
	bool returnValue = false;
	if(this->year < otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->month < otherDate.month)
	{
		returnValue = true;
	}
	else if(this->day < otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}
/************************************************************************/
/* IsGraterThan                                                         */
/************************************************************************/
bool Date::IsGreaterThan(Date& otherDate)
{
	bool returnValue = false;
	if(this->year > otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->month > otherDate.month)
	{
		returnValue = true;
	}
	else if(this->day > otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}
/************************************************************************/
/* IsNotLessThan                                                        */
/************************************************************************/
bool Date::IsNotLessThan(Date& otherDate)
{
	bool returnValue = false;
	if(this->year > otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->month > otherDate.month)
	{
		returnValue = true;
	}
	else if(this->day > otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}
/************************************************************************/
/* IsNotGreaterThan                                                     */
/************************************************************************/
bool Date::IsNotGreaterThan(Date& otherDate)
{
	bool returnValue = false;
	if(this->year < otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->month < otherDate.month)
	{
		returnValue = true;
	}
	else if(this->day < otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}
/************************************************************************/
/* Operator +                                                           */
/************************************************************************/
Date Date::operator+(ShortInt days)
{
	Date getDate;
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day + days;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
	return getDate;
}
/************************************************************************/
/* Operator -                                                           */
/************************************************************************/
Date Date::operator-(ShortInt days)
{
	Date getDate;
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day - days;

	mktime(&tempDate);

	getDate.year = (ShortInt)tempDate.tm_year + 1900;
	getDate.month = (Month)(tempDate.tm_mon + 1);
	getDate.day = (ShortInt)tempDate.tm_mday;
	getDate.weekday = (Weekday)tempDate.tm_wday;
	return getDate;
}
/************************************************************************/
/* Operator -                                                           */
/************************************************************************/
int Date::operator-(Date& otherDate)
{
	time_t temp1, temp2;
	int returnValue;
	Date getDate;
	struct tm tempDate1 = {0,};
	struct tm tempDate2 = {0,};

	
	tempDate1.tm_year = this->year - 1900;
	tempDate1.tm_mon = this->month - 1;
	tempDate1.tm_mday = this->day;

	temp1 = mktime(&tempDate1);

	tempDate2.tm_year = otherDate.year - 1900;
	tempDate2.tm_mon = otherDate.month - 1;
	tempDate2.tm_mday = otherDate.day;
	
	temp2 = mktime(&tempDate2);
	
	returnValue = (int)(temp2 - temp1);
	
	returnValue = returnValue / (60*60*24);
	
	return returnValue;
}
/************************************************************************/
/* Operator ==                                                          */
/************************************************************************/
bool Date::operator==(const Date& otherDate)
{
	bool returnValue = false;
	
	if(this->year == otherDate.year)
	{
		if(this->month == otherDate.month - 1)
		{
			if(this->day == otherDate.day)
			{
				returnValue = true;
			}
		}
	}
	return returnValue;
}
/************************************************************************/
/* Operator !=                                                          */
/************************************************************************/
bool Date::operator!=(const Date& otherDate)
{
	bool returnValue = false;
	
	if(this->year != otherDate.year || this->month != (otherDate.month - 1) || this->day != otherDate.day)
	{
		returnValue = true;
	}
	
	return returnValue;
}
/************************************************************************/
/* Operator >=                                                           */
/************************************************************************/
bool Date::operator>=(const Date& otherDate)
{
	bool returnValue = false;
	if(this->year > otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->year == otherDate.year && this->month > otherDate.month)
	{
		returnValue = true;
	}
	else if(this->year == otherDate.year && this->month == otherDate.month && this->day >= otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}

/************************************************************************/
/* Operator <=                                                          */
/************************************************************************/
bool Date::operator<=(const Date& otherDate)
{
	bool returnValue = false;
	if(this->year < otherDate.year)	
	{
		returnValue = true;
	}
	else if(this->year == otherDate.year && this->month < otherDate.month)
	{
		returnValue = true;
	}
	else if(this->year == otherDate.year && this->month == otherDate.month && this->day <= otherDate.day)
	{
		returnValue = true;
	}
	return returnValue;
}
/************************************************************************/
/* Operator ++ prefix                                                   */
/************************************************************************/
Date& Date::operator++()
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day + 1;

	mktime(&tempDate);

	this->year = (ShortInt)tempDate.tm_year + 1900;
	this->month = (Month)(tempDate.tm_mon + 1);
	this->day = (ShortInt)tempDate.tm_mday;
	this->weekday = (Weekday)tempDate.tm_wday;

	return *this;
}
/************************************************************************/
/* Operator ++ postfix                                                  */
/************************************************************************/
Date Date::operator++(int)
{
	Date returnDate;
	struct tm tempDate = {0,};

	returnDate.year = this->year;
	returnDate.month = this->month;
	returnDate.day = this->day;
	returnDate.weekday = this->weekday;
	
	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day + 1;

	mktime(&tempDate);

	this->year = (ShortInt)tempDate.tm_year + 1900;
	this->month = (Month)(tempDate.tm_mon + 1);
	this->day = (ShortInt)tempDate.tm_mday;
	this->weekday = (Weekday)tempDate.tm_wday;
	
	return returnDate;
}
/************************************************************************/
/* Operator -- prefix                                                   */
/************************************************************************/
Date& Date::operator--()
{
	struct tm tempDate = {0,};

	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day - 1;

	mktime(&tempDate);

	this->year = (ShortInt)tempDate.tm_year + 1900;
	this->month = (Month)(tempDate.tm_mon + 1);
	this->day = (ShortInt)tempDate.tm_mday;
	this->weekday = (Weekday)tempDate.tm_wday;

	return *this;
}
/************************************************************************/
/* Operator -- postfix                                                  */
/************************************************************************/
Date Date::operator--(int)
{
	Date returnDate;
	struct tm tempDate = {0,};

	returnDate = *this;
	
	tempDate.tm_year = this->year - 1900;
	tempDate.tm_mon = this->month - 1;
	tempDate.tm_mday = this->day - 1;

	mktime(&tempDate);

	this->year = (ShortInt)tempDate.tm_year + 1900;
	this->month = (Month)(tempDate.tm_mon + 1);
	this->day = (ShortInt)tempDate.tm_mday;
	this->weekday = (Weekday)tempDate.tm_wday;
	
	return returnDate;
}
/************************************************************************/
/* Operator =                                                           */
/************************************************************************/
Date& Date::operator=(const Date& source)
{
	this->year = source.year;
	this->month = source.month;
	this->day = source.day;
	this->weekday = source.weekday;

	return *this;
}
/************************************************************************/
/* Casting                                                              */
/************************************************************************/
Date::operator char*()
{
	static char buffer[11];
	sprintf(buffer, "%4d-%02d-%02d", this->year, this->month, this->day);
	return buffer;
}
/************************************************************************/
/* CastingDateForm                                                      */
/************************************************************************/
void Date::CastingDateForm(char* date)
{
	static Date buffer;
	struct tm currentDate = {0,};
	
	sscanf(date,"%4d-%2d-%2d",&this->year, &this->month, &this->day);
	currentDate.tm_year = this->year - 1900;
	currentDate.tm_mon = this->month - 1;
	currentDate.tm_mday = this->day;

	mktime(&currentDate);

	this->year = (ShortInt)(currentDate.tm_year + 1900);
	this->month = (Month)(currentDate.tm_mon + 1);
	this->day = (ShortInt)currentDate.tm_mday;
	this->weekday = (Weekday)currentDate.tm_wday;
}
