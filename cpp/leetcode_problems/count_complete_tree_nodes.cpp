#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    explicit Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
    explicit Node(int data): data(data), left(nullptr), right(nullptr) {}
    explicit Node(): data(0), left(nullptr), right(nullptr) {}

    static int i;
    static Node* buildTree(const vector<int>& preorder_sequence)
    {
        if (++i >= preorder_sequence.size() || preorder_sequence[i] == -1) return NULL;  
        Node* root = new Node(preorder_sequence[i]);
        root->left = buildTree(preorder_sequence);
        root->right = buildTree(preorder_sequence);
        return root;
    }
};

int countNodes(Node* root)
{
    if(!root) return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left+right+1;
}

int Node::i = -1;

int main()
{
    Node* root = Node::buildTree({1,2,-1,-1,3,4,-1,-1,5,-1,-1});

    int count_nodes = countNodes(root);
    cout << count_nodes << "\n";
    return 0;
}