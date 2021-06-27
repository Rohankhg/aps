#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);


void solve(){
    ll n;
    cin>>n;
    if(n & 1){
        cout<<"Bob"<<endl;
    }
    else{
    	int ct=0;
        while(n%2==0){
            n/=2;
            ct++;
        }
        if(n>1){
            cout<<"Alice"<<endl;
        }
        else{
            if(ct%2){
                cout<<"Bob"<<endl;
            }
            else{
                cout<<"Alice"<<endl;
            }
        }
    }
}

int main(){
    FAST1;
    FAST2;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
