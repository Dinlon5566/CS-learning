#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
int binarySearch(T arr[],int len,T target)
{
    int left=0;
    int right=len-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]= {1,2,3,6,8,9,10,11,23,56};
    cout <<binarySearch(arr,10,11)<< endl;
    return 0;
}
