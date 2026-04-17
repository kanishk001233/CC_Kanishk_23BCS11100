class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int maxi=0;
            for(int ln=1;ln<=k && i-ln>=0;ln++){
                maxi=max(maxi,arr[i-ln]);
                dp[i]=max(dp[i],dp[i-ln]+maxi*ln);
            }
        }
        return dp[n];
    }
};
