#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);

string func(string s1,string s2){
    for(int i=0;i<s1.size();i++){
        if(s1[i]<s2[i])
            return s1;
        else if(s1[i]>s2[i])
            return s2;
    }
    return s1;
}
string string1(string s,int sz){
    string st;
    for(int i=0;i<sz;i++)
        st+=s[i%s.size()];
    return st;
}
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans=string1(s,k);
    for(int i=0;i<n;i++){
        ans=func(ans,string1(s.substr(0,i+1),k));
    }
    cout<<ans<<endl;
}

int main(){
    FAST1;
    FAST2;
    ll t=1;
    while(t--){
        solve();
    }
}
