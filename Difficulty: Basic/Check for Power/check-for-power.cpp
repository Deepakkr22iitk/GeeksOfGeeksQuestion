class Solution {
  public:
    bool isPower(int x, int y) {
        int _exp = round(1.00*log(1.00*y)/log(1.00*x));
        return (pow(x, _exp) == y);
    }
};