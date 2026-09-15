class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n=arr.size();
        
        sort(arr.begin(), arr.begin() + n / 2);
        sort(arr.begin() + n / 2, arr.end());
        
        int i=0,j=n/2;
        int ans=0;
        while(j<n)
        {
            while(i<n/2 && arr[i]<(5*arr[j])) i++;
            ans+=(n/2-i);
            j++;
        }
        return ans;
    }
};