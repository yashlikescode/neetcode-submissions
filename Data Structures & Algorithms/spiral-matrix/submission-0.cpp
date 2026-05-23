class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int count = 0;
        vector<int> res;
        for (int i = 0; i < min((col + 1) / 2, (row + 1) / 2); i++) {

            if (count > total) {
                break;
            }
            for (int j = i; j < col - i; j++) {
                count++;
                if (count > total) {
                    break;
                }
                res.push_back(matrix[i][j]);
                cout << matrix[i][j] << " " << endl;
            }

            cout << "first row" << endl;
            int curj = col - 1 - i;
            int curi = i;
            for (int k = i + 1; k < row - i; k++) {
                count++;
                if (count > total) {
                    break;
                }
                res.push_back(matrix[k][curj]);
                cout << matrix[k][curj] << " " << endl;
            }
            cout << "last column" << endl;
            curi = row - 1 - i;
            curj = col - 1 - i;
            if (curi > i) {
                for (int j = col - 2 - i; j >= i; j--) {
                count++;
                if (count > total) {
                    break;
                }
                    res.push_back(matrix[row - 1 - i][j]);
                    cout << matrix[row - 1 - i][j] << " " << endl;
                }
            }
            cout << "bottom row" << endl;
            curi = row - i - 1;
            curj = i;
            if (curi > i) {
                for (int k = row - i - 2; k > i; k--) {
                count++;
                if (count > total) {
                    break;
                }
                    res.push_back(matrix[k][curj]);
                    cout << matrix[k][i] << " " << endl;
                }
            }
            cout << "first column" << endl;
        }
        return res;
    }
};
