#include <bits/stdc++.h>
 
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>>
 
long long int getnode(long long int p, vvi & G,long long int  n){
  vector<bool> done(n+1, false);
  
  long long int fd=-1,dur;
  done[p] = true;
  queue<pair<long long int , long long int >> qu; qu.push({p, 0});
   while(qu.size()){
    auto pi = qu.front(); qu.pop();
    long long int  m = pi.first, dis = pi.second;
    if(fd < dis) fd = dis, dur = m;
 
    for(auto q: G[m]){
      if(done[q]) continue;
      done[q] = true;
      qu.push({q, dis+1});
    }
  }
  return dur;
}
 
void node3(long long int m, long long int par, vvi & G, vi & H, vi & li, long long int  cur){
  bool isleaf = true;
  long long int  mx = 0;
  for(auto q: G[m])
  if(q != par) {isleaf = false; mx = max(mx, H[q]);}
  if(isleaf){ li.push_back(cur); return; }
 
  long long int  c = 0;
  for(auto q: G[m]){
    if(q == par) continue;
    if(H[q] == mx && c==0){
      node3(q, m, G, H, li, cur+1); c++;
    }
    else node3(q, m, G, H, li, 1);
  }
}
 
void node2(long long int  m, long long int  par, vvi & G, vi & H){
  bool isleaf = true;
  for(auto q: G[m]){
    if(q == par) continue;
    isleaf = false;
    node2(q, m, G, H);
    H[m] = max(H[m], 1 + H[q]);
  }
  if(isleaf) H[m] = 1;
}
 
void node1(long long int  m, long long int  par, vvi & G, vi&li, long long int  n){
  vector<long long int > H(n+1, 0);
  node2(m, par, G, H);
  node3(m, par, G, H, li, 1);
}
 
long long int getSol(vvi & N_1, long long int  s, long long int  t){
  if(t==1) return 1;
  long long int  u = getnode(1, N_1, s);
  vector<long long int > li;
  node1(u, 0, N_1, li, s);
  sort(li.rbegin(), li.rend());
  long long int  size = 1, total = 0, i = 0;
  while(total < t){
    size++; total += li[i++];
  }
  return size;
}
int main(){
  
    long long int  p;
    cin>>p;
    long long int _=1;
    while(p--){
    long long int  s, t;
    long long int  u, v;
    cin>>s>>t;
    vvi N_1(s+1);
    for(long long int i=1; i<s; i++){
      cin>>u>>v;
      N_1[u].push_back(v); N_1[v].push_back(u);
    }
    cout << getSol(N_1, s, t) << "\n";
    }
    return 0;
}