class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        int total=9*pow(10,n-1);
        int zero=0;
        int len=arr.size();
        for(int i=0;i<len;++i)
        {
            if(arr[i]==0) zero++;
        }
        int none=(9-(len-zero))*(pow(10-len,n-1));
        return total-none;
    }
};
