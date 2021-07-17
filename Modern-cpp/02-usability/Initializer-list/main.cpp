#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

class BetterFoo{
public:
    vector<int> vec;
    BetterFoo(initializer_list<int> nums){
    for(initializer_list<int>::iterator it=nums.begin();it!=nums.end();++it)
        vec.push_back(*it);

    }
};

int main()
{
    //before c++ 11;
    int arr[5]={1,2,3,4,5};
    Foo foo(1,2);
    vector<int> vec={1,2,3,4,5};

    //after c++11;
    BetterFoo betterfoo={1,2,3,4,5};
    for(vector<int>::iterator it=betterfoo.vec.begin();it!=betterfoo.vec.end();++it)
        cout<<*it<<endl;

    return 0;
}
