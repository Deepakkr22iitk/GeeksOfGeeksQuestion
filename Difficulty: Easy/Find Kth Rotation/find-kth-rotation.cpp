class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        if(arr[n-1]>arr[0] || n==1) return 0;
        int ind=1;
        while(ind<n && arr[ind-1]<arr[ind]) ind++;
        return ind;
    }
};
