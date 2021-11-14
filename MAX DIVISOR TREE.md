```
#include<bits/stdc++.h>
using namespace std;

class Node
{   public:
        Node* left;
        Node* right;
        int key;
};
Node* newNode(int key)
    {
        Node* temp = new Node();
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }
Node* createFactorTree(Node* node_ref, int v)
{
    node_ref = newNode(v);
    for (int i = 2 ; i <= v/2 ; i++)
    {
        if (v % i != 0)
                continue;
        node_ref->right = createFactorTree(node_ref->right, v/i);
        return node_ref;
    }
    return node_ref;
}
void printLevelOrder(Node* root)
{
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();q.pop();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}
int height(Node* root) {
if (!root) 
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);

    if (rh > lh) 
        return 1 + rh;
    else 
        return 1 + lh;
}
int main()
{

    int val = 10;// sample value
    Node *root;
    root = createFactorTree(root, val);
    printLevelOrder(root);
    cout<<height(root);
    return 0;
}
```
