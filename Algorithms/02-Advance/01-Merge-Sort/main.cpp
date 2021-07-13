/**
02-01-Insertion-Sort
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include "Insertion-Sort.h"
using namespace std;

vector<int> merge(vector<int> left,vector<int> right)
{
    vector<int> tmp;
    while(left.size()>0&&right.size()>0)
    {
        if(left.back()>right.back())
        {
            tmp.push_back(left.back());
            left.pop_back();
        }
        else
        {
            tmp.push_back(right.back());
            right.pop_back();
        }
    }
    while(left.size()>0)
    {
        tmp.push_back(left.back());
        left.pop_back();
    }
    while(right.size()>0)
    {
         tmp.push_back(right.back());
        right.pop_back();
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}

int mergeSort (vector<int> &nums)
{
    vector<int> result,left,right;
    if(nums.size()<=1)
    {
        return 1;
    }
    int mid=nums.size()/2;
    for(int i=0; i<mid; i++)
    {
        left.push_back(nums[i]);
    }
    for(int i=mid; i<nums.size(); i++)
    {
        right.push_back(nums[i]);
    }
    mergeSort(left);
    mergeSort(right);

    nums= merge(left,right);
    return 1;
}


int main()
{
    vector<int> nums= {10,9,8,7,6,5,4,3,2,1};
    mergeSort(nums);
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}
