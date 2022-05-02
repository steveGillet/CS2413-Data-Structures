#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

void problem1(){                                                  //Problem 1
    array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, 10> arr2;
    arr2.fill(10);
    cout << "The first element of the first array is: " << arr1.front() << endl;
    cout << "The last element of the first array is: " << arr1.back() << endl;
    arr1.swap(arr2);
    cout << "The size of the first array is: " << arr1.size() << endl;
    cout << "The size of the second array is: " << arr2.size() << endl;
}
void problem2(){                                                  //Problem 2
    srand(time(0));                                               //Part A
    int sizeVector;
    cout << "What would you like the size of the vector to be?" << endl;
    cin >> sizeVector;
    vector <int> vector1;
    for(int i=1; i<= sizeVector; i++)
    {
      cout << "Please enter an int for the vector: ";
      int vectorInput;
      cin >> vectorInput;
      vector1.push_back(vectorInput);
    }
    vector <int> vector2;
    for(int i=0; i< sizeVector; i++)
    {
      vector2.push_back(vector1[i]);
    }
    std::sort(vector2.begin(), vector2.end());
    cout << "Vector 1: " << endl;
    for(int i=0; i< sizeVector; i++)
    {
      cout << vector1[i] << endl;
    }
    cout << "Vector 2: " << endl;
    for(int i=0; i< sizeVector; i++)
    {
      cout << vector2[i] << endl;
    }
    vector <int> vector100;                               //Part B
    for(int i=0; i< 100; i++)
    {
      vector100.push_back(rand()%100+1);
    }
    vector <int> vector10;
    for(int i=0; i< 10; i++)
    {
      vector10.push_back(rand()%100+1);
    }
    int counter = 0;
    for(int i=0; i < vector10.size(); i++)
    {
      for(int j=0; j < vector100.size(); j++)
      {
        if(vector10[i] == vector100[j])
        {
          counter++;
          break;
        }
      }
    }
    cout << counter << " elements from the 10 vector are in the 100 vector." << endl;
    cout << counter * 10 << " percent of the 10 vector is contained in the 100 vector." << endl;
    vector <int> vectorEqual1;                                    //Part C
    vector <int> vectorEqual2;
    int sizeEqualVectors = rand()%10+1;
    for(int i=0; i < sizeEqualVectors; i++)
    {
      vectorEqual1.push_back(rand()%10+1);
      vectorEqual2.push_back(rand()%10+1);
    }
    if(vectorEqual1 == vectorEqual2)
    {
      cout << "The vectors are equal." << endl;
    }
    else
    {
      cout << "The vectors are not equal." << endl;
    }
    vector <int> vectorRepeated;                                    //Part D
    int sizeRepeated = rand()%10+1;
    for(int i=0; i < sizeRepeated; i++)
    {
      vectorRepeated.push_back(rand()%10+1);
    }
    for(int i=0; i < sizeRepeated; i++)
    {
      int compare, compareCounter = 0;
      compare = vectorRepeated[i];
      for(int j = 0; j < vectorRepeated.size(); j++)
      {
        if (compare == vectorRepeated[j])
        {
          compareCounter++;
        }
      }
      cout << i << " element of repeating vector is repeated " << compareCounter - 1 << " times." << endl; 
    }
    int sizeVectorMerge1 = rand()%10+1;                                  //Part E
    int sizeVectorMerge2 = rand()%10+1;
    vector <int> vectorMerge1;
    for(int i=0; i < sizeVectorMerge1; i++)
    {
      vectorMerge1.push_back(rand()%10+1);
    }
    vector <int> vectorMerge2;
    for(int i=0; i < sizeVectorMerge1; i++)
    {
      vectorMerge2.push_back(rand()%10+1);
    }
    std::sort(vectorMerge1.begin(), vectorMerge1.end());
    std::sort(vectorMerge2.begin(), vectorMerge2.end());
    cout << " Merge Vector 1: " << endl;  
    for(int i=0; i< vectorMerge1.size(); i++)
    {
      cout << vectorMerge1[i] << endl;
    }
    cout << " Merge Vector 2: " << endl;
    for(int i=0; i< vectorMerge2.size(); i++)
    {
      cout << vectorMerge2[i] << endl;
    }
    for(int i=0; i < vectorMerge2.size(); i++)
    {
      vectorMerge1.push_back(vectorMerge2[i]);
    }
    std::sort(vectorMerge1.begin(), vectorMerge1.end());
    cout << " Merged Vector: " << endl;
    for(int i=0; i< vectorMerge1.size(); i++)
    {
      cout << vectorMerge1[i] << endl;
    }
}


int main()
{
    problem1();
    problem2();
    
}