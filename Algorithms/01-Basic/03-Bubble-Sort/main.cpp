/**
01-03-Bubble-Sort
**/
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void bubbleSort(T nums[],int n)
{
    bool clean;
    do
    {
        clean=true;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1]>nums[i])
            {
                swap(nums[i-1],nums[i]);
                clean=false;
            }
        }
    }
    while(!clean);
}

int main()
{
    int nums[10]= {10,9,8,7,6,5,4,3,2,1};
    bubbleSort(nums,10);

    for(int i=0; i<10; i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
