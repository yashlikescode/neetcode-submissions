class Solution {
public:
    void dfs(int nrows, int ncols, int x, int y, vector<vector<int>>& heights, set<pair<int,int>>& allowed, int prevHeight){
        cout<<"Tested: "<<x<<" "<<y<<endl;
        pair<int,int> p(x,y);
        if(x < 0 || y < 0 || allowed.count(p)>0 || x >= nrows || y >= ncols || heights[x][y] < prevHeight){
            return;
        }
        allowed.insert(p);
        dfs(nrows, ncols, x+1, y, heights, allowed, heights[x][y]);
        dfs(nrows, ncols, x-1, y, heights, allowed, heights[x][y]);
        dfs(nrows, ncols, x, y+1, heights, allowed, heights[x][y]);
        dfs(nrows, ncols, x, y-1, heights, allowed, heights[x][y]);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int nrows = heights.size();
        int ncols = heights[0].size();
        set<pair<int,int>> pac;
        set<pair<int,int>> atl;
        for(int i = 0; i < nrows; i++){
            dfs(nrows,ncols,i,0,heights,pac, heights[i][0]);
            dfs(nrows,ncols,i,ncols-1,heights,atl, heights[i][ncols-1]);
        }
        for(int i = 0; i < ncols; i++){
            dfs(nrows,ncols,0,i,heights,pac, heights[0][i]);
            dfs(nrows,ncols,nrows-1,i,heights,atl, heights[nrows-1][i]);
        }
        vector<vector<int>> res;
        for(int i = 0; i < nrows; i++){
            for(int j = 0; j < ncols; j++){
                pair<int, int> p;
                p.first = i;
                p.second = j;
                vector<int> r = {i,j};
                if(pac.count(p)>0 && atl.count(p)>0){
                    res.push_back(r);
                }
            }
        }
        return res;

    }
};