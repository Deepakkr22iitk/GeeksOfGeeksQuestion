class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                pq.push(j);
            }
        }
        while(k-- >1)
        {
            pq.pop();
        }
        return pq.top();
    }
};