class Solution {
  public:
    bool find(vector<int>&arr , int x){
          int n =arr.size();
          
          int l =0;
          int r= n-1;
          
          while (l<=r){
                 int mid = l+(r-l)/2;
                 if(arr[mid]==x) return true;
                 
                 else if (arr[mid]<x){
                      l=mid+1;
                 }else{
                      r= mid-1;
                 }
          }
          return false;
    }
    int binarySearchable(vector<int>& arr) {
        int ans =0;
         for(int i:arr){
               if(find(arr,i)) ans++;
         }
         return ans;
    }
};