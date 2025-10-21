class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int,int> freq;
        for(auto it:arr) freq[it]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto it:freq) pq.push({it.second,it.first});
        
        vector<int> ans;
        int i=k;
        while(!pq.empty())
        {
            if(i==0) break;
            ans.push_back(pq.top().second);
            pq.pop();
            i--;
        }
        
        return ans;
    }
};
