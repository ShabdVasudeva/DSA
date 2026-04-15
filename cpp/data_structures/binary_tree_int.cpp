#include "binary_tree_int.h"
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

Node* Node::buildTree(const vector<int>& preorder_sequence)
{
    if (++i >= preorder_sequence.size() || preorder_sequence[i] == -1) return NULL;  
    Node* root = new Node(preorder_sequence[i]);
    root->left = buildTree(preorder_sequence);
    root->right = buildTree(preorder_sequence);
    return root;
}

void Node::postorderTraversal(Node* root) // Depth First Search Algorithm
{
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << "\n";
}

void Node::inorderTraversal(Node* root) // Depth First Search Algorithm
{
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << "\n";
    inorderTraversal(root->right);
}

void Node::preorderTraversal(Node* root) // Depth First Search Algorithm
{
    if (!root) return;
    cout << root->data << "\n";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void Node::levelorderTraversal(Node* root) // Breadth First Search Algorithm
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

int Node::i = -1;

void Node::deleteTree(Node* root)
{
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}