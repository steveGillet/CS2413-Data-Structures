// Steve Gillet Lab 11

#include <iostream>
#include <array>

using namespace std;

void printArray(int array[], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
        cout << array[i] << ' ';
    cout << endl;
}

void merge(int *array, int first, int last)
{
    //printArray(array, last + 1);
    int mid = (first + last) / 2;
    int i1(0), i2(first), i3(mid + 1);
    int temp[last - first + 1];
    while (i2 < mid + 1 && i3 < last + 1)
    {
        if (array[i2] < array[i3])
        {
            temp[i1] = array[i2];
            i1++;
            i2++;
        }
        else
        {
            temp[i1] = array[i3];
            i1++;
            i3++;
        }
    }
    while (i2 != mid + 1)
    {
        temp[i1] = array[i2];
        i2++;
        i1++;
    }
    while (i3 != last + 1)
    {
        temp[i1] = array[i3];
        i3++;
        i1++;
    }
    for (int i = 0, i4 = first; i < (last - first + 1); i++, i4++)
    {
        array[i4] = temp[i];
    }
    //printArray(array, last + 1);
}

void mergesort(int *array, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(array, first, mid);
        mergesort(array, mid + 1, last);
        merge(array, first, last);
    }
}

int main()
{
    int array[] = {4, 36, 27, 3, 2, 19, 54, 12, 73, 56};
    int sizeArray = sizeof(array) / sizeof(array[0]);
    cout << "Array before sorting : " << endl;
    printArray(array, sizeArray);
    mergesort(array, 0, sizeArray - 1);
    cout << "Array after sorting : " << endl;
    printArray(array, sizeArray);
    return 0;
}