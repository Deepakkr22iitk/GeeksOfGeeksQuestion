/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    long long prev = -1;
    long long minDiff = 1e18;

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            long long diff = root->data - prev;
            if (diff < minDiff) minDiff = diff;
        }
        prev = root->data;

        inorder(root->right);
    }
    int absDiff(Node *root) {
        prev = -1;
        minDiff = 1e18;
        inorder(root);
        return (int)minDiff;
    }
};