#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
    long long T,N,i;
    cin>>T;
    for(i=0;i<T;i++)
    {
        long long length[100000];
        long long breadth[100000];
        long long j,sum=0;
        cin>>N;
        for(j=0;j<N;j++)
        {
            cin>>length[j];
        }
        for(j=0;j<N;j++)
        {
            cin>>breadth[j];
        }
        sort(length,length+N);
        sort(breadth,breadth+N);
        for(j=0;j<N;j++)
        {
            sum=sum+min(length[j],breadth[j]);
        }
        cout<<sum<<'\n';
    }
	return 0;
}
