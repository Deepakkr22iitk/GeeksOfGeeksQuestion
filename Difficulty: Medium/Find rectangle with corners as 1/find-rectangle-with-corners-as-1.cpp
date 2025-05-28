class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                cnt=0;
                for(int k = 0;k<m;k++){
                    if((mat[i][k] & mat[j][k]) == 1){
                        cnt++;
                    }
                    if(cnt>=2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};