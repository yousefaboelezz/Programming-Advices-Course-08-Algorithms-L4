#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;
    
    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return false;
    
    return Date1.Day < Date2.Day;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    // 0: Sun, 1: Mon, 2: Tue, 3: Wed, 4: Thu, 5: Fri, 6: Sat
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6; // Saturday
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6); // Friday & Saturday
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date1)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
    EndOfMonthDate.Month = Date1.Month;
    EndOfMonthDate.Year = Date1.Year;
    return GetDifferenceInDays(Date1, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date1)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date1.Year;
    return GetDifferenceInDays(Date1, EndOfYearDate, true);
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
          {
                if (IsBusinessDay(DateFrom))
                    DaysCount++;
                DateFrom = IncreaseDateByOneDay(DateFrom);
          }
    return DaysCount;
}

int main()
{
    cout << "\nVacation Starts: ";
    stDate DateFrom = ReadFullDate();
    cout << "\nVacation Ends: ";
    stDate DateTo = ReadFullDate();
    cout << "\nVaction From: " <<
    DayShortName(DayOfWeekOrder(DateFrom)) << " , "
    << DateFrom.Day << "/" << DateFrom.Month << "/" <<
    DateFrom.Year << endl;
    cout << "Vaction To: " << DayShortName(DayOfWeekOrder(DateTo))  << " , "
    << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;
    cout << "\n\nActucal Vacation Days is: " <<
    CalculateVacationDays(DateFrom, DateTo);
   
    system("pause>0");
    return 0;
}
