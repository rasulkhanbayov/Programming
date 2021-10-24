#include <iostream>
#include <cstdlib>

using namespace std;

struct Data{
int salary;
int month;
string name;
};

struct Data2{
string name2;
int salary2;
};

int main()
{
    int N,amount;
    cin >> N >> amount;
    struct Data data[N];
    for(int i =0;i<N;i++){
    cin >> data[i].salary >> data[i].month;
    cin.ignore();
    getline(cin,data[i].name,'\n');
    }

    /// Task a
    int maxi = data[0].salary;
    string name = data[0].name;
    for(int i = 1; i<N;i++){
        if(data[i].salary > maxi){
            maxi=data[i].salary;
            name=data[i].name;
        }
    }

    /// Task b
    string allnames[N];
    int count1=0;
    int flagc=0;
    for(int i =0;i<N;i++){
        for(int j =0;j<count1;j++){
            if(allnames[j]==data[i].name){
                flagc=1;
            }
        }
        if(flagc==0){
            allnames[count1]=data[i].name;
            count1++;
    }
    flagc=0;
    }

    struct Data2 data2[count1];
    int helper=0;
    for(int i =0;i<count1;i++){
        for(int j =0 ; j<N;j++){
            if(data[j].name==allnames[i]){
               helper=helper+data[j].salary*data[j].month;
            }
        }
        data2[i].name2=allnames[i];
        data2[i].salary2=helper*100000;
        helper=0;
    }

    /// Task c
    string result3[N];
    int cntccc=0;
    for(int i =0;i<count1;i++){
        int mono[N];
        int cnt3=0;
        for(int j =0;j<N;j++){
            if(allnames[i]==data[j].name){
                mono[cnt3]=data[j].salary;
                cnt3++;
            }
        }
        int flag3=0;
        for(int z=0;z<cnt3-1;z++){
            if(mono[z+1]<=mono[z]){
                flag3=1;
            }
        }
        if(flag3==0){
            result3[cntccc]=allnames[i];
            cntccc++;
        }
            flag3=0;

    }

    /// Task d
    string result4[N];
    int cnt4=0;
    int flag4=0;
    for(int i =0;i<N;i++){
        if(data[i].salary>amount){
            for(int z =0;z<cnt4;z++){
                if(data[i].name==result4[z]){
                    flag4=1;
                }
            }
            if(flag4==0){
                result4[cnt4]=data[i].name;
                cnt4++;
            }
            flag4=0;
        }
    }
    /// Output Task a
    cout << "#" << endl;
    cout << name << endl;

    /// Output Task b
    cout << "#" << endl;
    cout << count1 << endl;
    for(int i =0;i<count1;i++){
        cout << data2[i].name2 << " " << data2[i].salary2 << endl;
    }

    /// Output Task c
    cout << "#" << endl;
    if(cntccc>0){
        cout << result3[0] << endl;
    }
    else{
        cout << "NONE" << endl;
    }
    /// Output Task d
    cout << "#" << endl;
    cout << cnt4 << endl;
    for(int i =0;i< cnt4 ; i++){
        cout << result4[i] << endl;
    }

    return 0;
}
