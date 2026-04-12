class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // int rowLength= mat.size();
        // int colLength = mat[0].size();
        // if(colLength==1 || rowLength==1) return true;
        // for(int i=0;i<rowLength;i++){
        //     for(int j=0;j<colLength;j++){
        //         if(i==j && mat[i][j]!=mat[0][0]) return false;
        //     }
        // }return true;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++){
                if(mat[i][j]!=mat[i+1][j+1])    return false;
            }
        }
        return true;
    }
};