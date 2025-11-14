/*AccessCtrl练习类继承中的访问控制
我们认为类有三种用户，按权限从大到小分为类的实现者/派生类/普通用户
说明符有两种出现位置；
1.出现在类内，限制类的三类用户
2.出现在继承描述（派生访问说明符），控制派生类用户对继承自基类的成员的访问权限，
可以理解为把基类类成员复制在派生类内，访问说明服取原来和现在权限更小的那个
（这是很符合直觉的），这样无论派生多少层，我们都能直观的看出当前这层类的用户的访问权限
可以看下面的代码加深理解
*/
#include <iostream>
class base {
public:
    void pub_mem(){std::cout<<"running";};
protected:
    int prot_mem;
private:
    char priv_mem;
};
class Pub_Derv : public base{
    /* Pub_Derv相当于包含注释这些
public:
    void pub_mem(){std::cout<<"running"};
protected:
    int prot_mem;
private:
    char priv_mem;
   */
    int f(){return prot_mem;}
    //char s(){return priv_mem;} !error!
    void memfcn(base &b) {b=*this;}
};
class Priv_Derv : private base{
    /*
private:
    void pub_mem(){std::cout<<"running"};
private:
    int prot_mem;
private:
    char priv_mem;
    
    */
    int f(){return prot_mem;}
    //char s(){return priv_mem;} !error!
    void memfcn(base &b) {b=*this;}
};
class Prot_Derv : protected base{
    /*
protected:
    void pub_mem(){std::cout<<"running"};
protected:
    int prot_mem;
private:
    char priv_mem;
    */
    int f(){return prot_mem;}
    //char s(){return priv_mem;} !error!
    void memfcn(base &b) {b=*this;}
};
class Pub_Derv_From_Public :public Pub_Derv{
    int use_base(){return prot_mem;}
    void memfcn(base &b) {b=*this;}
};
class Pub_Derv_From_Private : public Priv_Derv{
//    int use_base(){ return prot_mem;}
};
class Pub_Derv_From_Protected:public Prot_Derv{
    int use_use(){return prot_mem;}
    void memfcn(base &b) {b=*this;}
};