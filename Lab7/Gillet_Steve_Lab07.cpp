#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void switchPostOrder(struct Node *node)
{
    if (node->left == NULL || node->right == NULL)
        return;

    switchPostOrder(node->left);
    switchPostOrder(node->right);
    Node *temp = new Node;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void printInOrder(struct Node *node)
{
    if (node == NULL)
        return;

    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Tree printed in order before mirror: \n";
    printInOrder(root);
    cout << "\nTree switched: \n";
    switchPostOrder(root);
    cout << "\nTree printed after mirror: \n";
    printInOrder(root);
    return 0;
}