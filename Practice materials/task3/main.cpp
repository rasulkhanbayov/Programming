#include <iostream>
#include <cstdlib>

using namespace std;

struct adam {
    string add;
    float points;
};

int main()
{
    string tmp;
    getline(cin, tmp , ' ');
    int n = atoi(tmp.c_str());

    getline(cin, tmp , '\n');
    int total = atoi(tmp.c_str());

    adam lst[n];

    for (int i = 0 ; i < n ; i++){
        getline(cin,lst[i].add,';');
        getline (cin,tmp,'\n');
        lst[i].points = atoi(tmp.c_str());
    }
    float first = total*0.9;
    float second = total*0.8;
    float third = total*0.7;

    string fname[n];
    string sname[n];
    string tname[n];
    string frname[n];

    int firstn = 0;
    int secn = 0;
    int thirdn = 0;
    int fourn = 0;

    for (int i = 0 ; i < n ; i++){
       if (lst[i].points >= first ){
            fname[firstn] = lst[i].add;
            firstn++;
       }else if( lst[i].points >= second && lst[i].points < first){
            sname[secn] = lst[i].add;
            secn++;
       }else if(lst[i].points >= third && lst[i].points < second){
            tname[thirdn] = lst[i].add;
            thirdn++;
       }else{
            frname[fourn] = lst[i].add;
            fourn++;
       }
    }

    cout << firstn;
    for(int i = 0; i<firstn ; i++){
        cout  << ";" << fname[i];
    }
    cout << endl;

    cout << secn;
    for(int i = 0; i<secn ; i++){
        cout  << ";"<< sname[i];
    }
    cout << endl;

    cout << thirdn;
    for(int i = 0; i<thirdn ; i++){
        cout  << ";"<< tname[i];
    }
    cout << endl;

    cout << fourn;
    for(int i = 0; i<fourn ; i++){
        cout << ";" << frname[i];
    }

    return 0;
}
