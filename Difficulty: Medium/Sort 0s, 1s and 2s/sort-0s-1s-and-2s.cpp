class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        int idx=0;
        while(idx<=high)
        {
            if(arr[idx]==0)
            {
                swap(arr[idx],arr[low]);
                low++;
                idx++;
            }
            else if(arr[idx]==2)
            {
                swap(arr[idx],arr[high]);
                high--;
            }
            else idx++;
        }
        return ;
    }
};