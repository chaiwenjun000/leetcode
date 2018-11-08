#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    if(a[0] == b[0]){
        return (a[1] - a[0]) < (b[1] - b[0]);
    }
    return a[0] < b[0];
}

// 排序法， 贪心，先按照后面的升序排序，如果后面相同，前面的升序排序。然后遍历一遍
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0) return 0;
        sort(pairs.begin(),pairs.end(),cmp);
        int pre = -99999999;
        int cnt = 0;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0] > pre){
                cnt++;
                pre = pairs[i][1];
            }
        }
        return cnt;
    }
};

// dp  lis
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0) return 0;
        sort(pairs.begin(),pairs.end(),cmp);
        int dp[1010];
        memset(dp,0,sizeof dp);
        for(int i=0;i<pairs.size();i++) dp[i] = 1;
        int maxx = 1;
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = dp[j]+1;
                }
            }
            maxx = max(maxx,dp[i]);
        }
        return maxx;
    }
};
int main(){

    vector<vector<int> >pairs;
    vector<int> a ;

    a.push_back(3);
    a.push_back(4);
    vector<int> b ;

    b.push_back(1);
    b.push_back(3);

     vector<int> c ;

    c.push_back(1);
    c.push_back(2);

    pairs.push_back(a);
    pairs.push_back(b);
    pairs.push_back(c);

    sort(pairs.begin(),pairs.end(),cmp);
    for(int i=0;i<pairs.size();i++){
        for(int j=0;j<pairs[i].size();j++){
            cout<<pairs[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
