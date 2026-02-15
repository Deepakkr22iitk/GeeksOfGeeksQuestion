class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size();
        sort(a.begin(), a.end());
        if(m == 1) return 0;
        else {
            int ans = INT_MAX;
            for(int i=0; i<n-m+1; i++){
                if((a[i+m-1]-a[i])<ans) ans = (a[i+m-1]-a[i]);
            }
            return ans;
        }
    }
};