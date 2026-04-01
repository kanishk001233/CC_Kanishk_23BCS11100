#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;
        int same = 1;
        int maxPoints = 0;

        for (int j = i + 1; j < n; j++) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];

            if (x1 == x2 && y1 == y2) {
                same++;
            } else {
                int dx = x2 - x1;
                int dy = y2 - y1;

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                mp[{dx, dy}]++;
                maxPoints = max(maxPoints, mp[{dx, dy}]);
            }
        }

        result = max(result, maxPoints + same);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << maxPoints(points) << endl;

    return 0;
}
