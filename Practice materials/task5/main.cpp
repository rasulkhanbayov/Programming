#include <iostream>

using namespace std;

struct Data{
int beg;
int en;
int payment;
};


int main()
{
    int events, days;
    cin >> events >> days;
    struct Data data[events];
    for(int i = 0;i<events;i++){
        cin >> data[i].beg >> data[i].en >> data[i].payment;
    }
    /// Task a
    int sum=0;
    for(int i =0;i<events;i++){
        sum=sum+((data[i].en-data[i].beg+1)*data[i].payment);
    }
    /// Task b
    int num=1;
    int maxi=data[0].en-data[0].beg+1;
    for(int i =1;i<events;i++){
        if( (data[i].en-data[i].beg+1) > maxi){
            maxi = data[i].en-data[i].beg+1;
            num=i+1;
        }
    }
    /// Task c
    int result[days]={0};
    for(int i =0;i<events;i++){
        for(int j = data[i].beg-1; j<=data[i].en-1;j++){
            result[j]++;
        }
    }
    int maximum = result[0];
    for(int i =0;i<days;i++){
        if(result[i]>maximum){
            maximum=result[i];
        }
    }

    /// Task d
    int cnt=0;
    int smth=0;
    int lbeg,lend;
    int beginning, ending;
    for(int i =0;i<days;i++){
        if(result[i]==0){
            beginning=i+1;
            while(result[i]==0){
                cnt++;
                i++;
            }
            ending=i;
        }
        if(cnt>smth){
                smth=cnt;
            lbeg=beginning;
            lend=ending;
        }
        cnt=0;
    }
    /// Output Task a
    cout << sum << endl;

    /// Output Task b
    cout<< num << endl;

    /// Output Task c
    cout << maximum << endl;

    /// Output Task d
    if(smth==0){
            cout<< -1 << endl;
    }
    else{
    cout << lbeg << " " << lend << endl;
    }

}
