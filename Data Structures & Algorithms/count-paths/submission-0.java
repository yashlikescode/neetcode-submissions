class Solution {
    public int uniquePaths(int m, int n) {
        int[][] arr = new int[m][n];
        arr[m-1][n-1] = 1;
        int temp = 0;
        boolean first = true;
        for(int i = m-1; i > -1; i--){
            for(int j = n-1; j > -1; j--){
                if(first){
                    first = !first;
                    continue;
                }
                temp = 0;
                if(j+1<n){
                    temp += arr[i][j+1];
                }
                if(i+1<m){
                    temp += arr[i+1][j];
                }
                arr[i][j] = temp;
            }
        }
        return arr[0][0];
    }
}
