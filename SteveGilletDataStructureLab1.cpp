#include <iostream>

using namespace std;

string helloWorld() //Question 1
{
    string helloWorld = "Hello World.";
    return helloWorld;
}

int averageInts() //Question 2
{
    int first, second, average;
    cout<<"Please enter two integers to get the sum of: " << endl << "First: ";
    cin >> first;
    cout<<"Second: ";
    cin >> second;
    average = (first + second)/2; 
    return average;
}

int sumInt() //Question 3
{
    int intSum;
    cout<<"Please enter the integer that you want to sum with all of the integers before it down to 0: ";
    cin >> intSum;
    int sum = 0;
    for(int i = 0; i <= intSum; i++)
    {
        sum += i;
    }
    return sum;
}

int factorialOfInt() //Question 4
{
    int factorialInt;
    cout<<"Please enter the integer that you want to get the factorial of: ";
    cin >> factorialInt;
    int sum = 1;
    for(int i = 1; i <= factorialInt; i++)
    {
        sum *= i;
    }
    return sum;
}

int sumArray() //Question 5
{
    int array [5];
    cout << "Please enter 5 integers that you would like to sum: " << endl;
    cout << "First: ";
    cin >> array[0];
    cout << "Second: ";
    cin >> array[1];
    cout << "Third: ";
    cin >> array[2];
    cout << "Fourth: ";
    cin >> array[3];
    cout << "Fifth: ";
    cin >> array[4];
    int sum = 0;
    for(int i = 0; i<5; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    cout << helloWorld() << endl;
    int average = averageInts();
    cout << "Average: " << average << endl;
    int intSum; 
    intSum = sumInt();
    cout << "Sum: " << intSum << endl;
    int factorial = factorialOfInt();
    cout << "Factorial: " << factorial << endl;
    int intSumArray = sumArray();
    cout << "Sum of 5 integers: " << intSumArray << endl;
    return 0;
}
