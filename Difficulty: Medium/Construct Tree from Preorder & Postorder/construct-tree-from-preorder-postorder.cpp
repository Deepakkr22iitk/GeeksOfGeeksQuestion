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
};
*/

class Solution {
  protected:
    int getPostion(int ele, vector<int> &postorder){
        for(int  i=0; i<postorder.size(); i++){
            if(postorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* getAns(vector<int> &preorder, vector<int> &postorder, int &index, int start, int end){
        if(start>end or index>=preorder.size())
        return nullptr;
        Node* root= new Node(preorder[index++]);
        // if(index<preorder.size()){
            if (start == end || index >= preorder.size()) return root;
        int newele= preorder[index];
        int findPos= getPostion(newele, postorder);
        root->left  = getAns(preorder, postorder, index, start, findPos);
        root->right = getAns(preorder, postorder, index, findPos + 1, end - 1);
        return root;
    }
    public:
        Node* constructTree(vector<int>& preorder, vector<int>& postorder) {
        int index=0;
        int start=0;
        int end= postorder.size()-1;
        return getAns(preorder, postorder, index, start, end);
    
    }
};