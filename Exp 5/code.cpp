#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const ll base = 31;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<ll> st;
    vector<ll> power(1000006);
    power[0] = 1;

    for(int i = 1; i < 1000006; i++)
        power[i] = (power[i-1] * base) % mod;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        ll hash = 0;
        for(int j = 0; j < s.size(); j++)
            hash = (hash + (s[j] - 'a' + 1) * power[j]) % mod;

        st.insert(hash);
    }

    while(m--){
        string s;
        cin >> s;

        ll hash = 0;
        for(int j = 0; j < s.size(); j++)
            hash = (hash + (s[j] - 'a' + 1) * power[j]) % mod;

        bool found = false;

        for(int i = 0; i < s.size() && !found; i++){
            ll original = (s[i] - 'a' + 1);

            for(char c = 'a'; c <= 'c'; c++){
                if(c == s[i]) continue;

                ll newHash = hash;
                newHash = (newHash - original * power[i] % mod + mod) % mod;
                newHash = (newHash + (c - 'a' + 1) * power[i]) % mod;

                if(st.count(newHash)){
                    found = true;
                    break;
                }
            }
        }

        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}
