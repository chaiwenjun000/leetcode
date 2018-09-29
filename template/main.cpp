#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#define INF = 99999999
const int maxn = 222;
using namespace std;
typedef long long ll;
int mapp[maxn][maxn] 


ll pow_mod(ll x, ll n, ll mod){
    ll res = 1;
    x = x % mod;
    while(n){
        if(n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main(){

    cout<<pow_mod(4,2,4)<<endl;
    return 0;
}