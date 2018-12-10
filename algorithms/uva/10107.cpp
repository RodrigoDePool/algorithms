#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    long x, sol, aux;
    priority_queue<long> lowq;
    priority_queue<long, vector<long>, greater<long>> highq;

    cin >> x;
    lowq.push(x);
    cout << x << endl;
    while(cin >> x){
        if(x<=lowq.top()){
            lowq.push(x);
            if(lowq.size()>highq.size()+1){
                aux = lowq.top();
                lowq.pop();
                highq.push(aux);
            }
        }else{
            highq.push(x);
            if(highq.size()>lowq.size()+1){
                aux = highq.top();
                highq.pop();
                lowq.push(aux);
            }
        }
        
        if(lowq.size()==highq.size()){
            sol = (lowq.top()+highq.top())/2;
            cout << sol << endl;
        }else if(lowq.size()>highq.size()){
            cout << lowq.top() << endl;
        }else{
            cout << highq.top() << endl;
        }
    }
    return 0;
}