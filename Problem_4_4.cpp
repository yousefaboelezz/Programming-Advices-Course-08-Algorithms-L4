#include <iostream>
using namespace std;

bool is_Leap_Year(short Year)
{
    return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDayInYear(short Year)
{
    return is_Leap_Year(Year) ? 366 : 365;
}
short NumberOfHoursInYear(short Year)
{
    return NumberOfDayInYear(Year) * 24 ;
}
int NumberOfMinutesInYear(short Year)
{
    return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondInYear(short Year)
{
    return NumberOfMinutesInYear(Year) * 60;
}
short ReadYear()
{
    short Year ;
    cout << "Please enter a year to check: ";
    cin >> Year;

    return Year;
}

int main ()
{
   short Year = ReadYear();
   cout <<"\nNumber of Days  in Year [" << Year << "] is : " << NumberOfDayInYear(Year);
   cout <<"\nNumber of Hours  in Year [" << Year << "] is : " << NumberOfHoursInYear(Year);
   cout <<"\nNumber of Minutes  in Year [" << Year << "] is : " << NumberOfMinutesInYear(Year);
   cout <<"\nNumber of Second  in Year [" << Year << "] is : " << NumberOfSecondInYear(Year);
    return 0;
}