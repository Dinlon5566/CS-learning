#include <iostream>

using namespace std;

template<typename T>
void foo(T t0){
    cout<<t0<<endl;
}

template<typename T,typename... Ts>
void foo(T t0,Ts... args){
    cout<<sizeof...(args)<<"  "<<t0<<endl;
    foo(args...);
}

template<typename T,typename... Ts>
void betterFoo(T t0,Ts... args){
cout<<t0<<endl;
if constexpr (sizeof...(args)) betterFoo(args...);
}

template<typename T,typename... Ts>
void superFoo(T t0,Ts... args){
    cout<<t0<<endl;
    (void) initializer_list<T>{([&args] {
        cout << args <<endl;
    }(), t0)...};
}


int main()
{
    foo(1,2,3,4,5);
    cout<<"---"<<endl;
    betterFoo(1,2,3,4,5);
    cout<<"---"<<endl;
    superFoo(1,2,3,4,5);
    return 0;
}
