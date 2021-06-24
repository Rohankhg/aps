#include <bits/stdc++.h>
using namespace std;
#define MAX 3E5+5

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,a,b,i,j;
    cin>>t;
    while(t--){
        cin>>a>>b;
        long long int n[a];
        long long int m[b];
        for (long long int i=0;i<a;i++)
        {
            cin>>n[i];
        }
        for(long long int i=0;i<b;i++)
        {
            cin>>m[i];
        }
        long long int Max=MAX;
    
        long long int Q[a];
        
        long long int low=-1,high=-1;
        for(i=0;i<a;i++)
        {
           if(i==0)
           {
            Q[i]=0;
           }
           else if(n[i]!=0)
           {
            Q[i]=0;
           }
           else{
            Q[i]=Max;   
           } 
       }
       for(i=0;i<a;i++)
       {
           if(n[i]==1)
           {
               high=i;
           }
           if(high!=-1)
           {
               if(n[i]==0)
               {
                Q[i]=min(Q[i],i-high);
               }
           }
       }
        for(i=a-1;i>=0;i--)
        {
            if(n[i]==2)
            {
                low=i;  
            }
            if(low!=-1)
            {
                if(n[i]==0)
                { 
                    Q[i] =min(Q[i],low-i);
                }
            }
        }
        
        for(i=0;i<b;i++){
            
            j=m[i]-1;
            
            if(Q[j]!=Max)
            {
                cout<<Q[j]<<" ";
            }
            else
            {
                cout<<-1<<" ";
            }
        }
       cout<<endl;
    }
}