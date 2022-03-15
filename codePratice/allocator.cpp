#include<iostream>
using namespace std;

int main(){
    allocator<string> alloc;
    int N = 0;
    cin >> N;
    auto str_ve = alloc.allocate(N);
    auto  p = str_ve;
    alloc.construct(p++);
    alloc.construct(p++, 10, 'a');
    alloc.construct(p++, "construct");
    cout << str_ve[0] << endl;
    cout << str_ve[1] << endl;
    cout << str_ve[2] << endl;
    while(p != str_ve){
        alloc.destroy(--p); // 这里使用的是第一个版本，主要是销毁对象，调用析构函数。
    }
    alloc.deallocate(str_ve, N);    //回收内存。
    return 0;
}