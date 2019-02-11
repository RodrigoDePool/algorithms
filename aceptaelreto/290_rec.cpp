#include <iostream>
using namespace std;
int maxv;
void solve(int d){
    char c;
    cin >> c;
    if(c=='.'){
        if(d>maxv) maxv=d; 
        return; 
    } 
    solve(d+1);
    solve(d+1);
    return;
}
int main(){
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++){
        cin.ignore();
        maxv=0;
        solve(0);
        cout << maxv << endl;
    }
    return 0;
}
