#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    static int i;

    explicit Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
    explicit Node(int data): data(data), left(nullptr), right(nullptr) {}
    explicit Node(): data(0), left(nullptr), right(nullptr) {}
    
    static void deleteTree(Node* root);

    static Node* buildTree(const vector<int>& preorder_sequence);
    static void postorderTraversal(Node* root);
    static void inorderTraversal(Node* root);
    static void preorderTraversal(Node* root);
    static void levelorderTraversal(Node* root);
};

#endif