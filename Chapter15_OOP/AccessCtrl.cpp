#include "AccessCtrl.h"
int main(){
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Pub_Derv_From_Public dd1;
    Pub_Derv_From_Private dd2;
    Pub_Derv_From_Protected dd3;

    //for users of derived class
    d1.pub_mem();
    //d1.prot_mem;
    //d1.priv_mem;
    //d2.pub_mem();
    //d3.pub_mem();

    //practice15.18类型转化（记住一个原则，在某个节点基类共有成员是可访问的，
    //也就是说转换后访问性不存在冲突，则可以转换）
    base *p=&d1;
    //p=&d2;
    //p=&d3;
    p=&dd1;
//    p=&dd2;
//    p=&dd3;


    return 0;


}