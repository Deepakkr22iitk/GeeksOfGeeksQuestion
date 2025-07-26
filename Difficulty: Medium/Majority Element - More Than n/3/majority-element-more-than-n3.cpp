class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        
        vector<int> ans;
        for(auto &it : freq)
        {
            if(it.second>n/3) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};