#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include "../data_structures/binary_tree_int.h"

using namespace std;

void top_view(Node* root)
{
    if(!root) 
    {
        cout << "null" << "\n";
        return;
    }
    queue<pair<Node*, int>> q;
    map<int, Node*> map;
    q.push({root, 0});
    while(!q.empty())
    {
        Node* current = q.front().first;
        int current_val = q.front().second;
        q.pop();
        if(map.find(current_val) == map.end())
        {
            map[current_val] = current;
        }
        if(current->left) q.push({current->left, current_val-1});
        if(current->right) q.push({current->right, current_val+1});
    }
    for(pair<int, Node*> i: map)
    {
        cout << i.second->data << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> preorder_sequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = Node::buildTree(preorder_sequence);
    topView(root);
    return 0;
}