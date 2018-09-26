// 动态规划
// 很明显是dp 每个状态都与前一个状态相关，如果当前没有持有股票，可以是上一个没持有的延续，或者上一个持有+现在卖出。
// 如果当前持有股票，也是同理。
// 初始状态，0位置持有，-prices[0]
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int mx = 50000 + 5;
        int unhold[mx],hold[mx];
        //memset(unhold,0,sizeof unhold);
        //memset(hold,0,sizeof hold);
        int sz = prices.size();
        hold[0] = -prices[0];
        for(int i=1;i<sz;i++){
            hold[i] = max(hold[i-1],unhold[i-1] - prices[i]);
            unhold[i] = max(unhold[i-1],hold[i-1] + prices[i] -fee);
        }
        return unhold[sz-1];
    }
};