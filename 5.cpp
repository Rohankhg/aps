#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool lies(int a,int b,int c)
{

    if((b-a)%c==0 )
        return true;
    else 
        return false;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>k;
        int a=n+1;
        
        if(lies(a,x,k) && x<=a)
            cout<<"YES"<<endl;
        else if(lies(0,x,k) && x<=a)
            cout<<"YES"<<endl;
        
        else 
            cout<<"NO"<<endl;
    }
	return 0;
}
