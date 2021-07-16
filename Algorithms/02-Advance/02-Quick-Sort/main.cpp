/**
02-2-Quick-Sort
***/
#include <iostream>
#include <algorithm>
using namespace std;


template <typename T>
int partition(T nums[],int left,int right){
    int result;
    T tmp[left];

    //todo

    return result;
}

template <typename T>
void __quickSort(T nums[],int left,int right){

    if(left>=right)
        return;

    int flag=partition(nums,left,right);
    __quickSort(nums,left,flag-1);
    __quickSort(nums,flag+1,right);

}

template <typename T>
void quickSort(T nums[],int arrSize){
    __quickSort(nums,0,arrSize-1);
}

int main()
{
    int nums[10]= {10,9,8,7,6,5,4,3,2,1};

    quickSort(nums,10);

    for(int i=0; i<10; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
