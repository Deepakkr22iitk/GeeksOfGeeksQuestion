class Solution {
  public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> balanceFreq;
        balanceFreq[0] = 1;

        int count = 0;
        int prefixBalance = 0;

        for (string& s : arr) {
            int bal = 0;
            for (char ch : s) {
                if (isVowel(ch)) bal++;
                else bal--;
            }

            prefixBalance += bal;
            count += balanceFreq[prefixBalance];
            balanceFreq[prefixBalance]++;
        }

        return count;
    }
};