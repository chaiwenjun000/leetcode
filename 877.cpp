// 动态规划
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int dp[555][555];
        for(int i=0;i<piles.size();i++) dp[i][i] = piles[i];
        int sz = piles.size();
        int gap = 1;
        while(gap <=sz){
          for(int i=0;i<sz-gap;i++){
            dp[i][i+gap] = max(piles[i] - dp[i+1][i+gap],piles[i+gap] - dp[i][i+gap-1]);
            }  
            gap++;
        }
        return dp[0][sz-1];
    }
};