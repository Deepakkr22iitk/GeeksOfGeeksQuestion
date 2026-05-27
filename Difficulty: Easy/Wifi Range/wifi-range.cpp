class Solution {
  public:
    bool wifiRange(string &s, int x) {
        map<int,int>mpp;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')continue;
            mpp[fmax(i-x, 0)]++;
            mpp[i+x+1]--;
        }
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            sum+=mpp[i];
            if(!sum)return false;
        }
        return true;
    }
};