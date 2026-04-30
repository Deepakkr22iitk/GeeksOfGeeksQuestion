class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n=arr.size();
        
        int idx=0;
        while(idx<n/2)
        {
            if(idx*2+1>=n) break;
            int left=arr[2*idx+1];
            if(left>arr[idx]) return false;
            
            if(idx*2+2>=n) break;
            int right=arr[2*idx+2];
            if(right>arr[idx]) return false;
            idx++;
        }
        return true;
    }
};
