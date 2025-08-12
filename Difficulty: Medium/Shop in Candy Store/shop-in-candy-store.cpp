class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int n=prices.size();
        sort(prices.begin(),prices.end());
        if(n<=(k+1)) return{prices[0],prices[n-1]};
        int mini=0,maxi=0;
        
        int least = (n/(k+1));
        int more=(n-(least*(k+1)));
        int ans=0;
        for(int i=0;i<least;++i)
        {
            mini+=prices[i];
            maxi+=prices[n-1-i];
        }
        if(more)
        {
            mini+=prices[least];
            maxi+=prices[n-1-least];
        }
        
        // cout<<n<<"\n";
        // for(int i=0;i<n;++i)
        // {
        //     cout<<prices[i]<<" ";
        // }
        // cout<<"\n";
        return {mini,maxi};
    }
};