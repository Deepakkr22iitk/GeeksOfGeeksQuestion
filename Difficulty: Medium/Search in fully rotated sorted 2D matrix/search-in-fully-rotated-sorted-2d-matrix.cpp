class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int row=mid/m,col=mid%m;
            int midVal = mat[row][col];
            if (midVal == x) return true;
            int lowVal = mat[low / m][low % m];
            int highVal = mat[high / m][high % m];

            if (lowVal <= midVal) {
                if (x >= lowVal && x < midVal) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (x > midVal && x <= highVal) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
