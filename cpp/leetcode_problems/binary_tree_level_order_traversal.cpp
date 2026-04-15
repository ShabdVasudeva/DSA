#include <iostream>
#include <vector>
#include <queue>
#include "../data_structures/binary_tree_int.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<int> q;
}

int main()
{
    vector<int> preorder_sequence = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    Node* root = Node::buildTree(preorder_sequence);
    Node::preorderTraversal(root);
    return 0;
}