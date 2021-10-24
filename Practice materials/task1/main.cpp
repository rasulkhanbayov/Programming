#include <iostream>

using namespace std;

const int MaxN=100;
struct Data{
    int compId;
    int gen;
};
typedef Data DataArray[MaxN];

int main()
{
    /// declaration
    int N;
    string companies[MaxN];
    int M;
    DataArray data;

    int cnt;
    string gen7Comp[MaxN];

    /// input
    cerr << "N=? :";
    cin >> N;
    for (int i=0;i<N;i++) {
        cerr << i+1 << ". company=? :";
        cin >> companies[i];
    }
    cerr << "M=? :";
    cin >> M;
    int tmp;
    for (int i=0;i<M;i++) {
        cerr << i+1 << ". data :";
        cerr << "  compId=? :";
        cin >> data[i].compId;
        cerr << "  gen=? :";
        cin >> data[i].gen;
        cin >> tmp;
    }
    /// implement algorithm
    cnt=0;
    for (int i=0;i<M;i++) {
        if (data[i].gen==7) {
            gen7Comp[cnt]=companies[data[i].compId-1];
            cnt++;
        }
    }

    /// output
    if (cnt==0) {
        cout << "0 NINCS" << endl;
    } else {
        cout << cnt;
        for (int i=0;i<cnt;i++) {
            cout << " " << gen7Comp[i];
        }
        cout << endl;
    }


    return 0;
}
