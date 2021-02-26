/// Compiler - GCC
#include<iostream>
using namespace std;


bool leap(int year){
    if(year%4 != 0)
        return false;
    else if(year%100 != 0)
        return true;
    else if(year%400 != 0)
        return false;
    else
        return true;
}


int countDays(int a, int b){
    if(a>b)
        swap(a,b);

    long int dayCount = 0;

    for(int i = a;i<b;++i){
        if(leap(i))
            dayCount += 366;
        else
            dayCount += 365;
    }

    return dayCount;
}


int firstWeekday(int year){
    // First weekday of 2018 is Monday
    int ref_year = 2018;
    long int dayCount = countDays(2018, year);
    long int weekday = year > ref_year ? dayCount %7 : 7 - (dayCount % 7);
    return weekday;
}


void printMonthName(int month){
    switch(month){
        case 0:
            cout<<"\tJanuary\n";
            break;
        case 1:
            cout<<"\tFebruary\n";
            break;
        case 2:
            cout<<"\tMarch\n";
            break;
        case 3:
            cout<<"\tApril\n";
            break;
        case 4:
            cout<<"\tMay\n";
            break;
        case 5:
            cout<<"\tJune\n";
            break;
        case 6:
            cout<<"\tJuly\n";
            break;
        case 7:
            cout<<"\tAugust\n";
            break;
        case 8:
            cout<<"\tSeptember\n";
            break;
        case 9:
            cout<<"\tOctober\n";
            break;
        case 10:
            cout<<"\tNovember\n";
            break;
        case 11:
            cout<<"\tDecember\n";
            break;
        default:
            break;
    }
}


void printMonth(int month, int weekday, bool leap){
    printMonthName(month);
    cout<<" M   T   W   T   F   S   S\n";
    int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(leap)
        monthLength[1] = 29;

    weekday = weekday%7;

    cout<<" ";
    for(int i = 0; i < weekday; ++i)
        cout<<"    ";

    for(int i = 0 ; i < monthLength[month]; ++i){

        cout<<i+1<<"  ";
        if((i+weekday+1)%7 ==0)
            cout<<'\n';

        if(i<8)
            cout<<" ";
    }

    cout<<"\n\n";
}


int main(){
    int year;

    cout<<"Input year:\n> ";
    cin>>year;
    //std::cout<<"First week day of "<<year<<" is "<<intToWeekday(firstWeekday(year))<<'\n';
    //std::cout<<"Number of days between 2018 and "<<year<<" is "<<countDays(2018,year)<<'\n';

    int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int weekday = firstWeekday(year);
    bool isLeapYear = leap(year);
    if(isLeapYear)
        monthLength[1]=29;

    for(int i = 0; i<12; i++){
        printMonth(i,weekday, isLeapYear);
        weekday = (weekday + monthLength[i]) %7;
    }


    return 0;
}
