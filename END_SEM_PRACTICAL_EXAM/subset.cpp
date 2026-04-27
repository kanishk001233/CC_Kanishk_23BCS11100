class Solution {
  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    set<vector<int>> st;

    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }

        st.insert(subset);
    }

    return vector<vector<int>>(st.begin(), st.end());
    }
};
