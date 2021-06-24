#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,a,b;
    cin>>t;
    while(t--)
    {
        cin>>x>>a>>b;
        long long ans=0;
        ans=(100-x)*b+a;
        cout<<ans*10<<endl;
    }
	return 0;
}
