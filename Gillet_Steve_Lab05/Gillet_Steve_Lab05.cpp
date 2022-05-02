//Steve Gillet Lab 5

#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <string>
using namespace std;

void showq(queue <int> q)
{
    queue <int> qTemp = q;
    while (!qTemp.empty())
    {
        cout << '\t' << qTemp.front();
        qTemp.pop();
    }
    cout << endl;
}

int main()
{
    int totalGain = 0;  
    char continueCode = 'Y';
    queue <int> holdings;
    while(continueCode == 'Y' || continueCode == 'y')
    {
        int numberBuyShares, costShares, numberSellShares, salesValue=0, sales, capitalGain =0;
        cout << "How many shares would you like to buy? " << endl;
        cin >> numberBuyShares;
        cout << "How much do the shares cost? " << endl;
        cin >> costShares;
        for(int i = 0; i < numberBuyShares; i++)
            holdings.push(costShares);
        cout << holdings.size() << " Shares: " << endl;
        showq(holdings); 
        cout << "How many shares would you like to sell? " << endl;
        cin >> numberSellShares;
        while(numberSellShares>holdings.size())
        {
        cout << "You don't have that many shares." << endl;
        cout << "You have " << holdings.size() << " shares." << endl << "How many shares would you like to sell? " << endl;
        cin >> numberSellShares;
        }
        for(int i = 0; i < numberSellShares; i++)
        {
            salesValue += holdings.front();
            holdings.pop();
        }
        cout << holdings.size() << " Shares: " << endl;
        showq(holdings);
        sales = numberSellShares * costShares;
        capitalGain = sales - salesValue;
        totalGain += capitalGain;
        cout << "The total capital gains/loss for today is: $" << capitalGain <<endl;
        cout << "The total capital gains/loss for all days is: $" << totalGain <<endl;
        cout << "Would you like to continue (Y/N)? " << endl;
        cin >> continueCode;
    }
}