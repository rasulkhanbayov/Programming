#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int N;
    string tmp;
    bool err=false;
    do{
    cerr << "Number of patients? :";
    cin >> tmp;
    N=atoi(tmp.c_str());
    err=((N < 2) || (50 < N));
    if (err) {
        cerr << "  ERROR! This number must be between 2 and 50!" << endl;
        }
    } while (err);
    string name[N];
    int allowed[N];
    int consumed[N];
    for (int i=0; i<N;i++){
    cerr << "Enter patients name"<< endl;
    //getline (cin,name[i]);
    cin >> name[i];
    cerr << "Enter allowed calories"<< endl;
    cin >> allowed[i];
    cerr << "Enter consumed calories"<< endl;
    cin >> consumed[i];
    }
    int maxindex=-1;
    int maxvalue=0;
    int exceed;
    string answer;
    for (int i =0; i< N;i++){
    exceed=consumed[i]-allowed[i];
    if (exceed > maxvalue){
        maxindex=i;
        maxvalue=exceed;
    }
    }
    if (maxvalue>0){
        answer=name[maxindex];
        }
    else {
        answer="None";
    }
    int cnt=0;
    int i=1;
    bool exists;
    while (i<N && cnt < 3){
        if (consumed[i]<=allowed[i]){
            cnt=cnt+1;
            i=i+1;
        }
    }

    if (cnt == 3){
       exists=true;
    }
    else{
        exists=false;
    }
    cout << answer << endl;
    cout << exists << endl;

            return 0;
}
/*
John
1700
1800
Andrew
1900
1890
Paul
2100
2000
Thomas
1700
2000
Sergiano
2000
1900
Teo
2050
2000

*/

/*
#include <iostream>
#include <cstdlib>

using namespace std;
const int MaxN=100;
struct Data{
    string name;
    int allowed;
    int consumed;
};
typedef Data DataArray[MaxN];
void readWithCheckingDataint(int &N, DataArray name,DataArray allowed, DataArray consumed);
void exceededthemost (int &N,DataArray name,DataArray allowed, DataArray consumed);
bool followedtheinstructions (int N,DataArray name,DataArray allowed, DataArray consumed);
int main()
{
    int N;
    DataArray data;
    readWithCheckingDataint (N, data[0].name, data[0].allowed, data[0].consumed);
    return 0;
}
void readWithCheckingDataint(int &N ,DataArray name,DataArray allowed, DataArray consumed){
bool err=false;
    string tmp;
    do {
        cerr << "Number of patients? :";
        cin >> tmp;
        N=atoi(tmp.c_str());
        err=((N < 0) || (MaxN < N));
        if (err) {
            cerr << "  ERROR! This number must be between 1 and " << MaxN << "!" << endl;
        }
    } while (err);
    for (int i=0;i<N;i++) {
            cerr << (i+1) << ". allowed? :";
            cin >> tmp;
            data[i].allowed=atoi(tmp.c_str());
            cerr << (i+1) << ". consumed? :";
            cin >> tmpr;
            data[i].consumed=atoi(tmpr.c_str());
    }

}
void exceededthemost (DataArray name,DataArray allowed, DataArray consumed){

}
*/
