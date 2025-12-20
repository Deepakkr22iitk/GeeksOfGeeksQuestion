class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int n=arr.size();
        if(k<=arr[0]) return 0;
        if(k>arr[n-1]) return n;
        int low=0,high=n,flag=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==k)
            {
                flag=1;
                return mid;
            }
            if(arr[mid]>k) high=mid-1;
            else low=mid+1;
        }
        // if(flag==0)
        // {
        //     // if(arr[high]==k) return high;
        //     // else high+1;
            
        // }
        return high+1;
    }
};