#include <iostream>

using namespace std;

int main()
{
   int N;
   cin>>N;
   int a[N],month[N],day[N];
   int tmp,last,m,d,cnt=0;
   for(int i=0;i<N;i++){
    cin>>a[i];
    cin>>month[i];
    cin>>day[i];
   }
   cin>>last>>m>>d;
      for(int i=0;i<N-1;i++){
      for(int j=i;j<N;j++){
      if(a[i]>a[j]){
        tmp=a[j];
        a[j]=a[i];
        a[i]=tmp;
      }
      }
      }
   for(int i=0;i<N;i++){
   for(int j=i;j<N;j++){
     if(last>a[i]&&(last-100)<a[i]&&a[i]!=a[i+1]){
cnt++;
         break;
         }
   }
   }
      cout<< cnt <<" ";
     for(int i=0;i<N;i++){
        if(last>a[i]&&(last-100)<a[i]&&a[i]!=a[i+1])
        cout<<a[i]<<" ";
      }
}
/*
5
1957 1 20
2000 1 22
1917 1 8
2001 2 22
1950 5 5
2013 1 9
*/
