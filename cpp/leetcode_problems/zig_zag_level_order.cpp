#include <iostream>
#include <vector>
#include <queue>
#include "../data_structures/binary_tree_int.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(Node* root)
{
    if(!root) return {};
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    bool isSwap = false;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i=0; i<size; i++)
        {
            Node* current = q.front();
            q.pop();
            int index = (!isSwap) ? i : (size-i-1);
            level[index] = current->data;
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        isSwap = !isSwap;
        ans.push_back(level);
    }
    return ans;
}

void printAns(vector<vector<int>>& ans)
{
    for(vector<int> i: ans)
    {
        for(int var : i)
        {
            cout << var << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> preorder_sequence = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    Node* root = Node::buildTree(preorder_sequence);
    // Node::preorderTraversal(root);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    printAns(ans);
    return 0;
}