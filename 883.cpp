// 水体，水水更健康
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int szw = grid.size();
        int szn = grid[0].size();
        
        for(int i=0;i<szw;i++){
    
            int maxx = grid[i][0];
            for(int j=0;j<szn;j++){
                if(grid[i][j] > 0) cnt1++;
                if(grid[i][j] > maxx) maxx = grid[i][j];
            }
            cnt2 += maxx;
        }   
        for(int i=0;i<szn;i++){
            int maxx = grid[0][i];
            for(int j=0;j<szw;j++){
                if(grid[j][i] > maxx) maxx = grid[j][i];
            }
            cnt3 += maxx;
        }
        
        return cnt1 + cnt2+ cnt3;
    }
};
int main(){

    vector<vector<int> >grid;

    vector<int>vt;
    vt.push_back(1);
    vt.push_back(2);
    grid.push_back(vt);
    cout<<grid[0][0]<<endl;
    return 0;
}
