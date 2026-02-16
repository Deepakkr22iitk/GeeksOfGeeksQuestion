class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-1;++i)
        {
            if(arr[i][1]>arr[i+1][0]) return false;
        }
        return true;
    }
};