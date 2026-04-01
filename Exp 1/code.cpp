#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    long long res = 0;
    long long coeff = 1;

    for (int i = 0; i < n; i++) {
        res = (res + coeff * nums[i]) % 10;
        coeff = coeff * (n - 1 - i) / (i + 1);
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << triangularSum(nums) << endl;

    return 0;
}
