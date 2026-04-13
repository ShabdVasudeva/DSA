#include <iostream>
#include <vector>
#include <queue>

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

int height_level_order(Node* root) // Breadth First Search Algorithm
{
    if (!root) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root); q.push(NULL);
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if (!current)
        {
            count++;
            if (!q.empty())
            {
                q.push(NULL); continue;
            } else {
                break;
            }
        }
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
    }
    return count;
}

int height(Node* root)
{
    if(!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right)+1;
}

int main()
{
    Node* root = buildTree({1,2,-1,-1,3,4,-1,-1,5,-1,-1});
    cout << "Height of binary tree: " << height_level_order(root) << "\n";
    return 0;
}