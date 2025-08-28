class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0,end=0;
        int count=0,res=0;
        while(end<n)
        {
            if(arr[end]==0) count++;
            
            while(count>k)
            {
                if(arr[start]==0) count--;
                start++;
            }
            
            res=max(res,end-start+1);
            end++;
        }
        return res;
    }
};
