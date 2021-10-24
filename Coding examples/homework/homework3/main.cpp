#include <iostream>
#include <cstdlib>

using namespace std;
const int MaxBabies=100;
typedef int BabiesT[MaxBabies];

void readWithCheckingDataint(int &babies,BabiesT bornw, BabiesT onemonthw);
bool didGetover4000(int babies,const BabiesT bornw);
void gainedtheleastweight (int &babies,BabiesT bornw, BabiesT onemonthw);
int main()
{   cout << "Test1-3" << endl;
    int babies;
    BabiesT bornw;
    BabiesT onemonthw;
    readWithCheckingDataint (babies, bornw, onemonthw);

    didGetover4000(babies,bornw);
    if (didGetover4000(babies,bornw)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

gainedtheleastweight(babies, bornw, onemonthw);
    return 0;
}
void readWithCheckingDataint (int &babies,BabiesT bornw, BabiesT onemonthw){
bool err=false;
bool erro=false;
    string tmp;
    string tmpr;
    do {
        cerr << "Number of babies? :";
        cin >> tmp;
        babies=atoi(tmp.c_str());
        err=((babies < 0) || (MaxBabies < babies));
        if (err) {
            cerr << "  ERROR! This number must be between 1 and " << MaxBabies << "!" << endl;
        }
    } while (err);
    for (int i=0;i<babies;i++) {
        do {
            cerr << (i+1) << ". bornw? :";
            cin >> tmp;
            bornw[i]=atoi(tmp.c_str());
            err=((bornw[i] < 800) || (7000 < bornw[i]));
            if (err) {
                 cerr << "  ERROR! This number must be between 800 and 7000!" << endl;
                }
            } while (err);
            do {
            cerr << (i+1) << ". onemonthw? :";
            cin >> tmpr;
            onemonthw[i]=atoi(tmpr.c_str());
            erro=((onemonthw[i] < 800) || (9000 < onemonthw[i]));
            if (erro) {
                cerr << "  ERROR! This number must be between 800 and 9000!" << endl;
            }
        } while (erro);
    }

}
bool didGetover4000(int babies,const BabiesT bornw){
    int i=0;
    while ((i<babies) && (bornw[i]<4000)) {
        i++;
    }
    return (i<babies);
}
void gainedtheleastweight(int &babies,BabiesT bornw, BabiesT onemonthw){
   int leastgain = 1;
   for (int i = 2 ; i<babies ; i++){
    if ((onemonthw[i]-bornw[i])<(onemonthw[leastgain]-bornw[leastgain])){
        leastgain = i;
    }

   }
   cout << (leastgain+1) << endl;
}


