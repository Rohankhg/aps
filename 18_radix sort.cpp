
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define K 10
#define M 10
#define DIF 2147483648

void counting_sort(ll arr[], ll  n, ll p) {
    ll element = pow(10, p);
    ll divs = element / 10;
    ll count[M];
    for(ll i = 0; i < M; i++)
        count[i] = 0;
    for(ll i = 0; i < n; i++)
        count[(arr[i] % element) / divs] ++;
    for(ll i = 1; i < M; i++)
        count[i] += count[i-1];
    ll op[n];
    for(ll i = n-1; i >= 0; i--) {
        op[count[(arr[i] % element) / divs] - 1] = arr[i];
        count[(arr[i] % element) / divs] --;
    }
    for(ll i = 0; i < n; i++)
        arr[i] = op[i];
}

void radix_sort(ll arr[], ll n) {
    for(ll i = 1; i <= K; i++)
        counting_sort(arr, n, i);
}

int main() {    
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]+=DIF;
    }
    radix_sort(arr, n);
    for(ll i = 0; i < n; i++) {
        cout << arr[i]-DIF << ' ';
    }
    cout << '\n';
    return 0;
}
