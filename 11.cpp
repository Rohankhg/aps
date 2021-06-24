#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long int, long long int>
#define umap_pll_l unordered_map<pll, long long int, node>


struct node
{
 template <class T1, class T2>
 size_t operator()(const pair<T1, T2> &p) const
 {
 auto hash1 = hash<T1>{}(p.first);
 auto hash2 = hash<T2>{}(p.second);
 return hash1 ^ hash2;
 }
};


void dfs1(long long int nod, long long int par, vector<vector<long long int>> &G, vector<long long int> &S, vector<long long int> &P, vector<long long int> &C, vector<long long int> &L, long long int curlev) {
 C[nod] = 1;
 P[nod] = par;
 L[nod] = curlev;
 for (auto cnod : G[nod])
 {
 if (cnod != par)
 {
 dfs1(cnod, nod, G, S, P, C, L, curlev + 1);
 C[nod] += C[cnod];
 S[nod] += S[cnod] + C[cnod];
 }
 } }
void dfs2(long long int nod, long long int par, vector<vector<long long int>> &G, vector<long long int> &T, vector<long long int> &S, vector<long long int> &C, umap_pll_l &Contdp,umap_pll_l &Cdp, long long int n) {
 T[nod] = T[par] + n - 2 * C[nod];
 for (auto cnod : G[nod])
 if (cnod != par)
 {
 dfs2(cnod, nod, G, T, S, C, Contdp, Cdp, n);
 Cdp[make_pair(nod, cnod)] = C[cnod];
 Contdp[make_pair(nod, cnod)] = S[cnod];
 Contdp[make_pair(cnod, nod)] = T[nod] - S[cnod] -
 C[cnod];
 }
 Cdp[make_pair(nod, par)] = n - C[nod];
}

void goUpBy(long long int &u, long long int dist, vector<vector<long long int>> &Pdp) {
 for (long long int i = 20; i >= 0; i--)
 if ((1 << i) <= dist)
 {
 dist -= (1 << i);
 u = Pdp[u][i];
 } }
long long int getLca(long long int a, long long int b, vector<vector<long long int>> &Pdp, vector<long long int> &L) {
 long long int u = a, v = b;
 if (L[u] > L[v])
 goUpBy(u, L[u] - L[v], Pdp);
 if (L[u] < L[v])
 goUpBy(v, L[v] - L[u], Pdp);
 // u and v are at the same place
 if (u == v)
 return u;
 for (int i = 19; i >= 0; i--)
 if (Pdp[u][i] != 0 && Pdp[u][i] != Pdp[v][i])
 u = Pdp[u][i], v = Pdp[v][i];
 u = Pdp[u][0];
 return u; }
void getMidProps(long long int &a, long long int &b, vector<vector<long long int>> &Pdp, vector<long long int> &L, vector<long long int> &v) {
 long long int lca = getLca(a, b, Pdp, L);
 long long int dist = abs(L[lca] - L[a]) + abs(L[lca] - L[b]);
 long long int mva = (dist - 1) / 2, mvb;
 long long int m1 = a, m2;
 // move m1
 goUpBy(m1, mva, Pdp);
 mvb = dist - 1 - mva;
 m2 = b;
 if (m1 != lca)
 m2 = Pdp[m1][0];
 else
 {
 goUpBy(m2, mvb, Pdp);
 }
 v[0] = m1;
 v[1] = m2;
 v[2] = mva;
 v[3] = mvb; }
void showRoute(long long int a, long long int b, vector<vector<long long int>> &Pdp) {
 cout << "[A] " << a << " ";
 while (Pdp[a][0] != 0)
 {
 a = Pdp[a][0];
 cout << a << " ";
 }
 cout << "\n";
 cout << "[B] " << b << " ";
 while (Pdp[b][0] != 0)
 {
 b = Pdp[b][0];
 cout << b << " ";
 }
 cout << "\n"; }
void solve(vector<vector<long long int>> &G, int n, int q) {
 vector<long long int> S(n + 1, 0), P(n + 1, 0), C(n + 1, 0), T(n + 1, 0), L(n + 1, 0);
 umap_pll_l Contdp, Cdp;
 dfs1(1, 0, G, S, P, C, L, 1);
 T[0] = S[1] + C[1];
 dfs2(1, 0, G, T, S, C, Contdp, Cdp, n);
 vector<vector<long long int>> Pdp(n + 1, vector<long long int>(20, 0));
 for (int nod = 1; nod <= n; nod++)
 Pdp[nod][0] = P[nod];
 for (int j = 1; j < 20; j++)
 for (int nod = 1; nod <= n; nod++)
 Pdp[nod][j] = Pdp[Pdp[nod][j - 1]][j - 1];
 vector<long long int> v(4, 0);
 long long int a, b, ans = 0;
 while (q--)
 {
 //cout << "\n";
 cin >> a >> b;
 if (L[a] < L[b])
 swap(a, b);
 getMidProps(a, b, Pdp, L, v);
 long long int m1 = v[0], m2 = v[1], da = v[2], db = v[3];
 long long int conta = T[a] - (da + 1) * Cdp[{m1, m2}] - Contdp[{m1, m2}];
 long long int contb = T[b] - (db + 1) * Cdp[{m2, m1}] - Contdp[{m2, m1}];
 ans = conta + contb;
 cout << ans << "\n";
 } }
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(NULL);
 int t;
 cin >> t;
 long long int n, q;
 while (t--)
 {
 cin >> n >> q;
 vector<vector<long long int>> G(n + 1);
 long long int u, v;
 for (int i = 1; i < n; i++)
 {
 cin >> u >> v;
 G[u].push_back(v);
 G[v].push_back(u);
 }
 solve(G, n, q);
 }
 return 0; }