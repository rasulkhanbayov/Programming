#include <iostream>
#include <stdlib.h>

using namespace std;
const int MaxDays=20;
typedef int CaloriesT[MaxDays];

void readWithCheckingDataint(int &days,CaloriesT calories);
bool wentoverlimit (int days , const CaloriesT calories);
void sheconsumedlessthan1620 (int &days , CaloriesT calories);
int main()
{   cout << "Test1-1" << endl;
    int days;
    CaloriesT calories;
    readWithCheckingDataint (days, calories);

    wentoverlimit (days, calories);
    if (wentoverlimit (days, calories)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    sheconsumedlessthan1620 (days, calories);
    return 0;
}

void readWithCheckingDataint(int &days,CaloriesT calories){
    bool error = false;
    string tmp;
    do{
        cerr << "days? :"<<endl;
        cin >> tmp;
       days=atoi(tmp.c_str());
        error= ((days<1) || (days > 20));
        if (error){

            cerr << "  ERROR! Days must be between 1 and 20.";
        }
    }while(error);
   for (int i = 0; i<days; i++){
            do {
        cerr << "Calories? :";
        cin >> tmp;
        /// check data
        calories[i]=atoi(tmp.c_str());
        error=((calories[i]<1000) || (3000<calories[i]));
        if (error) {
            /// feedbacks to the user
            cerr << "  ERROR! Days must be between 1000 and 3000.";
        }
    } while (error);
        }
}

bool wentoverlimit (int days , const CaloriesT calories){
        bool overlimit;
for (int i = 0 ; i<days; i++){
        if(calories[i] > 1800 ){
            overlimit = true;
        }
    }
   return overlimit;
}
void sheconsumedlessthan1620 (int &days , CaloriesT calories){
    int dayscount = 0;
    for (int i = 0 ; i<days; i++){
        if (calories[i]<=1620){
            dayscount++;
        }
    }
        cout << dayscount<<endl;
}
