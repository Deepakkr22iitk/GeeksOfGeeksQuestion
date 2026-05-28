/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    void dfs(Node* root,int key,map<int,int> &mp){
        if(!root)return ;
        mp[key]+=root->data;
        dfs(root->left,key-1,mp);
        dfs(root->right,key+1,mp);
    }
    vector<int> verticalSum(Node* root) {
        vector<int> ans;
        map<int,int> mp;
        dfs(root,0,mp);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};