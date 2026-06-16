class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> arr;
        int _xor = 0;
        for(int i = queries.size()-1;i>=0;i--){
            int ty = queries[i][0], x = queries[i][1];
            if(ty == 0){
                arr.push_back((_xor^x));
            }
            else{
                _xor ^= x;
            }
        }
        arr.push_back(_xor);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
