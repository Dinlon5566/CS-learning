/**
Note:
即使編譯器可以執行某些行數，但在標準中就是非法
constenptr可以讓常數便常態表達式，避免非法傳遞
**/
#include <iostream>
#define LEN 10

using namespace std;

constexpr int fibonacci(const int n){
    return n==1||n==2?1:fibonacci(n-1)+fibonacci(n-2);
}

int foo(){
    return 10;
}
constexpr int foo_constexptr(){
    return 10;
}

int main()
{
    char arr_1[10];
    char arr_2[LEN];

    int len=10;
    //char arr_3[len]

    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    //char arr_4[len_2];
    char arr_5[len_2_constexpr];

    //char arr_6[foo()+1];
    char arr_7[foo_constexptr()+1];

    cout<<fibonacci(10)<<endl;

    return 0;
}
