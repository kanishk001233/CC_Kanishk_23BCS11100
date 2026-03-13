#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int powertokens(vector<int> tokens, int power){
    sort(tokens.begin(), tokens.end());
    int ans=0, score=0;
    int l=0,r=tokens.size()-1;
    while(l<=r){
        if(power>=tokens[l]){
            score=score-tokens[l];
            ans=ans+1;
            l++;
        }
        else if(score>0){
            score=score+tokens[r];
            ans=ans-1;
            r--;
        }
        else{
            break;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> tokens(n);
    for(int i=0;i<n;i++){
        cin>>tokens[i];
    }
    int ans=powertokens(tokens,m);
    cout<<ans<<endl;
    return 0;
}
