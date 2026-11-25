#include <iostream>

using namespace std;
bool is_Leap_Year(short Year)
{
    return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
    short Year;
    cout << "Enter a year: ";
    cin >> Year;

    return Year;
}
int main()
{
    short Year = ReadYear();

     if(is_Leap_Year(Year))
     {
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
     }
     else{
        cout << "\nNo, Year [" <<Year << "] is NOT a leap year.\n";
     }
     
    return 0;
}
