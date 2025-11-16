#include "Quote.h"
double print_total(ostream & os,const Quote &item,unsigned n){
    double ret=item.net_price(n);
    os<<"ISBN:"<<item.isbn()<<endl
    <<"sold: "<<n<<endl
    <<"total_due: "<<ret<<endl;
    return ret;
}
