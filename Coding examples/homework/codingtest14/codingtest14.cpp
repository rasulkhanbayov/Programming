#include <iostream>
#include<cstdlib>
using namespace std;

int main()
{


    cout << " Test1-4 " << endl;
    int N ;
    int M ;
    bool err=false;
    string tmp;
    do {
        cerr << "Number of Runners? :";
        cin >> tmp;
        N=atoi(tmp.c_str());
        err=((N < 2) || (50 < N));
        if (err) {
            cerr << "  ERROR! This number must be between 2 and 50! " << endl;
        }
    } while (err);
    do {
        cerr << "Number of Laps? :";
        cin >> tmp;
        M=atoi(tmp.c_str());
        err=((M < 2) || (20 < M));
        if (err) {
            cerr << "  ERROR! This number must be between 2 and 20! " << endl;
        }
    } while (err);
     int data[N][M];
     for (int i =0 ; i< N;i++){
        for (int j = 0; j<M; j++){
            cin >> data[i][j];
        }
        }
bool exists=false;
int i=0;
while(i<N && exists==false ){
    int j=1;
    while (j<M && data [i][j]<data [i][j-1]){
        j=j+1;
    }
    if (j<M){
        exists=true;
    }
i=i+1;
}
int indexes[N];
int cnt=0;
    for (int i =0 ; i< N;i++){
           if (data[i][0] <60) {
                indexes[cnt]=(i+1);
                cnt=cnt+1;
              }
}
if (exists==true){
cout << "yes" << endl;
}
else{
    cout << "no" << endl;
}
cout << cnt << " ";
for (int i=0; i <cnt ;i++){
    cout << indexes[i] << " ";
}
return 0;
}
/*
6
5
72 70 71 78 80
80 78 77 76 75
58 60 62 59 66
73 72 70 72 73
60 59 57 55 63
58 62 59 67 75
*/
