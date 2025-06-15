class Solution {
  public:
    int pred(vector<int> &arr,int div)
    {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=(arr[i]+div-1)/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1,high=1e6;
        int ans=1e6;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(pred(arr,mid)<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
