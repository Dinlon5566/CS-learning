/**
02-Insertion-Sort
**/
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void insertionSort(T nums[],int arraySize)
{
    for(int i=0; i<arraySize; i++)
    {
        for(int j=i; j>0&&nums[j]<nums[j-1]; j--)
        {
            swap(nums[j],nums[j-1]);
        }
    }
}

int main()
{
    int nums[10]= {10,9,8,7,6,5,4,3,2,1};
    insertionSort(nums,10);

    for(int i=0; i<10; i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
