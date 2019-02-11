#include <iostream>
#include <vector>
using namespace std;
// WRONG ANSWER, PROBLEMA DE PRECISION
int main(){
    long long value;
    vector<long long> solutions(1001,0);
    solutions[0]=1;
    solutions[1]=2;
    solutions[2]=5;
    solutions[3]=13;
    for(long long i=4; i<=1000; i++){
        solutions[i]=2*solutions[i-1]+solutions[i-2]+solutions[i-3]; 
    }
    while(cin>>value){
        cout << solutions[value] << endl;
    }
    return 0;
}
