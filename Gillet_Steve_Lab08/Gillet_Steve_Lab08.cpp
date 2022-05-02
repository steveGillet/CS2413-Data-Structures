// Steve Gillet Lab 8

#include <iostream>
#include <stack>

using namespace std;

int counterLeft(0), counterRight(0), maxLeft(0), maxRight(0);

struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    tree(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};

void heightLeftTree(struct tree *root)
{
    if (root == NULL)
        return;
    counterLeft++;
    heightLeftTree(root->left);
    heightLeftTree(root->right);
    if (counterLeft > maxLeft)
        maxLeft = counterLeft;
    counterLeft = 1;
}

void heightRightTree(struct tree *root)
{
    if (root == NULL)
        return;
    counterRight++;
    heightRightTree(root->right);
    heightRightTree(root->left);
    if (counterRight > maxRight)
        maxRight = counterRight;
    counterRight = 1;
}

bool compareHeights(int heightLeft, int heightRight)
{
    if (abs(heightLeft - heightRight) > 1)
        return 1;
    else
        return 0;
}

bool bst = 1;
stack<int> s;

void bstCheck(struct tree *root)
{
    if (root == NULL)
        return;
    bstCheck(root->left);
    s.push(root->key);
    bstCheck(root->right);
}

void stackCheck()
{
    while (!s.empty())
    {
        int temp;
        temp = s.top();
        s.pop();
        if (temp < s.top())
            bst = 1;
        else
            bst = 0;
    }
}

int main()
{
    int heightLeft;
    tree *root = new tree(4);
    root->left = new tree(2);
    root->right = new tree(5);
    root->left->left = new tree(1);
    root->left->right = new tree(3);
    root->left->right->right = new tree(6);
    root->left->right->right->left = new tree(7);
    heightLeftTree(root->left);
    cout << "The height of the left subtree is: " << maxLeft << endl;
    heightRightTree(root->right);
    cout << "The height of the right subtree is: " << maxRight << endl;
    if (compareHeights(maxLeft, maxRight))
        cout << "The tree is unbalanced." << endl;
    else
        cout << "The tree is balanced." << endl;
    bstCheck(root);
    stackCheck();
    if (bst == 1)
        cout << "Tree is binary search tree." << endl;
    else
        cout << "Tree is not binary search tree." << endl;
    return 0;
}