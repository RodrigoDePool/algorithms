#include <iostream>
#include <stack>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    for(int i=0; i<cases;i++){
        cin.ignore();
        int maxv=0, curr=0;
        char c;
        stack<bool> explored;
        cin >> c;
        if(c!='.'){
            explored.push(false);
            maxv=1;
            curr = 1;
            while(!explored.empty()){
                cin >> c;
                if(c=='\n') break;
                if(c=='.'){
                    if(curr>maxv) maxv=curr;
                    while(explored.top()){
                        explored.pop();
                        curr--;
                        if(explored.empty()) break;
                    }
                    if(!explored.empty()){
                        //Hemos llegado a un false
                        explored.pop();
                        explored.push(true);
                    }
                    
                }else{
                   explored.push(false);
                   curr++;
                }
            }
        }
        cout << maxv << endl;
    }
    return 0;
}
