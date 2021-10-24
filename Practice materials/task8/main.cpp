#include <iostream>

using namespace std;

int main()
{
    int weeks;
    cin >> weeks;
    int data[weeks][7];
    for(int i =0;i<weeks;i++){
        for(int j=0;j<7;j++){
            cin >> data[i][j];
        }
}
    /// Task a
    int result[weeks];
    int cnt=0;
    int sum=0;
    for(int i=0;i<weeks;i++){
        for(int j =0;j<7;j++){
         sum=sum+data[i][j];
        }
        result[cnt]=sum;
        cnt++;
        sum=0;
    }
    /// Task b
    int maxi = result[0];
    int id = 1;
    for(int i =1;i<cnt;i++){
        if(result[i]>maxi){
            maxi=result[i];
            id=i+1;
        }
    }

    /// Task c
    int flag=0;
    int counting=0;
    int result3[weeks];
    for(int i =0;i<weeks;i++){
        for(int j=1;j<7;j++){
            if(data[i][j]<=data[i][j-1]){
                flag=1;
            }
        }
        if(flag==0){
            result3[counting]=i+1;
            counting++;
        }
        flag=0;
    }

    /// Task d
    int result4[weeks];
    int num=0;
    for(int i =0;i<weeks;i++){
        for(int j =0;j<7;j++){
            if(data[i][j]>0){
                num++;
            }
        }
        result4[i]=num;
        num=0;
    }
    int minu=result4[0];
    int idminu=1;
    for(int i =1;i<weeks/2;i++){
        if(result4[i]<minu){
            minu=result4[i];
            idminu=i+1;
        }
    }
    /// Task e

    int ffirst5=0,flast5=0;
    int first5,last5;
    int length5=0;
    int tmp5;
    for(int i =0;i<cnt;i++){
        if(result[i]<=10){
            first5=i+1;
            while(result[i]<=10 && i!=cnt){
                i++;
            }
            last5=i;
        tmp5=last5-first5+1;
        if(tmp5>length5){
            length5=tmp5;
            ffirst5=first5;
            flast5=last5;
        }
        }
    }

    /// Output Task a
    for(int i =0;i<cnt;i++){
        cout << result[i] <<" ";
    }
    cout<<endl;

    /// Output Task b
    cout<< id<< endl;

    /// Output Task c
    cout<< counting;
    for(int i = 0 ;i<counting;i++){
        cout << " " << result3[i];
    }
    cout << endl;

    /// Output Task d
    cout << idminu<< endl;

    /// Output Task e
    if (ffirst5>0 && flast5>0){
    cout << ffirst5 << " " << flast5;
    }
    else{
        cout << 0 << endl;
    }

}
/*
6
5 10 15 20 25 30 35
0 2 0 0 0 0 0
0 0 0 1 0 3 0
0 1 2 3 4 5 6
5 1 0 0 2 1 0
0 0 0 0 0 0 0
*/

/*
8
4 7 16 20 56 140 185
5 3 1 0 0 0 0
0 0 0 0 479 0 0
0 0 0 0 999 46 405
649 575 217 0 0 0 8
0 6 0 3 0 0 0
7 0 0 1 1 0 0
0 1 3 9 23 24 28
*/
