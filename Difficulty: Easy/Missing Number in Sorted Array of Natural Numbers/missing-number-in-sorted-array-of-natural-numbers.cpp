class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        
        if(arr[0]>1) return 1;
        
        int n=arr.size();
        int start=0,end=n-1;
        
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[mid]==(mid+1)) 
            {
                start=mid+1;
                ans=start+1;
            }
            else end=mid-1;
        }
        
        return ans;
    }
};