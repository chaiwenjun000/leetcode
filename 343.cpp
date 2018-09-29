

class Solution {
public:
    int integerBreak(int n) {
        int l = 2;
        int r = n/2;
        if(r < l) r++;
        long long maxx = 1;
        for(int i=l;i<=r;i++){
            long long tmp = n / i;
            long long tmpmax = 1;
            for(int j=0;j<i-1;j++){
                tmpmax *= tmp;
            }
            if(n % i == 0){
                  tmpmax *=tmp;
            }else{
                tmpmax *= (tmp + n % i);
            }
            maxx = max(maxx,tmpmax);
            int rear =  n % i;
            if(rear){
                tmp = n / i + 1;
                tmpmax = 1;
                for(int j=0;j<rear;j++){
                    tmpmax *= tmp;
                }
                for(int j=0;j<i - rear;j++){
                    tmpmax *= (n/i);
                }
                maxx = max(maxx,tmpmax);
                
            }
            
        }
        return maxx;
        
    }
};