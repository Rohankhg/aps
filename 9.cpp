#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<long long int,long long int>>x;
        vector<pair<long long int,long long int>>y;
        multiset<long long int> r;
        multiset<long long int> s;
        long long int h1=0,w1=0,h2=0,w2=0,h1_max=0,w1_max=0,h1_min=LONG_MAX,w1_min=LONG_MAX;
        long long int ar=LONG_MAX;
        long long int n_ar;
        
        for(long long int i=0;i<n;i++)
        {
            cin>>a>>b;
            x.push_back({a,b});
            y.push_back({b,a});
            r.insert(a);
            s.insert(b);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        for(long long int i=0;i<n-1;i++)
        {
            h1_max=max(h1_max,x[i].second);
            h1_min=min(h1_min,x[i].second);
            h1=h1_max-h1_min;
            auto it=s.find(x[i].second);
            s.erase(it);
            h2=*s.rbegin()-*s.begin();
            n_ar=(x[i].first-x[0].first)*h1+(x[n-1].first-x[i+1].first)*h2;
            ar=min(ar,n_ar);
        }
        for(long long int i=0;i<n-1;i++)
        {
            w1_max=max(w1_max,y[i].second);
            w1_min=min(w1_min,y[i].second);
            w1=w1_max-w1_min;
            auto it=r.find(y[i].second);
            r.erase(it);
            w2=*r.rbegin()-*r.begin();
            n_ar=(y[i].first-y[0].first)*w1+(y[n-1].first-y[i+1].first)*w2;
            ar=min(ar,n_ar);
        }
        
        if(ar==LONG_MAX)
        {
            ar=0;
        }
        cout<<ar<<endl;
        
        
    }
}