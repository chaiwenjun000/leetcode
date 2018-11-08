// 水题
class Solution {
public:
    int minAddToMakeValid(string S) {
        int len = S.length();
        int ans = 0;
        int l = 0;
        for(int i=0;i<len;i++){
            if(S[i] == '('){
                l++;
            }else if(S[i] == ')'){
                if(l == 0)
                    ans++;
                else
                    l--;
            }
        }
        ans += l;
        return ans;
    }
};