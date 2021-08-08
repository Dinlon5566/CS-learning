#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
public:
    int val;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;
    TreeNode():val(0){}
    TreeNode(int _val):val(_val){}
    TreeNode(int _val,TreeNode* _left,TreeNode* _right):val(_val),left(_left),right(_right){}
};

bool searchTarget(TreeNode* root,int target){
    if(!root)
        return false;
    if(root->val==target)
        return true;
    return searchTarget(target>root->val?root->right:root->left,target);
}
int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(7);
    cout<<searchTarget(root,6)<<endl;
    cout<<searchTarget(root,7)<<endl;
    return 0;
}
