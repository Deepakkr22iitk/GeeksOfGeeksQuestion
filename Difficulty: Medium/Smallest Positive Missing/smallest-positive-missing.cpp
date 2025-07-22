class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        unordered_map<int,int> mp;
        for(auto it:arr){
            if(it>0 && mp.find(it)==mp.end())
            {
                mp[it]+=1;
            }
        }
        
        int ans =1;
        while(mp.find(ans)!=mp.end())
        {
            ans++;
        }
        return ans;
    }
};