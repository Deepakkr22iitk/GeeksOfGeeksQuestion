class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n=arr.size();
        int ans=0; int i=0; int j=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};