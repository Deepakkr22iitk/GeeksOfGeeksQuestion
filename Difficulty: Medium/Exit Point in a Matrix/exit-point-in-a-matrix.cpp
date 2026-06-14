class Solution {
  public:
    int n;
    int m;
    
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    
    bool check(int i,int j){
        return i<n && j<m && i>=0 && j>=0;
    }
    
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        m = mat[0].size();
        int k = 0; // direction
        int i=0;
        int j=0;
        
        while(true){
            
            if(mat[i][j]==0){
                
                if(check(i+row[k],j+col[k])){
                    i = i+row[k];
                    j = j+col[k];
                }
                else return {i,j};
                
            }
            else{ // change direction
                
                mat[i][j] = 0;
                k = ((k+1) % 4);
                
                if(check(i+row[k],j+col[k])){
                    i = i+row[k];
                    j = j+col[k];
                }
                else return {i,j};
                
            }
        }
        
        return {0,0};
    }
};