#include "Quote.h"
int main(){
    Bulk_quote book("redstar",10.5,10,0.2);
    cout<<book.net_price(5,5);
    cout<<book.net_price(5);

    return 0;
}