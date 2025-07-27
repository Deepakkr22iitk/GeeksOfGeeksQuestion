class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        queue<int> r;
        queue<int> c;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    r.push(i);
                    c.push(j);
                }
            }
        }
        
        while(!r.empty()){
            for(int j=0; j<mat[0].size(); j++){
                mat[r.front()][j] = 0;
            }
            r.pop();
        }
        
        while(!c.empty()){
            for(int j=0; j<mat.size(); j++){
                mat[j][c.front()] = 0;
            }
            c.pop();
        }
    }
};