#include <iostream>
#include <string>
using namespace std;
class Quote {
public:
    Quote()=default;
    Quote(const string &book,double book_price)
    :bookNo{book},price{book_price}{}
    string isbn() const {return bookNo;}
    virtual double net_price(unsigned n) const {return n*price;}
    virtual ~Quote()=default;
private:
    string bookNo;
protected:
    double price=0.0;
    
};
class Bulk_quote: public Quote{
public:
    Bulk_quote()=default;
    Bulk_quote(const string &book,double book_price,
    unsigned qty,double disc):
    Quote(book,book_price),min_qty{qty},disc{disc}{}
    
    double net_price(unsigned n) const override{
        if(n>=min_qty){
            cout<<"discout book!"<<endl;
            return n*(1-disc)*price;
        }
        else return n*price;
    }
private:
    double disc;
    unsigned min_qty;

};
double print_total(ostream & ,const Quote & ,unsigned);
