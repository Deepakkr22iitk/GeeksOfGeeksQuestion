class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int mini = arr[0] , maxi =arr[0] , ans = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            if(arr[i] < 0){
                swap(mini , maxi);
            }
            
            maxi = max(arr[i] , arr[i]*maxi);
            mini = min(arr[i] , arr[i]*mini);
            
            ans = max(ans , maxi);
        }
        
        return ans;
    }
};