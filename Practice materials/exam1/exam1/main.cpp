#include <iostream>

using namespace std;

struct Data{
int studentID;
int eventID;
};

int main()
{
    int students, events, applications;
    cin >> students >> events >> applications ;
    struct Data data[applications];
    for(int i =0;i<applications;i++){
        cin >> data[i].studentID >> data[i].eventID;
    }
    int id;
    cin >> id;

    int allstudents[students];
    int cccc=0;
    int flagcc=0;
    for(int i =0;i<applications;i++){
        for(int j=0;j<cccc;j++){
            if(allstudents[j]==data[i].studentID){
                flagcc=1;
            }
        }
            if(flagcc==0){
                allstudents[cccc]=data[i].studentID;
                cccc++;
            }
            flagcc=0;
    }
    int tmp;
    for(int i = 0; i<cccc; i++) {
       for(int j = i+1; j<cccc; j++){
      if(allstudents[j] < allstudents[i]) {
         tmp = allstudents[i];
         allstudents[i] = allstudents[j];
         allstudents[j] = tmp;
      }
   }
}


    int allevents[events];
    int ccc=0;
    int flagc=0;
    for(int i =0;i<applications;i++){
        for(int j=0;j<ccc;j++){
            if(allevents[j]==data[i].eventID){
                flagc=1;
            }
        }
            if(flagc==0){
                allevents[ccc]=data[i].eventID;
                ccc++;
            }
            flagc=0;

    }

    int temp;
    for(int i = 0; i<ccc; i++) {
       for(int j = i+1; j<ccc; j++){
      if(allevents[j] < allevents[i]) {
         temp = allevents[i];
         allevents[i] = allevents[j];
         allevents[j] = temp;
      }
   }
}

    /// Task a
    int result1[applications];
    int cnt1=0;
    int flag1=0;
    for(int i =0;i<applications;i++){
        if(data[i].studentID==id){
            for(int j = 0;j<cnt1;j++){
                if(result1[j]==data[i].eventID){
                    flag1=1;
                }
            }
            if(flag1==0){
                result1[cnt1]=data[i].eventID;
                cnt1++;
            }
            flag1=0;
        }
    }
    /// Task b
    int result2[applications];
    int cnt2=0;
    int flag2=0;
    for(int i = 0; i < applications ; i++){
        for(int j =0;j<applications;j++){
            if(data[i].studentID==data[j].studentID && data[i].eventID==data[j].eventID && i!=j){
                for(int z =0;z<cnt2;z++){
                    if(result2[z]==data[i].studentID){
                        flag2=1;
                    }
                }

                if(flag2==0){
                result2[cnt2]=data[i].studentID;
                cnt2++;
                }
                flag2=0;
            }
        }
    }
    /// Task c
    int result3[events];
    int cnt3=0;
    int flag3=0;
    int help=0;
    for(int i =0;i<events;i++){
        int st[applications];
        int count1=0;
        for(int j =0;j<applications;j++){
            if(allevents[i]==data[j].eventID){
                for(int z =0;z<count1;z++){
                    if(st[z]==data[j].studentID){
                        flag3=1;
                    }
                }
                if(flag3==0){
                    help++;
                    st[count1]=data[j].studentID;
                    count1++;
                }
                flag3=0;
            }
        }
        result3[cnt3]=help;
        cnt3++;
        help=0;
    }

    /// Task d
    int result4[students];
    int cnt4=0;
    int flag4=0;
    int helper=0;
    for(int i =0;i<students;i++){
        int ev[applications];
        int count2=0;
        for(int j =0;j<applications;j++){
            if (allstudents[i]==data[j].studentID){


                for(int z =0;z<count2;z++){
                    if(ev[z]==data[j].eventID){
                        flag4=1;
                    }
                }
                if(flag4==0){
                    helper++;
                    ev[count2]=data[j].eventID;
                    count2++;
                }
                flag4=0;
            }
            }
               result4[cnt4]=helper;
        cnt4++;
        helper=0;
    }
    int stid=1;
    int maxi= result4[0];
    for(int i =0;i<cnt4;i++){
        if(result4[i]>maxi){
            maxi=result4[i];
            stid=i+1;
        }
    }

    /// Output Task a
    cout << "#" << endl;
    cout << cnt1 << endl;

    /// Output Task b
    cout << "#" << endl;
    if(cnt2>0){
            int mini=result2[0];
    for(int i =1;i<cnt2;i++){
        if(result2[i]<mini){
            mini=result2[i];
        }
    }
    cout << mini << endl;
    }
    else{
        cout<< "-1" << endl;
    }

    /// Output Task c
    cout << "#" << endl;
    for(int i =0;i<cnt3;i++){
        cout << result3[i] << " ";
    }
    cout << endl;
    /// Output Task d
    cout << "#" << endl;
    cout << stid << endl;
    return 0;
}
