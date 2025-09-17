class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;
        
        for(int i=n-2;i>=0;--i)
        {
            st.push(arr[i]);
        }
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;--i)
        {
            while(st.size()>0 && st.top()<=arr[i])
            {
                st.pop();
            }
            if(st.size()!=0)
            {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        
        return ans;
    }
};