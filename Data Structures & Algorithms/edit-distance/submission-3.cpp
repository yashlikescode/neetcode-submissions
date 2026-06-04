class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> v(n1 + 1, vector<int>(n2 + 1, 100000));

        for(int i = 0; i < n1+1; i++){
            v[i][n2] = n1-i;
        }

        for(int i = 0; i < n2+1; i++){
            v[n1][i] = n2-i;
        }

        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    v[i][j] = v[i+1][j+1];
                } else {
                    v[i][j] = 1 + min(v[i+1][j+1], min(v[i][j+1],v[i+1][j]));
                }
            }
        }
        return v[0][0];
    }
};
