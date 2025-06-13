class Solution {
  public:
    bool possible(vector<int> &arr,int n, int k,int mid){
        int temp=k;
        for(int i=0;i<n;i++){
            int quant = arr[i]/mid;
            int rem = arr[i]%mid;
            
            if(quant ==0)   temp-=1;
            else{
                if(rem!=0)
                    temp -= (quant+1);
                else{
                    temp -= quant;
                }
            }
            if(temp<0)
                return false;
        }
        return true;
        
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int end = *max_element(arr.begin(),arr.end());
        int n = arr.size();
        int start = 1;
        int ans=-1;
        
        while(start<=end){
            int mid = start+ (end-start)/2;
            if(possible(arr,n,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};