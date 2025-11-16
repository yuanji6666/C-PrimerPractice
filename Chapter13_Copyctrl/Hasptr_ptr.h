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
    /*
    HasPtr& operator=(const HasPtr& x){ 
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
    */
   HasPtr& operator=(HasPtr x){
        swap(*this,x);
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
public:
    friend void swap(HasPtr&,HasPtr&);
};
void swap(HasPtr& a,HasPtr& b){
    using std::swap;
    swap(a.ps,b.ps);
    swap(a.i,b.i);
    swap(a.use,b.use);
}