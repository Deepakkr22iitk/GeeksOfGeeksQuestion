class Solution {
  public:
    bool canmake(vector<int>&arr, int reqbuke, int reqflower, int day){
        int n=arr.size();
        int buke=0,flower=0;
        for(int bloom:arr){
            if(bloom<=day){
                flower++;
                if(flower==reqflower){
                    buke++;
                    flower=0;
                }
            }
            else flower=0;
        }
        return buke>=reqbuke;
        
    }
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        // sort(arr.begin(),arr.end());
        int low=INT_MAX,high=INT_MIN;
        int ans=-1;
        int n=arr.size();
        if(n<k*m){
            return ans;
        }
        for(auto it:arr){
            low=min(it,low);
            high=max(it,high);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canmake(arr,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};