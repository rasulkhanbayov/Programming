#include <iostream>

using namespace std;

struct Data{
string platenum;
int first;
int last;
};

int main()
{
    int N;
    cin >> N;

    struct Data data[N];
    for(int i =0;i<N;i++){
        cin>>data[i].platenum >> data[i].first >> data[i].last;
    }

    /// Task a
    int result1[N];
    for(int i=0;i<N;i++ ){
        result1[i]=data[i].last-data[i].first+1;
    }
    int sum1=0;
    for(int i =0;i<N;i++){
        sum1 = sum1 + result1[i];
    }

    /// Task b
    string allnames[N];
    int cntc=0;
    int flagc=0;
    for(int i =0;i<N;i++){
        for(int j =0;j<cntc;j++){
            if(allnames[j]==data[i].platenum){
                flagc=1;
            }
        }
        if(flagc==0){
            allnames[cntc]=data[i].platenum;
            cntc++;
        }
        flagc=0;
    }

    int allrentedtimes[N]={0};
    for(int i =0;i<cntc;i++){
        for(int j =0;j<N;j++){
            if(allnames[i]==data[j].platenum){
                allrentedtimes[i]++;
            }
        }
    }



    int allrenteddays[N];
                int sum=0;
    for(int i =0;i<cntc;i++){

        for(int j =0;j<N;j++){
            if(allnames[i]==data[j].platenum){
                sum=sum+data[j].last-data[j].first+1;
            }
        }
    allrenteddays[i]=sum;
    sum=0;
    }

    int maxi2=allrenteddays[0];
    string max2id=allnames[0];
    for(int i =0;i<cntc;i++){
        if(maxi2<allrenteddays[i]){
            maxi2=allrenteddays[i];
            max2id=allnames[i];
        }
    }

    /// Task c
    int days[30]={0};
    for(int i =0;i<N;i++){
        for(int j = data[i].first ; j<=data[i].last;j++){
            days[j-1]++;
        }
    }

    int maxi3=days[0];
    int max3id=1;
    for(int i =0;i<30;i++){
        if(maxi3<days[i]){
            maxi3=days[i];
            max3id=i+1;
        }
    }

    /// Task d
    int result4[30];
    int cnt4=0;
    int flag4=0;
    for(int i =1;i<30;i++){
        for(int j =i-1;j>=0;j--){
            if(days[j]>=days[i]){
                flag4=1;
            }
        }
        if(flag4==0){
            result4[cnt4]=i+1;
            cnt4++;
        }
        flag4=0;
    }

    /// Task e
    /// allnames , allrentedtimes, allrenteddays are above.

    /// Output Task a
    cout << "#" << endl;
    cout << sum1 << endl;

    /// Output Task b
    cout << "#" << endl;
    cout << max2id << endl;

    /// Output Task c
    cout << "#" << endl;
    cout << max3id << endl;
    /// Output Task d
    cout << "#" << endl;
    for(int i =0; i<cnt4;i++){
        cout << result4[i] <<" ";
    }
    cout << endl;
    /// Output Task e
    cout << "#" << endl;
    for(int i =0;i<cntc;i++){
        cout << allnames[i] << " " << allrentedtimes[i] << " " << allrenteddays[i] << endl;
    }

}
