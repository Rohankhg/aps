#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dsu d(2 * n);
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c;
      x--;
      a[x] = c;
    }
    if (type == 2) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      d.unite(x, y + n);
      d.unite(x + n, y);
    }
    if (type == 3) {
      int x, y, v;
      cin >> x >> y >> v;
      x--; y--;
      if ((d.get(x) != d.get(y) && d.get(x) != d.get(y + n)) || d.get(x) == d.get(x + n)) {
        cout << 0 << '\n';
      } else {
        if (d.get(x) != d.get(y)) {
          cout << '-';
        }
        long long num = v * 1LL * a[x];
        long long den = a[y];
        long long g = __gcd(num, den);
        num /= g;
        den /= g;
        cout << num << '/' << den << '\n';
      }
    }
  }
  return 0;
}
