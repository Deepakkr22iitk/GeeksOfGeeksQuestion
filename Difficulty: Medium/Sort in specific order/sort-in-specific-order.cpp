class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int i, int j){
            if((i&1) && (j&1)) return i > j;
            else if(i&1) return true;
            else if(j&1) return false;
            else return i<j;
        });
    }
};