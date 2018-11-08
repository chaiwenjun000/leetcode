// 861.cpp

// 水体，贪心策略即可。 先横向翻转保证最高位为1，接着纵向翻转，统计纵向1的个数。
// 这两种翻转互不影响，都向权值最大化前进
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        
        int ans = 0;
        for(int i=0;i<A.size();i++){
            if(A[i][0] == 0){
                for(int j=0;j<A[i].size();j++)
                    A[i][j] = !A[i][j];
            }
            
        }
        for(int i=0;i<A[0].size();i++){
            int cnt0 = 0;
            int cnt1 = 0;
            for(int j=0;j<A.size();j++){
                cnt0 += A[j][i] == 0;
                cnt1 += A[j][i] == 1;
            }
            if(cnt0 > cnt1){
                 for(int j=0;j<A.size();j++){
                     A[j][i] = ! A[j][i];
                 }
            }
        }
        int sum = 0;
        for(int i=0;i<A.size();i++){
            int mi = A[0].size()-1;
            for(int j=0;j<A[0].size();j++){
                sum += pow(2,mi) * A[i][j];
                mi--;
            }
        }
        return sum;
    }
};