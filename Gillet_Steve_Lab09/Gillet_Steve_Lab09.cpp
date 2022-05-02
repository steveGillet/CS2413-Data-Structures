/* Lab #9, Steve Gillet*/

#include <iostream>
#include <vector>

using namespace std;

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

int maxCount(1), count(0), levelCounter(0);
vector<int> widthLevel;

void findWidths(tree *root)
{
    if (root == NULL)
        return;
    levelCounter++;
    for (int i = 0; i < levelCounter; i++)
    {
        if (levelCounter == i + 1)
            widthLevel[i]++;
    }
    findWidths(root->left);
    findWidths(root->right);
    levelCounter--;
}

void heightTree(tree *root)
{
    if (root == NULL)
        return;
    count++;
    heightTree(root->left);
    heightTree(root->right);
    if (count > maxCount)
        maxCount = count;
    count--;
}

int main()
{
    int heightLeft, maxWidth(0), maxWidthLevel(1);
    tree *root = new tree(4);
    root->left = new tree(2);
    root->right = new tree(5);
    root->left->left = new tree(1);
    root->left->right = new tree(3);
    root->right->right = new tree(6);
    root->right->left = new tree(99);
    root->right->right->right = new tree(7);
    root->left->right->right = new tree(10);
    root->right->right->right->right = new tree(64);
    heightTree(root);
    for (int i = 0; i < maxCount; i++)
        widthLevel.push_back(0);
    findWidths(root);
    cout << "The widths levels in order are: " << endl;
    for (int i = 0; i < widthLevel.size(); i++)
        std::cout << widthLevel.at(i) << ' ';
    for (int i = 0; i < widthLevel.size(); i++)
    {
        if (widthLevel.at(i) > maxWidth)
        {
            maxWidth = widthLevel.at(i);
            maxWidthLevel = i + 1;
        }
    }
    cout << "\nThe widest level is level " << maxWidthLevel << ". ";
    return 0;
}