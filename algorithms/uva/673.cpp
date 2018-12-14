#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    cin.ignore();
    for(int i=0;i<cases; i++){
        string inp;
        stack<char> curr;
        bool finn=false;
        char c;
        getline(cin, inp);
        istringstream iss(inp);
        if(inp.length()==0){
            cout << "Yes" << endl;
            finn=true;
        }
        while(!finn && iss>>c){
            if(c=='(' || c=='['){
                curr.push(c);
            }else if(c==')' || c == ']'){
                if(curr.size()==0){
                    cout << "No" << endl;
                    finn=true;
                }else if(( c==')' && curr.top()=='(' ) || ( c==']' && curr.top()=='[' )){
                    curr.pop();
                }else{
                    cout << "No" << endl;
                    finn=true;
                }
            }else{
                cout << "No" << endl;
                finn=false;
            }
        }
        if(!finn){
            if(curr.size()==0){
                cout << "Yes" << endl;
            }else{
                cout <<  "No" << endl;
            }
        
        }
    }
    
    return 0;


}
