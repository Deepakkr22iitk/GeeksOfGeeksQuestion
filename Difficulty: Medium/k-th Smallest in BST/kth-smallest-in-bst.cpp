/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  // Helper function for Inorder Traversal
    int inorder(Node *root, int &k) {
        if (!root) {
            return -1; // -1 as a sentinel value, meaning not found in this subtree
        }

        // 1. Traverse Left Subtree
        int left_result = inorder(root->left, k);
        // If the element is found in the left subtree, immediately return it
        if (left_result != -1) {
            return left_result;
        }

        // 2. Visit Root Node
        k--; // Decrement k for the current node
        if (k == 0) {
            return root->data; // This is the k-th smallest element
        }

        // 3. Traverse Right Subtree
        int right_result = inorder(root->right, k);
        // If the element is found in the right subtree, return it
        if (right_result != -1) {
            return right_result;
        }

        // Not found in this subtree and its children
        return -1; 
    }

public:
    int kthSmallest(Node *root, int k) {
        // We pass k by reference to track the count across recursive calls.
        return inorder(root, k); 
    }
};