#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
        }
        if(sum>=0)
            if(sum>n)
            res=sum-n;
            if(sum==n)
            res=0;
            
        if(sum<0)
        {
           res=1; 
        }  
        cout<<res<<endl;
    }
	return 0;
}
