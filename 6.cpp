#include <iostream>
#include<bits/stdc++.h>

using namespace std;
const unsigned int M = 1000000007;

long long int power(long long int x, long long int y)
{
    long long int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    temp=temp%M;
    if (y % 2 == 0)
        return (temp * temp)%M;
    else
        return (x * temp * temp)%M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,k;
    cin>>t;
    while(t--)
    {   
        cin>>k;
        cout<<power(2,k-1)<<endl;
    }
	return 0;
}
