#include <iostream>
#include <cstdlib>

using namespace std;

const int MaxExams=8;
typedef int gradesT[MaxExams];

void readWithCheckingData(int &exams,gradesT grades);
void willGetCertificate(int exams,const gradesT grades);
bool didGetFive(int exams,const gradesT grades);

int main()
{
    cerr << "Test1-2" << endl;

    /// DECLARATION
    int exams;
    gradesT grades;

    // bool certificate;
    // bool existsFive;

    /// INPUT
    readWithCheckingData(exams,grades);

    /// ALGORITHM
    /// OUTPUT
    willGetCertificate(exams,grades);
    if (didGetFive(exams,grades)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

void readWithCheckingData(int &exams,gradesT grades){
    bool err=false;
    string tmp;
    do {
        cerr << "Number of exams? :";
        cin >> tmp;
        exams=atoi(tmp.c_str());
        err=((exams < 1) || (MaxExams < exams));
        if (err) {
            cerr << "  ERROR! This number must be between 1 and " << MaxExams << "!" << endl;
        }
    } while (err);
    for (int i=0;i<exams;i++) {
        do {
            cerr << (i+1) << ". grade? :";
            cin >> tmp;
            grades[i]=atoi(tmp.c_str());
            err=((grades[i] < 1) || (5 < grades[i]));
            if (err) {
                cerr << "  ERROR! This number must be between 1 and 5!" << endl;
            }
        } while (err);
    }
}

void willGetCertificate(int exams,const gradesT grades){
    int sum=0;
    for (int i=0;i<exams;i++) {
        sum+=grades[i];
    }
    if ((sum/exams)>=2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

bool didGetFive(int exams,const gradesT grades){
    int i=0;
    while ((i<exams) && (grades[i]!=5)) {
        i++;
    }
    return (i<exams);
}
