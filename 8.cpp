/*

复杂模拟，错了好多次。

atoi;

自动清除各种干扰项，边界数据，返回正确的数字。


 */

#include<iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int len = str.length();
        int num_found = 0;
        int st = -1;
        for(int i=0;i<len;i++){
            if((str[i] >='0' && str[i] <='9') || str[i] == '+' || str[i] == '-' ){
                if(str[i] == '0'){
                    int j = i+1;
                    for(;j<len;j++){
                        if(str[j] != '0')
                            break;
                    }
                    st = j-1;
                    break;
                }
                st = i;
                break;
            }
            if(str[i] != ' ' && str[i] != '+' && str[i] != '-'){
                return 0;
            }
        }
        if(st == -1)
            return 0;
        //cout<<st<<endl;
        if(str[st]>='0' && str[st] <='9' ){
            string num = "";
            for(int i=st;i<len;i++){
                if(str[i] >='0' && str[i]<='9')
                    num += str[i];
                else
                    break;
            }
            //cout<<num<<endl;
            long long ans = matoi(1,num);
             // cout<<ans<<" hh"<<endl;
            return ans;
        }else{
            string num = "";
            for(int i=st+1;i<len;i++){
                if(str[i] >='0' && str[i]<='9')
                    num += str[i];
                else
                    break;
            }
            if(num == "") return 0;
            int type = 1;
            int ans ;
            if(str[st] == '-'){
                type = 2;
                ans = matoi(type,num);
                ans = -ans;
            }
            else{
                ans = matoi(type,num);
            }

            //cout<<ans<<" hh"<<endl;
            return ans;
        }
    }
    long long matoi(int type,string tmp){
        long long  mmax;
        if(type == 1){ // 正数
            mmax = (((long long )1<<31)-1);
        }else{
            mmax =( (long long )1<<31);
        }

        int len = tmp.length();
        int i;
        for(i=0;i<len;i++){
            if(tmp[i] != '0')
                break;    
        }
        if(i == len) i--;
        //cout<<"i"<<i<<endl;
        tmp = tmp.substr(i,len - i);
        //cout<<tmp<<endl;
        len = tmp.length();
        if(len >10 )
            return mmax;
        else{
            long long ans = 0;
            long long cur = 1;
            for(int i=len-1;i>=0;i--){
                ans += (tmp[i]- '0') * cur;
                cur*=10;
            }
            //cout<<"ff"<<endl;
            //cout<<ans<<endl;
            //cout<<mmax<<endl;
            return min(ans, mmax);
        }
    }
};

int main(){
    Solution so;
    cout<<so.myAtoi("+")<<endl;
    return 0;
}