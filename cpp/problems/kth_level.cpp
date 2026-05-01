#include <iostream>
#include <vector>
#include "../data_structures/binary_tree_int.h"

using namespace std;

void kthLevel(Node* root, int k)
{
    if(!root) return;
    if(k == 1) cout << root->data << " ";
    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = Node::buildTree(arr);
    kthLevel(root, 3);
    return 0;
}