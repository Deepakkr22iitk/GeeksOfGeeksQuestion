class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int count=0,idx=0;
        while(idx<arr.size())
        {
            if(arr[idx]==0) count++;
            else arr[idx-count]=arr[idx];
            idx++;
        }
        while(count>0)
        {
            arr[idx-count]=0;
            count--;
        }
        return ;
    }
};