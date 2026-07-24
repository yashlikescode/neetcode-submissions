class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowlist;
        set<int> collist;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]==0){
                    rowlist.insert(i);
                    collist.insert(j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
            {
                if(rowlist.contains(i) || collist.contains(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
