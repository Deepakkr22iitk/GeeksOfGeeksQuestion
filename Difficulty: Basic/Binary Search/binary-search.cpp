class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0,end=n-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[mid]==k) return true;
            
            if(arr[mid]>k) end=mid-1;
            else start=mid+1;
        }
        
        return false;
    }
};