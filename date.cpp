#include <cassert>

//Date class
class Date {
public:
  Date(int day, int month, int year);

  int Day() const { return day_; }
  void Day(int day);

  int Month() const { return month_; }
  void Month(int month);

  int Year() const { return year_; }
  void Year(int year);

//private member function that can only be called by class 
private:
  int DaysInMonth(int month, int year) const;
  bool LeapYear (int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

//DaysInMonth function that determines the number of days in any given month
//Called from Date class (hence ::) and it is a const meaning it will not change
int Date::DaysInMonth(int month, int year) const {
  if (month == 2)

    //calls LeapYear function
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
  else
      return 31;
}

//Leap Year function to determine if February has 28 or 29 days
//Called by DaysInMonth function 
bool Date::LeapYear(int year) const {
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 100 == 0 && year % 400 == 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

void Date::Day(int day) {

  //DaysInMonth function calls accessor functions (Month() and Year()) to make it look cleaner
  if (day >= 1 && day <= DaysInMonth(Month(), Year()))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(29, 2, 2016);
  assert(date.Day() == 29);
  assert(date.Month() == 2);
  assert(date.Year() == 2016);
    
  Date date2(29, 2, 2019);
  assert(date2.Day() != 29);
  assert(date2.Month() == 2);
  assert(date2.Year() == 2019);
}