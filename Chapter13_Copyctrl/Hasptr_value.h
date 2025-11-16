//行为像值的类
#include <utility>
#include <iostream>
#include <string>
using namespace std;
class HasPtr {
public:
    /*如果不声明这样的拷贝函数和运算符，进行的是浅拷贝，直接把指针赋值过去*/
    //copy constructor
    HasPtr(const HasPtr & x){ps=new string(*x.ps); i=x.i;}
    HasPtr(const string &s =string()):ps(new string(s)),i(0){}
    //copy operator
    /*
    HasPtr& operator=(const HasPtr& x){ 
        
        //编写赋值运算符的原则：对象赋予他自身时必须能工作
        
        auto newp=new string(*x.ps);//先存入局部临时对象
        delete ps;//释放旧内存
        ps=newp;
        i=x.i;
        return *this;    
    }
    */
    HasPtr& operator=(HasPtr x){
        swap(*this,x);
        return *this;
    }
    //deconstructor
    ~HasPtr(){cout<<"deconstructor_running!"<<endl;delete ps;}
    //
    void print(){cout<<*ps<<" "<<i<<endl;}
    string * returns(){return ps;};
public:
    string *ps;
    int i;
public:
    friend void swap(HasPtr&,HasPtr&);
};
void swap(HasPtr &a,HasPtr&b){
    cout<<"swap_running"<<endl;
    std::swap(a.ps,b.ps);
    std::swap(a.i,b.i);
}