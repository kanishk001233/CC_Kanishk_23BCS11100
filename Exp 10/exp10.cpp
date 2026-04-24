class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> arr;
        
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});
        
        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }
    
    void mergeSort(vector<pair<int,int>>& arr, int l, int r, vector<int>& ans) {
        if(l >= r) return;
        
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid + 1, r, ans);
        merge(arr, l, mid, r, ans);
    }
    
    void merge(vector<pair<int,int>>& arr, int l, int mid, int r, vector<int>& ans) {
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1;
        int rightCount = 0;
        
        while(i <= mid && j <= r) {
            if(arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightCount++;
                j++;
            } else {
                ans[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }
        
        while(i <= mid) {
            ans[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= r) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k = l; k <= r; k++)
            arr[k] = temp[k - l];
    }
};
