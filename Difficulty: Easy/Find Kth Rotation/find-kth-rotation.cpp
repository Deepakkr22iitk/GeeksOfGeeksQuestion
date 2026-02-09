class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        if(arr[n-1]>arr[0] || n==1) return 0;
        
        // int ind=1;
        // while(ind<n && arr[ind-1]<arr[ind]) ind++;
        // return ind;
        
        if(arr[0]>arr[1]) return 1;
        int low=0,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid+1;
            if(arr[mid+1]>arr[mid] && arr[mid]<arr[0]) 
            {
                high=mid-1;
            }
            else low=mid+1;
        }
    }
};
