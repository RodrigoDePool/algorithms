#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int resolver(int n, vector<int> input100, int suma){
    int i, times=0;
    int  solup=0, soldown=0;
    int media = suma/n;
    for(int i=0; i<n; i++){
        int diff = input100[i]-media;
        if(diff <= 0){
            soldown += -diff;
        }else{
            solup += diff;
        }
    }
    int sol;
    if(solup > soldown)
        sol = soldown;
    else
        sol = solup;
    printf("$%.2f", double(sol)/100);
    return 0;
}


int main(){
    int n, money100, suma;
    double aux;
    while(cin >> n){
        if(n == 0) break;
        
        vector<int> input100(n);
        suma = 0;
        for(int i=0; i<n; i++){
            cin >> aux;
            input100[i] = int(aux*100);
            suma += input100[i];
        }
        resolver(n, input100, suma);
        cout << endl;
    }   
    return 0;
}