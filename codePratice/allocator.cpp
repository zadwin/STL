// #include<bits/stdc++.h>
#include<iostream>
#include<typeinfo> // 类型判断的用法
using namespace std;
template <typename T>
class A{
public:
    T a;
    explicit A(T c) : a(c)
    {
    }
};
// 测试char*被void*接收会怎么样。
template<typename T>
class A<T*>{ // 偏特化的前提是要有泛化的类。
public:
    typedef T value_type;
    T a;
    explicit A(T c): a(c){
    }
};
template <class I>
void func(I iter){
    cout << typeid(iter).name() << endl;
}
int main(){
    int *c = new int(10);
    A<int*> b(*c);
    typedef A<int *>::value_type value;
    value a = 10;
    cout << a << "  " << typeid(a).name() << endl;
    int cc = 10;
    func(&cc);
    return 0;
}