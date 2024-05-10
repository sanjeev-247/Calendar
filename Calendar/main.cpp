#include <bits/stdc++.h>

using namespace std ;

int getDay(int m, int K, int J){
    // Zeller's congruence
    if(m == 13 || m == 14){
        K--;
    }
    return (1 + ((13*(m+1)) / 5) + K + K/4 + J/4 + 5*J) % 7;
}

int numOfDays(string M, int Y){
    if(M == "APR" || M == "JUN" || M == "SEP" || M == "NOV"){
        return 30;
    }
    else if(M == "FEB"){
        if(Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0)){
            return 29;
        }
        else return 28;
    }
    else return 31;
}

int main() {
    string month; int year;

    cout<<"Enter month & year(e.g., AUG 2022): ";
    cin>>month>>year;

    for(int i = 0; i < month.size(); i++){
        month[i] = toupper(month[i]);
        cout<<"month["<<i<<"] = "<<month[i]<<endl;
    }
    
    int K = year % 100;
    int J = year / 100;
    int m = 1;  //m is month number, accord. to zeller's rule, not same as conventional month number.

    string months[] = {"MAR", "APR", "MAY", "JUN", "JUL", "AUG",
                        "SEP", "OCT", "NOV", "DEC", "JAN", "FEB"};

    int s = sizeof(months)/sizeof(months[0]); //size of months array

    for(int i = 0; i < s; i++){
        if(months[i] == month){
            m += i + 2;  //MAR = 3, APR = 4, ... ,FEB = 14
            break;
        }
    }

    int h = getDay(m, K, J);
    int firstDayOfMonth = ((h + 5) % 7);


    string Days[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

    for(auto i : Days){
        cout<<i<<'\t'<<"  ";
    }

    int t = firstDayOfMonth;

    for(int i = 0; i < numOfDays(month, year); i++){
        if(i == 0){
            cout<<endl;
            while(t--){
                cout<<"  "<<'\t'<<"  ";
            }
        }
        else if((i+firstDayOfMonth)%7 == 0){
            cout<<endl;

        }
        cout<<i+1<<'\t'<<"  ";
    }

    return 0;
}
//Sanjeev testing Git, first time