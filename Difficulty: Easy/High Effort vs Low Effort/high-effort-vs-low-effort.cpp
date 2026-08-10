class Solution {
  public:
    // int solve(vector<int> j,vector<int> k,int ind)
    // {
    //     int n=j.size();
    //     if(ind>=n) return 0;
        
    //     int karo=k[ind]+solve(j,k,ind+1);
    //     int nhi_karo=0;
    //     if(ind<n-1) nhi_karo=j[ind+1]+solve(j,k,ind+2);
        
    //     return max(karo,nhi_karo);
    // }
    int maxTask(vector<int>& h, vector<int>& l) {
        int n=h.size();
        
        // int ans=0;
        // ans=solve(h,l,0);
        // ans=max(ans,h[0]+solve(h,l,1));
        // return ans;
        
        int prev1=max(h[0],l[0]); // maximum tasks possible on day i-1
        int prev2=0; // maximum tasks possible on day i-2
        
        for(int i=1;i<n;++i)
        {
            int less=prev1+l[i];
            int more=prev2+h[i];
            
            int curr=max(less,more);
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};