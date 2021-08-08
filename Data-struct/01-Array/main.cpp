#include <iostream>

using namespace std;

struct Array{
private:
    int size;
    int* array;
public:
    Array(int i){
        array=new int[i];
    }
    void set(int loc,int num){
        array[loc]=num;
    }
    int get(int i){
        return array[i];
    }
    int getSize(){
        return size;
    }
    void del(){
        delete array;
    }
};
int main()
{
    Array a(5);
    for(int i=0;i<5;i++){
        a.set(i,i);
        cout<<a.get(i)<<endl;
    }
    a.del();
    return 0;
}
