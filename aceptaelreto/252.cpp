#include <string>
#include <iostream>
using namespace std;
int main(){
    string inp;
    getline(cin, inp);
    while(inp!="XXX"){
        int p1, p2;
        bool sol;
        p1=0;
        p2=inp.length()-1;
        sol=true;
        while(p1<p2){
            if(inp[p1]==' '){
                p1++;
            }else if(inp[p2]==' '){
                p2--;
            }else if(tolower(inp[p1])==tolower(inp[p2])){
                p1++;
                p2--;
            }else{
                sol=false;
                break;
            }
        }
        if(sol)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
        getline(cin, inp);
    }
    return 0;
}
