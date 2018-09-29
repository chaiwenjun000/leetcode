/*

求最短路径，显然想到了bfs。
终点是end
思路就是两种操作。
一种操作 复制当前剪贴板到当前数。如果超过了 end 则 跳过。
另一种操作 如果当前数cur大于剪贴板cp， 可以考虑复制，但必须end % cp == 0.

 */
class Solution {
public:
    struct node{
        int cur;
        int cp;
        int step;
        node(){}
        node(int cur,int cp,int step){
            this->cur = cur;
            this->cp = cp;
            this->step = step;
        }
    };
    int minSteps(int n) {
        if(n == 1) return 0;
        int ans = bfs(n);
        return ans;
    }
    int bfs(int end){
        queue<node>Q;
        Q.push(node(1,1,1));
        while(!Q.empty()){
            node now = Q.front(); Q.pop();
            if(now.cur == end) return now.step;
            for(int i=0;i<2;i++){
                if(i == 0){
                    now.cur += now.cp;
                    now.step++;
                    if(now.cur > end) continue;
                    Q.push(now);
                }else{
                    if(now.cur > now.cp){
                        now.cp = now.cur;
                        now.step++;
                        if(end % now.cp != 0) continue;
                        Q.push(now);
                    }
                }
            }
    
        }
        
        return -1;
    }
};

/*
简单dp.

 */
class Solution {
public:
  
    int minSteps(int n) {
        int dp[1001];
        dp[1] = 0;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = i;
            for(int j=2;j<i;j++){
                if(i % j == 0){
                    dp[i] = min(dp[i],dp[j] + i / j);
                }
            }
        }
        return dp[n];
    }
   
};

/*优化的DP*/

class Solution {
public:
  
    int minSteps(int n) {
        int dp[1001];
        dp[1] = 0;
        dp[2] = 2;
        for(int i=3;i<=n;++i){
            dp[i] = i;
            for(int j=i/2;j>=2;--j){
                if(i % j == 0){
                    dp[i] = min(dp[i],dp[j] + i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
   
};

/*递归*/
class Solution {
public:
  
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};

/*

还有一个素数的dp方法，有点乱，贴上吧，没有完全看懂

如果n是质数的话，就要一个一个粘贴上去，次数就是n.
如果不是质数的话，由先由一个A获得n的最大公因子m为模版，在copy all,在paste n/m-1 次。
 */


class Solution {
public:
    int isprime(int n){
        int i;
        if(n==1) return 1;
        for(i=2;i<=sqrt(n);i++)
            if(n%i==0) return i;
        return -1;
    }
    int minSteps(int n) {
        int dp[11001]={0};
        if(isprime(n)==-1)
           return n;
        for(int i=2;i<=n;i++)
            if(isprime(i)==-1)
               dp[i]=i;
            else
               dp[i]=dp[i/isprime(i)]+isprime(i);
        return dp[n];
    }
};
