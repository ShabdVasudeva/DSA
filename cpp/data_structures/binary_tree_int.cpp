#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    explicit Node(int data): data(data), left(nullptr), right(nullptr) {}
};

static int i = -1;

Node* buildTree(const vector<int>& preorder_sequence)
{
    if (++i >= preorder_sequence.size() || preorder_sequence[i] == -1) return NULL;  
    Node* root = new Node(preorder_sequence[i]);
    root->left = buildTree(preorder_sequence);
    root->right = buildTree(preorder_sequence);
    return root;
}

void postorderTraversal(Node* root) // Depth First Search Algorithm
{
    if(!root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << "\n";
    }
}

void inorderTraversal(Node* root) // Depth First Search Algorithm
{
    if (!root)
    {
        inorderTraversal(root->left);
        cout << root->data << "\n";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) // Depth First Search Algorithm
{
    if (!root)
    {
        cout << root->data << "\n";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void levelorderTraversal(Node* root) // Breadth First Search Algorithm
{
    if (!root) return;
    deque<Node*> q;
    q.push_back(root); q.push_back(NULL);
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop_front();
        if (!current)
        {
            if (!q.empty())
            {
                cout << "\n"; q.push_back(NULL); continue;
            } else {
                break;
            }
        }
        cout << current->data << " ";
        if(current->left != NULL) q.push_back(current->left);
        if(current->right != NULL) q.push_back(current->right);
    }
}

void deleteTree(Node* root)
{
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    Node* root = buildTree({1,2,-1,-1,3,-1,4,-1,-1});
    levelorderTraversal(root);
    deleteTree(root);
    return 0;
}