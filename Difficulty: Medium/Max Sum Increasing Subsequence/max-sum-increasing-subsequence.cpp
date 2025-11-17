class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>sum(n,0);
	    sum[n-1] = arr[n-1];
	    for(int i=n-2;i>=0;i--){
	        int sumi = arr[i];
	        int addi = 0;
	        for(int j = i+1;j<n;j++){
	            if(arr[j]>arr[i]){
	                addi = max(addi,sum[j]);
	            }
	        }
	        sum[i] = addi + sumi;
	    }
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++){
	        maxi = max(maxi,sum[i]);
	    }
	    return maxi;
    }
};