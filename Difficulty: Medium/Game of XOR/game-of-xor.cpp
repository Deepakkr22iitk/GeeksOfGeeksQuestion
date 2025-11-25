class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=(i+1)*(n-i);
            //x denotes the number of subarrays A[i] will be part of
            x%=2;
            if(x)ans^=arr[i];
        }
        return ans;
    }
};