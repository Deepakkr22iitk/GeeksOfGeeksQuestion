// User function template for C++
class Solution {
  public:
    int lowerbound(vector<int> v, int len, int x)
    {
        int ans=len,low=0,high=len-1;
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            if(v[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;
        }
        return len-ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(lowerbound(arr[i],m,1)>mx)
            {
                mx=lowerbound(arr[i],m,1);
                ans=i;
            }
        }
        return ans;
    }
};