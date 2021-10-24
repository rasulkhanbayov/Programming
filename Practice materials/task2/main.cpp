#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string sol[N];
    string sag[N];
    int flag=1;
    for(int i =0;i<N;i++){
        cin >> sol[i] >> sag[i];
    }
    int cnt=0;
    string result[N];
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){

            if(sag[i]==sol[j]){
                for(int z=0;z<cnt;z++){
                if(sol[i]==result[z]){
                    flag=1;
                }
                }
                if(flag==0){
                result[cnt]=sol[i];
                cnt++;
                }
            }
         flag=0;
        }
    }
   if(cnt==0){
   cout<<cnt<<endl;
   }
   else{
    cout << cnt << endl;
    for(int i =0;i<cnt ; i++){
        cout<< result[i] << endl;
    }
   }
}
