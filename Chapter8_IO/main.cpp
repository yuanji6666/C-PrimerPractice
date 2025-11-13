#include "stream.h"
int main(){
    ifstream strm("2.txt",ios::in);
    vector<string> v;
    readFile(strm,v);
    for(auto IT=v.begin();IT!=v.end();IT++){
        cout<<*IT<<' ';
    }
    for(auto IT=v.begin();IT!=v.end();IT++){
        cout<<*IT<<' ';
    }
    return 0;

    

}
