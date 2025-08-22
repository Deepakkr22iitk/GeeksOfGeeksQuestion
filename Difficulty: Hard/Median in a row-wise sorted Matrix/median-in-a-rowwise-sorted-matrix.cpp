class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int minVal=INT_MAX, maxVal=INT_MIN;
  
        // finding the minimum and maximum elements
        // in the matrix
        for(int i = 0;i<n;i++) {
            if (mat[i][0]<minVal)
                minVal=mat[i][0];
            if (mat[i][m-1]>maxVal)
                maxVal=mat[i][m-1];
        }
        
        int desired=(n*m+1)/2;
    	int low=minVal, high=maxVal;
        while (low<high) {
            int mid=low+(high-low)/2;
            int place=0;
    
            // count elements smaller than or equal to mid
            for (int i=0;i<n;++i)
                place+=upper_bound(mat[i].begin(),mat[i].end(),mid)
                         -mat[i].begin();
            
            // adjust the range based on the count of 
            // elements found
            if (place<desired)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
