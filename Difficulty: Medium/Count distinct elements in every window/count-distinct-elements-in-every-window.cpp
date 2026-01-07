class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<k;++i)
        {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());
        int count=freq.size();
        for(int i=k;i<arr.size();++i)
        {
            
            if(freq[arr[i-k]]==1)
            {
                count--;
            }
            freq[arr[i-k]]--;
            if(freq.find(arr[i])==freq.end() || freq[arr[i]]==0)
            {
                count++;
            }
            freq[arr[i]]++;
            ans.push_back(count);
        }
        return ans;
    }
};