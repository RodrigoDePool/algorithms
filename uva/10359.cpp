#include <iostream>
#include <vector>
using namespace std;
// ERROR DE PRECISION
int main(){
    int num;
    vector<int> sols(250);
    sols[0]=1;
    sols[1]=3;
    for(int i=2; i<250; i++)
        sols[i]=sols[i-1]+2*sols[i-2];
    while(!cin.eof() && cin >> num){
        cout << sols[num-1] << endl;    
    } 
    return 0;
}
