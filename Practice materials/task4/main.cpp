#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Data{
string name;
int month;
int day;
};

int main()
{
    string give;
    getline(cin,give,'\n');
    int N;
    cin >> N;
    struct Data data[N];
    for(int i =0; i<N; i++){
    cin.ignore();
    getline(cin,data[i].name,'\n');
    cin>> data[i].month>> data[i].day;
    }

    /// Task a
    int cnt=0;
    int months[N];
    int days[N];
    for(int i =0;i<N;i++){
        if(data[i].name==give){
          months[cnt]=data[i].month;
          days[cnt]=data[i].day;
          cnt++;
        }
    }

    /// Task b
    int namecnt=0;
    string names[N];
    int flag=0;
    for(int i = 0;i<N;i++){
        for(int j =0;j<namecnt;j++){
            if(data[i].name==names[j]){
                flag=1;
            }
        }
        if(flag==0){
            names[namecnt]=data[i].name;
            namecnt++;
        }
        flag=0;
    }
    /// Task c
    int numbers[12]={0};
    for(int i =0;i< N;i++){
        numbers[data[i].month-1]++;
    }
    /// Task d
   int numbers2[12]={0};
    for(int i =0;i< N;i++){
        numbers2[data[i].month-1]++;
    }
   for(int i =0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if((data[i].month==data[j].month) && (data[i].day==data[j].day)){
            numbers2[data[i].month-1]=numbers2[data[i].month-1]-1;
        }
      }
   }

    int nmmnth=1;
    int maxi = numbers2[0];
    for(int i =1;i<12;i++){
        if(numbers2[i]>maxi){
            maxi=numbers2[i];
            nmmnth=i+1;
        }
    }
    /// Output task a
    cout<< cnt;
    for(int i = 0; i< cnt;i++){
        cout<< " " << months[i] << " " <<days[i];
    }
    cout<<endl;
    /// Output task b
    cout << namecnt<<" ";
    for(int i=0;i<namecnt;i++){
            if((i+1)==namecnt){
             cout<< names[i];
            }
            else{
        cout<< names[i]<<",";
            }
    }
    /// Output task c
    cout<<endl;
    for(int i =0;i< 12;i++){
       cout<< numbers[i]<< " ";
    }
    /// Output task d
    cout<<endl;
    cout<< nmmnth<< " " << maxi << endl;
    return 0;
}
