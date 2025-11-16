#include "Hasptr_value.h"
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
    
    return 0;
}