#include "stream.h"
istream & func(istream&is){

    while(!is.eof()){
        char c='\0';
        is>>c;
        cout<<c;
    }
    is.clear();
    return is;
}
void readFile(istream& is,vector<string>& v){
    string line;
    istringstream linestrm;
    while(getline(is,line)){cout<<"into_loop";
        linestrm.str(line);
        linestrm.clear();
        string word;
        while(linestrm>>word){cout<<"into_loop2";
            v.push_back(word);
        }

    }
}
