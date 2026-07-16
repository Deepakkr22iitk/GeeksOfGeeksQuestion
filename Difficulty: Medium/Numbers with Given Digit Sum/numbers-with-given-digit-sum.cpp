class Solution {
  public:
    // set<string> st;
    // void fun(int id,string s,int cur,int n,int sum){
    //     if(id==n){
    //         if(cur==sum)st.insert(s);
    //         return;
    //     }
    //     for(int i=0;i<=9;i++){
    //         if( id==0 && i==0 ){
    //             continue;
    //         }
    //         if(cur+i<=sum){
    //             s.push_back(i+'0');
    //             fun(id+1,s,cur+i,n,sum);
    //             s.pop_back();
    //         }
    //     }
    //     return;
    // }
    
    int fun(int id,int cur,int n,int sum,vector<vector<int>>&dp){
        if(id==n){
            if(cur==sum){
                return 1;
            }
            return 0;
        }
        
        if( dp[id][cur] != -1 ){
            return dp[id][cur];
        }
        
        int ans=0;
        for(int i=0;i<=9;i++){
            if( id==0 && i==0 ){
                continue;
            }
            if(cur+i<=sum){
                int c=fun(id+1,cur+i,n,sum,dp);
                ans+=c;
            }
        }
        return dp[id][cur]=ans;
    }
    int countWays(int n, int sum) {
        // code here
        //fun(0,"",0,n,sum);
        //dp
        vector< vector<int> > dp(n,vector<int>(sum+1,-1));
        int ans=fun(0,0,n,sum,dp);
        if( ans == 0 ) return -1;
        return ans;
        // if(st.size()==0){
        //     return -1;
        // }
        // return (int)st.size();
    }
};