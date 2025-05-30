/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans=-1;
        Node* node=root;
        while(node){
            if(node->data<=k){
                ans=node->data;
                node=node->right;
            }else{
                node=node->left;
            }
        }
        return ans;
    }
};