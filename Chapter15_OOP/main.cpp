#include "Quote.h" 
int main(){
    Quote Book1("001",9.3);
    Bulk_quote Book2("101",10.1,5,0.2);

    print_total(cout,Book1,5);
    print_total(cout,Book2,15);

    return 0;
}