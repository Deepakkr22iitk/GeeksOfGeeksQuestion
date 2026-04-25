class Solution {
  public:
    bool sameValue(int a, int b){
        return abs(a) == abs(b);
    }
    bool oppositeSign(int a, int b){
        return (a < 0 && b > 0) || (a > 0 && b < 0);
    }
    vector<int> reducePairs(vector<int>& arr) {
        
        vector<int> stk;
        
        for(int i=0; i<arr.size(); i++){
            bool fl = true;
            while(!stk.empty() && oppositeSign(stk.back(), arr[i])){
                if(sameValue(stk.back(), arr[i])){
                    stk.pop_back();
                    fl = false;
                    break;
                }else if(!sameValue(stk.back(), arr[i])){
                    int top = stk.back();
                    stk.pop_back();
                    if(abs(top) > abs(arr[i])) arr[i] = top;
                }
            }
            if(fl) stk.push_back(arr[i]);
        }
        
        return stk;
    }
};