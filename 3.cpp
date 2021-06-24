#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
    long long T,N,K,i;
    cin>>T;
    for(i=0;i<T;i++)
    {
        long long j;
        long long a[100000];
        long long sum=0;
        cin>>N>>K;
        for(j=0;j<N;j++)
        {
            cin>>a[j];
        }
        for(j=0;j<N;j++)
        {
            sum=sum+a[j];
        }
        cout<<sum%K<<'\n';
        
    }
	return 0;
}
