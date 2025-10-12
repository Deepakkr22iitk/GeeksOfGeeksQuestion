/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int calCandy(Node* root, int &ans) {
        if(root == NULL) return 0;
        
        int lCandy = calCandy(root->left, ans);
        int rCandy = calCandy(root->right, ans);
        
        ans += abs(lCandy) + abs(rCandy);
        return lCandy + rCandy + 1 - root->data;
    }
    
  public:
    int distCandy(Node* root) {
        int ans = 0;
        calCandy(root, ans);
        
        return ans;
    }
};