class Solution {
  public:
    int distinctSubseq(string &str) {
        int ans=1,m=1e9+7;
        int mp[26]={0};
        for(char c:str){
            int repeating_seq = mp[c-'a'];  
            mp[c-'a']=ans;               
            ans=(1LL*ans*2 - repeating_seq+m)%m;  
        }
        return ans;
    }
};