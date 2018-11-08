/*
简单 bfs。

注意只能往右往下。

第一次错是因为往上往左也考虑了，得出了更小的步数 - - 。

 */
class Solution {
public:
    struct node{
        int x,y,step;
        node(){
            x = 0;y = 0;step = 0;
        }
        node(int x,int y,int step){
            this->x = x;
            this->y = y;
            this->step = step;
        }
        bool operator < (const node & t) const{
           return step > t.step;
        }
    };
    int minPathSum(vector<vector<int>>& grid) {
        //bfs
      
        int h = grid.size();
        if(h == 0) 
            return 0;
        int w = grid[0].size();
        int vis[h][w];
        memset(vis,0,sizeof vis);
        vis[0][0] = 1;
        int dx[4] = {1,0};
        int dy[4] = {0,1};
        priority_queue<node > Q ;
        map<node,node>mp;
        node st = node(0,0,grid[0][0]);
        mp[st] = node(0,0,-1);
        Q.push(node(0,0,grid[0][0]));
        int ans  = 0;
        while(!Q.empty()){
            node p = Q.top();
            Q.pop();
            if(p.x == h-1 && p.y == w-1)
            {
                ans = p.step;
                break;
            }    
            for(int i=0;i<2;i++){
                int nx = dx[i] +p.x;
                int ny = dy[i] + p.y;
              
                if(nx >=0 && nx < h && ny >=0 && ny < w){
                    int step = p.step + grid[nx][ny];
                    if(!vis[nx][ny]){
                        vis[nx][ny] = 1;
                        Q.push(node(nx,ny,step));
                       // mp[node(nx,ny,step)] = p;
                    }
                }
            }
          
            
        }
         /*
            node ed = node(h-1,w-1,ans);
            while(1){
                node tmp = mp[ed];
                cout<<tmp.x<<" "<<tmp.y<<" "<<tmp.step<<endl;
                ed = tmp;
                if(tmp.step == -1)
                    break;
            }
            */
            return ans;
        
    }
};