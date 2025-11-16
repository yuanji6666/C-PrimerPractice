#include "Hasptr_ptr.h"
int main(){
    HasPtr a("hello");
    HasPtr b(a);
    HasPtr c("test");
    c=a;
    a.print();
    *a.ps="world";
    a.print();
    b.print(); 
    c.print();
    string *s=nullptr;
    int i=1;
    {
        HasPtr d(a);
        s=d.returns();
        i--;
    }
    if(s) cout<<"value of pointer d is"<<*s<<endl;
    else cout<<"d is a nullptr"<<endl;
    return 0;
}