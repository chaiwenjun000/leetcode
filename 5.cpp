 #include<iostream>
using namespace std;
// 暴力做法
 string longestPalindrome(string s) {
        // n ^ 2
        if(s.length() == 0) return "";
        int len = s.length();
        int maxx = 1;
        string maxstring = s.substr(0,1);
        for(int i=0;i<len;i++){
            int curx = i-1;
            int cury = i+1;
            int tmpcnt = 1;
            while(curx >=0 && cury < len){
                if(s[curx] != s[cury] )
                    break;
                tmpcnt+=2;
                if(tmpcnt > maxx){
                    maxx = tmpcnt;
                    maxstring = s.substr(curx,cury - curx +1);
                }
                curx--;
                cury++;
            }

            curx = i;
            cury = i+1;
            tmpcnt = 0;
            while(curx >=0 && cury < len){
                if(s[curx] != s[cury] )
                    break;
                tmpcnt+=2;
                if(tmpcnt > maxx){
                    maxx = tmpcnt;
                    maxstring = s.substr(curx,cury - curx +1);
                }
                curx--;
                cury++;
            }
        }

        return maxstring;
}

// dp solution
class Solution {
public:
    string longestPalindrome(string s) {
       
        int len  = s.length();
        if(len == 0) return "";
         int dp[1010][1010];
        for(int i=0;i<len;i++)
            for(int j = 0;j<len;j++)
                dp[i][j] = 0;
        int maxlen = 1;
        int l  = 0;
        for(int le=0;le<len;le++){
                    
            for(int j=0;j<len-le;j++){
                if(le == 0){
                    dp[j][j] = 1;
                }else if(le == 1 && (s[j] == s[j+le])){
                    dp[j][j+le] = dp[j][j];
                }else if(le !=1 && (s[j] == s[j+le])){
                    dp[j][j+le] = dp[j+1][j+le-1];
                }else{
                    dp[j][j+le] = 0;
                }
                if(dp[j][j+le] && le+1 >= maxlen){
                    l = j;
                    maxlen = le+1;
                }
            }
        }
        
        return s.substr(l,maxlen);

    }
};
int main(){
    string ans = longestPalindrome("ababa");
    cout<<ans<<endl;
}