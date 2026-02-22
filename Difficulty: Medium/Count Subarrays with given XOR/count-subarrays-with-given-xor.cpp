class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // Initialize a map to store frequencies of prefix XORs
        map<int, int> mp;

        // Running XOR and result counter
        int sum = 0;
        long long ans = 0;

        for(int i = 0; i < arr.size(); ++i) {
            sum ^= arr[i]; // Update running XOR

            // Check if the running XOR itself equals k
            if (sum == k) {
                ++ans; 
            }

            // Check for previous XOR (sum ⊕ k) in the map
            if (mp.find(sum ^ k) != mp.end()) {
                ans += mp[sum ^ k]; // Add the frequency of (sum ⊕ k) to the count
            }

            // Update the frequency of the current XOR in the map
            mp[sum]++;
        }

        return ans; // Return the total count
    }
};