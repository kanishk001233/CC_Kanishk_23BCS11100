#include <iostream>
#include <algorithm>
using namespace std;


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long low = 1;
    long long high = N * min(A, B);

    long long lcm = (A * B) / gcd(A, B);

    while (low < high) {
        long long mid = (low + high) / 2;

        long long count = mid / A + mid / B - mid / lcm;

        if (count < N)
            low = mid + 1;
        else
            high = mid;
    }

    cout << low;
    return 0;
}
