class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        int n=arr.size();
        
        vector<int> ans;
        set<int> st;
        for(auto it:arr)
        {
            st.insert(it);
        }
        
        for(int i=low;i<=high;++i)
        {
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};