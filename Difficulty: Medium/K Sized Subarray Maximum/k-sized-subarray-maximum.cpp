class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            while(!dq.empty() && dq.back() < arr[i])
                dq.pop_back();
            dq.push_back(arr[i]);
            if(i >= k - 1)
            {
                if((i != k - 1) && dq.front() == arr[i - k])
                {
                    dq.pop_front();
                }
                ans.push_back(dq.front());
            }
        }
        return ans;
    }
};