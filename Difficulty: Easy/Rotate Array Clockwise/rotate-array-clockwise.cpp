class Solution {
  public:
    void rotateclockwise(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans(n,0);
        k%=n;
        
        int ind=0;
        while(ind<n)
        {
            ans[ind]=arr[(n-k+ind)%n];
            ind++;
        }
        arr=ans;
        return ;
    }
};
