//行为像指针的类
#include <iostream>
#include <string>
using namespace std;
class HasPtr {
    /*
    通过引用计数use实现行为像指针的类
    */
public:
    //copy constructor
    HasPtr(const HasPtr & x){
        ps=x.ps;
        i=x.i;
        use=x.use;
        ++*use;
    }
    HasPtr(const string &s =string()):ps(new string(s)),i(0),use(new unsigned(1)) {}
    //copy operator
    HasPtr& operator=(const HasPtr& x){ 
        /*
        编写赋值运算符的原则：对象赋予他自身时必须能工作
        */
        ++*x.use;
        if(--*use==0){
            delete ps;
            delete use;
        }
        ps=x.ps;
        i=x.i;
        use=x.use;
        return *this;    
        
    }
    //deconstructor
    ~HasPtr(){
       if(--*use==0){
        delete ps;
        delete use;
       } 
        
    }
    void print(){cout<<*ps<<" "<<i<<endl;}
    string * returns(){return ps;};
public:
    unsigned *use;
    string *ps;
    int i;
};