//Steve Gillet Lab 6

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct tree
{
    char value;
    struct tree *left;
    struct tree *right;
    tree(char value2)
    {
        value = value2;
        left = NULL;
        right = NULL;
    }
};

void printStack(stack<tree *> s)
{
    stack<tree *> sPrint = s;
    while (!sPrint.empty())
    {
        cout << " " << sPrint.top()->value;
        sPrint.pop();
    }
    cout << endl;
}

tree *newNode(char c)
{
    tree *temp = new tree(c);
    temp->left = temp->right = NULL;
    temp->value = c;
    return temp;
}

bool isOperator(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
    {
        return true;
    }
    else
        return false;
}

bool isNum(char c)
{
    if (c >= 48 && c <= 57)
    {
        return 1;
    }
    else
        return 0;
}
bool isParen(char c)
{
    if (c == '(' || c == ')')
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    string userExpression;
    stack<tree *> treeStack;
    stack<tree *> tempStack;
    stack<tree *> opStack;
    tree *tempTree1, *tempTree2, *tempTree;
    cout << "Please input the expression you would like to convert to tree form: " << endl;
    getline(cin, userExpression);
    for (int i = 0; i < userExpression.length(); i++)
    {
        if (isOperator(userExpression[i]) || isNum(userExpression[i]) || isParen(userExpression[i]))
        {
            tempTree = newNode(userExpression[i]);
            treeStack.push(tempTree);
        }
    }
    while (!treeStack.empty())
    {
        tempTree = treeStack.top();
        treeStack.pop();
        if (isNum(tempTree->value))
            tempStack.push(tempTree);
        else if (isOperator(tempTree->value))
        {
            tempTree->left = tempStack.top();
            tempStack.pop();
            if (isParen(treeStack.top()->value))
            {
                while (isParen(treeStack.top()->value))
                {
                    treeStack.pop();
                }
                tempTree1 = treeStack.top();
                treeStack.pop();
                tempTree2 = treeStack.top();
                treeStack.pop();
                tempTree->right = tempTree2;
                tempTree2->right = tempTree1;
                tempTree2->left = treeStack.top();
                treeStack.pop();
                opStack.push(tempTree2);
            }
            else
            {
                tempTree->right = treeStack.top();
                treeStack.pop();
            }
            tempStack.push(tempTree);
            opStack.push(tempTree);
        }
    }
    tempTree = tempStack.top();
    tempStack.pop();
    cout << "The root of the tree is: " << tempTree->value << endl;

    while (!opStack.empty())
    {
        tempTree = opStack.top();
        cout << "  ";
        cout << tempTree->value;
        cout << endl;
        cout << " / \\";
        cout << endl;
        if (!isOperator(tempTree->left->value))
            cout << tempTree->left->value;
        cout << "   ";
        if (!isOperator(tempTree->right->value))
            cout << tempTree->right->value;
        cout << endl;
        opStack.pop();
    }

    return 0;
}