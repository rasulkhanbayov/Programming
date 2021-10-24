#include <iostream>

using namespace std;

struct Data{
int factoryID;
int candyID;
int price;
};

int main()
{
    int numcandy,factories,candytypes;
    cin >> numcandy >> factories >> candytypes;
    struct Data data[numcandy];
    for(int i =0 ;i<numcandy;i++){
        cin >> data[i].factoryID >> data[i].candyID >> data[i].price;
    }

    /// Task a
    int cheapest=data[0].price;
    int chfacID=data[0].factoryID;
    int chcanID=data[0].candyID;
    for(int i =1;i<numcandy;i++){
        if(data[i].price<cheapest){
            cheapest=data[i].price;
            chfacID=data[i].factoryID;
            chcanID=data[i].candyID;
        }
    }

    /// Task b
    int result[factories]={0};
    for(int i =0;i<numcandy;i++){
        result[data[i].factoryID-1]++;
    }
    int maxi=result[0];
    int maxcan=1;
    for(int i=1;i<factories;i++){
        if(result[i]>maxi){
            maxi=result[i];
            maxcan=i+1;
        }
    }

    /// Task c
    int cont = 0;
    int maxID[factories];
    int maxPrice[factories];

    for(int i =0 ; i < factories ; i++){
        if(result[i] > 0){
            int tmpId = 0;
            int tmpPr = 0;
            for(int j = 0 ; j < numcandy ; j++){
                if( i + 1 == data[j].factoryID && tmpPr < data[j].price){
                    tmpId = data[j].factoryID;
                    tmpPr = data[j].price;
                }
            }
            maxID[cont] = tmpId;
            maxPrice[cont] = tmpPr;
            cont++;
        }
    }

    /// Task d
    int flag=0;
    int cnt=0;
    int result3[candytypes]={0};
    for(int i =0;i<numcandy;i++){
        for(int j=0;j<cnt;j++){
            if(data[i].candyID==result3[j]){
                flag=1;
            }
        }
        if(flag==0){
            result3[cnt]=data[i].candyID;
            cnt++;
        }
        flag=0;
    }

    /// Task e
    int flag2=0;
    int counting=0;
    int result4[candytypes]={0};
    for(int i =0;i<numcandy;i++){
        for(int j =0; j< numcandy;j++){
           if(data[i].candyID==data[j].candyID && i!=j){
            flag2=1;
           }
        }
        if(flag2==0){
            result4[counting]=data[i].candyID;
            counting++;
        }
        flag2=0;
    }
    int temp;
    for(int i = 0; i<counting; i++) {
       for(int j = i+1; j<counting; j++){
      if(result4[j] < result4[i]) {
         temp = result4[i];
         result4[i] = result4[j];
         result4[j] = temp;
      }
   }
}

    /// Output task a
    cout << chfacID << " " << chcanID << endl;

    /// Output task b
    cout << maxcan << endl;
    /// Output task c
    cout << cont;
    for(int i = 0 ; i < cont ; i++){
        cout << " " << maxID[i] << " " << maxPrice[i];
    }
    cout << endl;
    /// Output task d
    cout << cnt << endl;

    /// Output task e
    cout << counting;
    for(int i =0; i< counting; i++){
        cout << " "  << result4[i];
    }

}
