#include<bits/stdc++.h>
using namespace std;
long long int power(long long int p,long long int q)
{
    long long int ans=1;
    while(q>0)
    {
        if(q%2)
        {
            ans=(ans*p)%1000000007;
        }
        p=(p*p)%1000000007;
        q=q/2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        long long int c=power(2,a)-1;
        cout<<power(c,b)<<endl;
    }
}