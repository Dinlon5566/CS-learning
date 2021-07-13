#ifndef INSERTION-SORT_H_INCLUDED
#define INSERTION-SORT_H_INCLUDED

#include <iostream>
#include <algorithm>

template<typename T>
void insertionSort(T nums[],int arrSize){
    for(int i=0;i<arrSize;i++){
        for(int j=i;j>0&&nums[j-1]>nums[j];j--){
            std::swap(nums[j],nums[j-1]);
        }
    }
}

#endif // INSERTION-SORT_H_INCLUDED
