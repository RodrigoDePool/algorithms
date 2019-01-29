#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;

int main(){
    int cases, i, aux, n;
    string inp, num;
    cin >> cases;
    for(i=0;i<cases; i++){
        inp="";
        // Read the indexes line
        while(inp.length()<=0 || inp[0]==' ') getline(cin,inp);
        istringstream iss(inp);
        vector<int> indexes;
        n=-1;
        while(iss>>aux){
            if(aux>n) n=aux;
            indexes.push_back(aux);
        }
        
        vector<string> vals(n);
        getline(cin, inp);
        istringstream iss2(inp);
        int j=0;
        while(getline(iss2, num,' ')){
            vals[indexes[j]-1]=num;
            j++;
        }
        for(string num:vals){
            cout << num << endl;
        }
        if(i!=cases-1) cout<<endl; 
    }
    return 0;
}
