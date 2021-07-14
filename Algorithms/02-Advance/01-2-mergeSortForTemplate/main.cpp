/**
02-01-1--Merge-Sort-For-Template
**/
#include <iostream>

using namespace std;



template <typename T>
void merge(T nums[],int numsHead,int numsMid,int numsEnd)
{
    T tmp[numsEnd-numsHead+1];

    for(int i=numsHead; i<=numsEnd; i++)
    {
        tmp[i-numsHead]=nums[i];
    }

    int left=numsHead,right=numsMid+1,loadCount=numsHead;

    while(left<=numsMid&&right<=numsEnd)
    {
        if(tmp[left-numsHead]<tmp[right-numsHead])
        {
            nums[loadCount]=tmp[left-numsHead];
            left++;
        }
        else
        {
            nums[loadCount]=tmp[right-numsHead];
            right++;
        }

        loadCount++;
    }

    while(left<=numsMid)
    {
        nums[loadCount]=tmp[left-numsHead];
        loadCount++;
        left++;
    }
    while(right<=numsEnd)
    {
        nums[loadCount]=tmp[right-numsHead];
        loadCount++;
        right++;
    }

}

template <typename T>
void __mergeSort(T nums[],int numsHead,int numsEnd)
{

    if(numsHead>=numsEnd)
        return;

    int numsMid=(numsHead+numsEnd)/2;
    __mergeSort(nums,numsHead,numsMid);
    __mergeSort(nums,numsMid+1,numsEnd);

    merge(nums,numsHead,numsMid,numsEnd);
}

template <typename T>
void mergeSort(T nums[],int numsSize)
{
    __mergeSort(nums,0,numsSize-1);
}

int main()
{
    int nums[10]= {10,9,8,7,6,5,4,3,2,1};

    mergeSort(nums,10);

    for(int i=0; i<10; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}
