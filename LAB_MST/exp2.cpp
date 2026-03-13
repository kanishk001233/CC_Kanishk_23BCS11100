#include<iostream>
#include<vector>
using namespace std;
int check(vector<int> nums){
    int ans=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int x:nums){
            if((x>>i)&1){
                count++;
            }
        }
        if(count%3){
            ans|=(1<<i);
        }
    }
    return ans;
} 
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=check(nums);
    cout<<ans<<endl;
    return 0;
}
