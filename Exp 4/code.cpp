#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    const long long mod = 1000000007;
    long long n = A.size();
    long long ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] & (1LL << bit))
                count1++;
        }

        long long count0 = n - count1;
        ans = (ans + (2LL * count1 % mod * count0 % mod) % mod) % mod;
    }

    return (int)ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << solve(A);

    return 0;
}
