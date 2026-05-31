class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        return n > 2 && (n & (n - 1)) != 0;
    }
};