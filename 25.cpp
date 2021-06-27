#include<bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    long long n;
    scanf("%lld", &n);
    n++;
    vector <int> d;
    long long tmp = n;
    while (tmp > 0) {
      d.push_back(tmp % 10);
      tmp /= 10;
    }
    int kd = d.size();
    long long cnt = 0;
    for (int dig = 0; dig <= 9; dig++) {
      for (int j = kd - 1; j >= 0; j--) {
        for (int v = 0; v < d[j]; v++) {
          if (j == kd - 1 && v == 0) {
            if (dig != 0) {
              long long cur = 1;
              for (int jj = 0; jj < j; jj++) cur *= 9;
              cnt += cur;
            } else {
              long long cur = 1;
              for (int jj = 0; jj < j; jj++) {
                cur *= 9;
                cnt += cur;
              }
            }
            continue;
          }
          if (v == dig) continue;
          long long cur = 1;
          for (int jj = 0; jj < j; jj++) cur *= 9;
          cnt += cur;
        }
        if (d[j] == dig) break;
      }
    }
    cnt -= 9;
    long long den = (n - 1) * 10;
    long long num = den - cnt;
    long long x = num, y = den;
    while (x > 0 && y > 0)
      if (x > y) x %= y;
      else y %= x;
    num /= x + y;
    den /= x + y;
    printf("%lld/%lld\n", num, den);
  }
  return 0;
}
