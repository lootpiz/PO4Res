//Date.h

#ifndef _DATE_H
#define _DATE_H

class Date
{
public:
	/**** TYPENAME ****/
	typedef unsigned short ShortInt;

	/**** ENUMERATOR ****/
	enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
	enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };

	/**** MEMBER FUNCTION ****/
		
		///// CONSTRUCTOR ////
		Date();												//Default Constructor
		Date(char* date);									//Constructor
		Date(Date& source);									//Copy Constructor

		 //// DESTRUCTOR ////
		~Date();											

		//// STATIC MEMBER FUNCTION ////
		static Date GetCurrentDate();
		
		//// OPERATOR FUNCTION ////
		Date operator+(ShortInt days);
		Date operator-(ShortInt days);
		int operator-(Date& otherDate);
		bool operator==(const Date& otherDate);
		bool operator!=(const Date& otherDate);
		bool operator>=(const Date& otherDate);
		bool operator<=(const Date& otherDate);
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);
		Date& operator=(const Date& source);
		
		//// CASTING FUNCTION ////
		operator char*();

		//// NORMAL FUNCTION ////
		void Today();
		void Tomorrow(Date& getDate);
		void Yesterday(Date& getDate);
		void Previousday(ShortInt days, Date& getDate);
		void Nextday(ShortInt days, Date& getDate);
		bool IsEqual(Date& otherDate);
		bool IsNotEqual(Date& otherDate);
		bool IsLessThan(Date& otherDate);
		bool IsGreaterThan(Date& otherDate);
		bool IsNotLessThan(Date& otherDate);
		bool IsNotGreaterThan(Date& otherDate);
		void CastingDateForm(char* date);

	
		//// PROPERTY FUNCTION ////
		ShortInt GetYear() const;
		Month GetMonth() const;
		char* GetMonthString() const;
		ShortInt GetDay() const;
		Weekday GetWeekday() const;
		char* GetWeekdayString() const;

private:
	ShortInt year;
	Month month;
	ShortInt day;
	Weekday weekday;
};

inline Date::ShortInt Date::GetYear() const
{
	return this->year;
}
inline Date::Month Date::GetMonth() const
{
	return this->month;
}
inline char* Date::GetMonthString() const
{
	char* month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	return month[this->month];
}
inline Date::ShortInt Date::GetDay() const
{
	return this->day;
}
inline Date::Weekday Date::GetWeekday() const
{
	return this->weekday;
}
inline char* Date::GetWeekdayString() const
{
	char* weekday[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	return weekday[this->weekday];
}


#endif