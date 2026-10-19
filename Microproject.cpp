#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//class: Calender
class calendar
{
    private:
    int date;
    int day;
    int month;
    int year;
    
    //Month Name
    string monthName[12]={
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };
    

    //No. of days in each month
    int dayInMonth[12]={
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    public:

    //Default Constructor
    calendar();

    //Parametrized Constructor
    calendar(int d, int m, int y);
    
    //Input Date
    void getdate();
    
    //Check Leap Year
    bool LeapYear(int y);

    //check Valid Date
    bool validDate(int d, int m, int y);
    
    //Calculate day number
    int calculateDay(int d, int m, int y);
    
    //display day
    void displayDay();
    
    //display monthly calender
    void displayMonth();
    
    //display yearly calender
    void displayYear();
   
    //display month name
   string getMonthName(int m);
    
    //get No. of days
    int getDays(int m, int y);
};

//Default Constructor
calendar::calendar()
{
   day = 1;
   month = 1;
   year = 2001;
}

//Parametrized Constructor
calendar::calendar(int d, int m, int y)
{
   day = d;
   month = m;
   year = y;
}

//Input Date
void calendar::getdate()
{
   cout<<"Enter Year(2001 - 2100):"<<endl;
   cin>>year;
   cout<<"Enter Month(1 - 12):"<<endl;
   cin>>month;
   cout<<"Enter date:"<<endl;
   cin>>day;
}

//Check Leap Year
bool calendar::LeapYear(int y)
{
   if ((y % 400 == 0) ||
        (y % 4 == 0 && y % 100 != 0))
   {
      return true;
   }
   return false;
}

//get No. of days in month
int calendar::getDays(int m, int y)
{
  if(m == 2 && LeapYear(y))
   return 29;
   return dayInMonth[m - 1];
}

//get month name
string calendar::getMonthName(int m)
{
  return monthName[m - 1];
}

//Valid date
bool calendar::validDate(int d, int m, int y)
{
   if(y < 2001 || y > 2100)
   {
     cout<<"Invalid Year"<<endl;
   }
   if(m < 1 || m > 12)
   {
      cout<<"Invalid Month"<<endl;
   }
   if(d < 1 || d > getDays(m, y))
   {
      cout<<"Invalid date"<<endl;
   }
   return true;
}

// CALCULATE DAY
//
// Returns:
// 0 = Sunday
// 1 = Monday
// 2 = Tuesday
// 3 = Wednesday
// 4 = Thursday
// 5 = Friday
// 6 = Saturday
int calendar::calculateDay(int d, int m, int y)
{
   int monthCode[]={
       0, 3, 2, 5, 0, 3,
       5,  1, 4, 6, 2, 4
   };
   if(m < 3)
   { 
     y = y -1;
   }
   int dayNumber=
   (y + y / 4 - y / 100 + y / 400
   + monthCode[m - 1] + d) % 7;
   return dayNumber;
}

//display day
void calendar::displayDay()
{ 
   if(!validDate(day, month, year))
   { 
     cout<<"Invalid Date"<<endl;
     return;
   }
   string dayName[]={
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thrusday",
        "Friday",
        "Saturday"
   };
   int result = calculateDay(day, month, year);
   cout<<"---------------------------------------------"<<endl;
   cout<<"Date: "<<day<<" "<<getMonthName(month)<<" "<<year<<endl;
   cout<<"Day: "<<dayName[result]<<endl;
   cout<<"---------------------------------------------"<<endl;
}

//display Monthly Calender
void calendar::displayMonth()
{
   if(year < 2001 || year > 2100 || month < 1 || month > 12)
   {
      cout<<"Invalid year or month!"<<endl;
   }
   string dayName[]={
      "Sun", "Mon", "Tue", "Wed",
      "Thu", "Fri", "Sat"
   };

   int totalDays = getDays(month, year);
   int firstDay = calculateDay(1, month, year);
   cout<<"========================================================="<<endl;
   cout<<"        "<<getMonthName(month)<<" "<<year<<endl;
   cout<<"========================================================="<<endl;

   for(int i=0; i<7; i++)
   {
      cout<< setw(6) <<dayName[i];
   }

   cout<<"\n----------------------------------------------------------"<<endl;
   for(int i=0; i<firstDay; i++)
   {
      cout<<setw(6)<<" ";
   }

   for(int d=1; d<=totalDays; d++)
   {
      cout<<setw(6)<<d;
      if((firstDay+d) % 7 == 0)
      cout<<endl;
   }
   cout<<"\n========================================================="<<endl;
}

//Display complete year
void calendar::displayYear()
{
   if(year<2001 || year>2100)
   {
      cout<<"Year Must be between 2001 and 2100."<<endl;
   }
   cout<<"#########################################################"<<endl;
   cout<<"                CALENDER OF " <<year<<endl;
   cout<<"########################################################"<<endl;

   for(int m=1; m<=12; m++)
   {
      month = m;
      displayMonth();
   }
}

int main()
{
   calendar c1;
   int choice;

   while( choice != 5)
   {
      cout<<"==================================================="<<endl;
      cout<<"          100-YEAR CALENDER SYSTEM                 "<<endl;
      cout<<"==================================================="<<endl;

      cout<<"1. Find Day of a Date"<<endl;
      cout<<"2. Display Monthly Calender"<<endl;
      cout<<"3. Display Yearly Calender"<<endl;
      cout<<"4. Check Leap Year"<<endl;
      cout<<"5. Exit"<<endl;

      cout<<"-------------------------------------------------"<<endl;
      cout<<"Enter your choice:"<<endl;
      cin>>choice;

      switch(choice)
      {
         case 1:
         {
            c1.getdate();
            c1.displayDay();
            break;
         }
         case 2:
         {
            int y, m;
            cout<<"Enter year (2001 - 2100):"<<endl;
            cin>>y;
            cout<<"Enter Month (1 - 12):"<<endl;
            cin>>m;

            calendar monthly(1, m, y);
            monthly.displayMonth();
            break;
         }
         case 3:
         {
            int y;
            cout<<"Enter year (2001 - 2100):"<<endl;
            cin>>y;
            calendar yearly(1, 1, y);
            yearly.displayYear();
            break;
         }
         case 4:
         {
            int y;
            cout<<"Enter Year:"<<endl;
            cin>>y;
            calendar leapChecker;

            if(leapChecker.LeapYear(y))
               cout<<" "<<y<<" is a Leap Year."<<endl;
            else
               cout<<" "<<y<<" is a not a Leap Year."<<endl;
            break;    
         }
         case 5:
             cout<<"Thank you for using Calender System!"<<endl;
             break;
         default:
             cout<<"Invalid choice! Please try again."<<endl;
      }
   }
   return 0;
}