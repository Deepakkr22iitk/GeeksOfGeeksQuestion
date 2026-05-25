class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(arr[i]>=start && arr[i]<=end) cnt++;
        }
        return cnt==(end-start+1);
    }
};
