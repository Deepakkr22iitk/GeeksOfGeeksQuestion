class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int min_diff = arr[n-1] - arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] < k) continue;
            int mini = min(arr[0] + k, arr[i] - k);
            int maxi = max(arr[n-1] - k, arr[i-1] + k);
            min_diff = min(min_diff, maxi - mini);
        }
        return min_diff;
    }
};