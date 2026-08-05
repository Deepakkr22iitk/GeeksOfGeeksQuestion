class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        int n=arr.size();
        
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        
        for(int i=0;i<n;++i)
        {
            prefix[i]=(prefix[i-1]+arr[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;++i)
        {
            int low=i,high=n-1;
            int lowerIndex=-1;
            
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int subArraySum=prefix[mid]-prefix[i]+arr[i];
                
                if(subArraySum>=l)
                {
                    lowerIndex=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            
            if(lowerIndex!=-1)
            {
                int low=i,high=n-1;
                int higherIndex=-1;
                
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    int subArraySum=prefix[mid]-prefix[i]+arr[i];
                    
                    if(subArraySum<=r)
                    {
                        higherIndex=mid;
                        low=mid+1;
                    }
                    else high=mid-1;
                }
                
                if(higherIndex!=-1)
                {
                    ans+=higherIndex-lowerIndex+1;
                }
            }
        }
        return ans;
    }
};