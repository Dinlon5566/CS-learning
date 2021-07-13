/**
01-04-Shell-Sort
**/
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void shellSort(T nums[],int n)
{
    int h=1;
    while(h<n/3){
        h=h*3+1;
    }
    while(h){
        for(int i=h;i<n;i++){
            T e=nums[i];
            int j;
            for(j=i;j>=h&&e<nums[j-h];j-=h){
                nums[j]=nums[j-h];
            }
            nums[j]=e;
        }
        h/=3;
    }
}

int main()
{
    int nums[10]= {10,9,8,7,6,5,4,3,2,1};
    shellSort(nums,10);

    for(int i=0; i<10; i++)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
