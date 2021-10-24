#include <iostream>

using namespace std;

struct Data{
int companyID;
int productID;
int price;
};

int main()
{
    int companies,products,offers;
    cin >> companies >> products >> offers;
    struct Data data[offers];
    for(int i =0;i<offers;i++){
        cin >> data[i].companyID >> data[i].productID >> data[i].price;
    }
    /// Task a
    int expensive=data[0].price;
    int exID=data[0].productID;
    for(int i = 1;i<offers;i++){
        if(data[i].price>expensive){
            expensive=data[i].price;
            exID=data[i].productID;
        }
        else if(data[i].price==expensive){
            if(data[i].productID < exID){
            expensive=data[i].price;
            exID=data[i].productID;
            }
        }
    }
    /// Task b
    int flag=0;
    int companynames[companies];
    int cnt=0;
    for(int i =0;i<offers;i++){
        for(int j = 0;j<cnt;j++){
            if(data[i].companyID==companynames[j]){
                flag=1;
            }
        }
        if(flag==0){
            companynames[cnt]=data[i].companyID;
            cnt++;
        }
        flag=0;
    }
     int name;
     int maxi=0;
     int tmp=0;
     for(int i =0;i<cnt;i++){
        for(int j =0;j<offers;j++){
            if(companynames[i]==data[j].companyID){
                tmp++;
            }
        }
        if(tmp>maxi){
            maxi=tmp;
            name=companynames[i];
        }
        else if(tmp==maxi){
            if(companynames[i]<name){
            maxi=tmp;
             name=companynames[i];
            }
        }
        tmp=0;
     }
    /// Task c
    int result3[products]={0};
    for(int i =0;i<offers;i++){
        result3[data[i].productID-1]++;
    }

    int fin[products];
    int cnt3=0;
    for(int i =0;i<products;i++){
        if(result3[i]==1){
            fin[cnt3]=i+1;
            cnt3++;
        }
    }

    /// Task d
    int allcompanies[companies];
    int cnt4=0;
    int flag4=0;
    for(int i =0;i<offers;i++){
        for(int j = 0 ;j<cnt4;j++){
            if(allcompanies[j]==data[i].companyID){
                flag4=1;
            }
        }
        if(flag4==0){
            allcompanies[cnt4]=data[i].companyID;
            cnt4++;
        }
        flag4=0;
    }

    int temp;
    for(int a = 0; a<cnt4; a++) {
       for(int w = a+1; w<cnt4; w++){
      if(allcompanies[w] < allcompanies[a]) {
         temp = allcompanies[a];
         allcompanies[a] = allcompanies[w];
         allcompanies[w] = temp;
      }
   }
}

    int ffirst=0,flast=0;
    for(int i =0;i<cnt4;i++){
        int first[products];
        int cntf=0;
        for(int j =0;j<offers;j++){
            if(allcompanies[i]==data[j].companyID){
                first[cntf]=data[j].productID;
                cntf++;
            }
        }



    int temp;
    for(int a = 0; a<cntf; a++) {
       for(int w = a+1; w<cntf; w++){
      if(first[w] < first[a]) {
         temp = first[a];
         first[a] = first[w];
         first[w] = temp;
      }
   }
}


        for(int z=i+1;z<cnt4;z++){
            int last[products];
            int cntl=0;
                for(int k =0;k<offers;k++){
                    if(allcompanies[z]==data[k].companyID){
                        last[cntl]=data[k].productID;
                        cntl++;
            }
        }


        int tmp;
    for(int a = 0; a<cntl; a++) {
       for(int w = a+1; w<cntl; w++){
      if(last[w] < last[a]) {
         tmp = last[a];
         last[a] = last[w];
         last[w] = tmp;
      }
   }
}



        int flagq=0;
        for(int q=0;q<cntf;q++){
            if(first[q]!=last[q] || cntf!=cntl){
                flagq=1;
            }
        }

        if(flagq==0 && ffirst==0){
            ffirst=allcompanies[i];
            flast=allcompanies[z];
        }

flagq=0;
        }
    }


    /// Output Task a
    cout << "#" << endl;
    cout<<exID<<endl;
    /// Output Task b
    cout << "#" << endl;
    cout << name << endl;
    /// Output Task c
    cout << "#" << endl;
    if(cnt3>0){
    cout << cnt3 << endl;
    for(int i =0;i<cnt3;i++){
        cout << fin[i] << " ";
    }
    }
    else{
        cout << 0 << endl;
    }
    cout << endl;
    /// Output Task d
    cout << "#" << endl;
    if(ffirst>0 && flast>0 && ffirst<flast){
    cout << ffirst << " " << flast << endl;
    }
    else if(ffirst>0 && flast>0 && ffirst>flast){
    cout << flast << " " << ffirst << endl;
    }
    else{
        cout << -1 <<endl;
    }

}
