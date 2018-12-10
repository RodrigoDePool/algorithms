#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;


int resolver(int n, vector<int> input100, int suma){
    int i, times=0;
    int  solup=0, soldown=0;
    int c = ceil((0.0+suma)/n);
    int f = floor((0.0+suma)/n);
    // cout << suma << endl;
    // cout << c << " " << f << endl;
    for(int i=0; i<n; i++){
        if((input100[i]-c)>0){
            solup += (input100[i]-c);
        }else if((f-input100[i])>0){
            soldown += (f-input100[i]);
        }
    }
    int sol;
    if(solup > soldown)
        sol=solup;
    else
        sol=soldown;
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
            input100[i] = int(round(aux*100));
            suma += input100[i];
        }
        resolver(n, input100, suma);
        cout << endl;
    }   
    return 0;
}