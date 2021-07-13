/**
02-01-Insertion-Sort
**/
#include <iostream>
#include <algorithm>
#include "Insertion-Sort.h"
using namespace std;

template<typedef T>
void _merge(T nums[],int arrSize,int arrMid,int arrEnd){

    T aux[arrEnd-arrSize+1];

    for()
}

int main()
{
    int nums[10]={10,9,8,7,6,5,4,3,2,1};
    insertionSort(nums,10);
    for(int i=0;i<10;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
