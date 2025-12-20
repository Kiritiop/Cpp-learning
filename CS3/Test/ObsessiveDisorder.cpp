#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[500001];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mu[500001];
    bool prime[500001];
    int primes[500001];
    int pc = 0;

    for (int i = 1; i <= n; i++) {
        mu[i] = 1;
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes[pc++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < pc; j++) {
            int p = primes[j];
            if (i * p > n) break;
            prime[i * p] = false;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }

    long long c[500001];
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
    }

    for (int j = 1; j <= n; j++) {
        if (a[j] == 0) continue;
        for (int i = j; i <= n; i += j) {
            c[i] += (long long)mu[i / j] * a[j];
        }
    }

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (c[i] >= 0) ans += c[i];
        else ans -= c[i];
    }

    cout << ans << endl;
    return 0;
}
