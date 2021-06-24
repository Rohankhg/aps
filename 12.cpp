#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long T,i;
    long long total=0;
    cin>>T;
    for(i=0;i<T;i++)
    {
        long long N,j,t,A[4][4]={0};
        long long k;
        char m;
        cin>>N;
        for(j=0;j<N;j++)
        {
            cin>>m;
            cin>>t;
            if(t==12)
            {
                t=0;
            }
            A[m%65][t/3]++;
        }
        long long max[4]={0};
        long long l=0,p=0,q=0;
         for(j=0;j<4;j++)
        {
            long long most=0;
            for(k=0;k<4;k++)
            {
                if(A[k][j]>most)
                {
                    most=A[k][j];
                    p=k;
                }
            }
            if(most!=0)
            {
            for(q=0;q<4;q++)
            {
                 A[p][q]=0;
            }
            }
            max[l]=most;
            l++;
        }
        sort(max,max+4,greater<>());
        long long sum=0;
        if(max[0]==0)
        {
            sum=-400;
        }
        else if(max[1]==0)
        {
            sum=(100*max[0])-300;
        }
        else if(max[2]==0)
        {
            sum=(100*max[0])+(75*max[1])-200;
        }
        else if(max[3]==0)
        {
            sum=(100*max[0])+(75*max[1])+(50*max[2])-100;
        }
        else
        {
            sum=(100*max[0])+(75*max[1])+(50*max[2])+(25*max[3]);
        }
        cout<<sum<<'\n';
        total=total+sum;
        

    }
     cout<<total<<'\n';
    
    
}