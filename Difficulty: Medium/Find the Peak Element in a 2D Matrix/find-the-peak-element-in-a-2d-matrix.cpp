class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        /*
             logic : 
             1. find mid of matrix column wise  mid =  start+end /2 
             2. check peak value in mid column 
             3. check left and right column`s value is it large shift 
             to that column  other wise peak is at mid colum value 
             
        */
        int row = mat.size();
        int col = mat[0].size();
        int start=0 , end = col-1;
        while(start<=end)
        {
            int mid =(start+end)/2;     
            // find max in row 
            int max = 0;
            for(int i =0;i<row;i++)
            {
                if(mat[i][mid]>mat[max][mid])
                {
                    max=i;
                }
            }
            int current = mat[max][mid];
            int left = (mid>0)? mat[max][mid-1]:INT_MIN;
            int right = (mid<col-1)? mat[max][mid+1]:INT_MIN;
            
            if(left>current)
            {
                end= mid-1;
            }
            else if(right >current)
            {
                start = mid+1;
            }
            else
            {
                return {max,mid};
            }
        }
       return {-1,-1};
    }
};
