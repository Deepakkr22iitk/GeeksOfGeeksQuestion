class Solution {
  public:
    int maxIndexDifference(string &s) {
        int max_index = 0;
        int n = s.length();
        int first_index_a = -1;
        vector<int>first_index(26,-1);
        int index=0;
        for(char ch='a';ch<='z';ch++){
            for(int i=index;i<n;i++){
                if(s[i]==ch){
                    first_index[ch-'a']=i;
                    index=i;
                    break;
                }
            }
        }
        if(first_index[0]==-1) return -1;
        int max_last_ch_index = first_index[0];
        for(char ch='b';ch<='z';ch++){
            int index =-1;
            for(int i=n-1;i>=0;i--){
                if(s[i]==ch){
                    max_index = max(max_index,i);
                    index =i;
                    break;
                }
            }
            if(first_index[ch-'a']<first_index[ch-'a'-1]){
                 return max(0,max_last_ch_index-first_index[0]);
            }
            
            if(index==-1 ) break;
            max_last_ch_index = max_index;
        }
        return max(0,max_index-first_index[0]);
    }
};
