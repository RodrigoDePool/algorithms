#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;

vector <int>registros(10);
int o;
vector<int> operar(int op, vector<int>memoria){
    int num, d, n;
    num = op/100;
    d = (op%100)/10;
    n = (op%10);
    if(num==2){
        registros[d]= n % 1000;
    }else if(num==3){
        registros[d]=(registros[d]+n)%1000;
    }else if(num==4){
        registros[d]=(registros[d]*n)%1000;
    }else if(num==5){
        registros[d]=registros[n]%1000;
    }else if(num==6){
        registros[d]=(registros[d]+registros[n])%1000;
    }else if(num==7){
        registros[d]=(registros[d]*registros[n])%1000;
    }else if(num==8){
        registros[d]=memoria[registros[n]];
    }else if(num==9){
        memoria[registros[n]]=registros[d];
    }else if(num==0){
        if(registros[n]!=0){
            o = registros[d];
        }
    }
    return memoria;
}


void simular(){
    int val, i, operaciones;
    for(i=0;i<10;i++){
        registros[i]=0;
    }

    vector <int>memoria(1000, 0);
    char dig1, dig2, dig3;
    for(i=0; i<1000; i++){
        cin.get(dig1);
        cout << dig1 << "dadas" << endl;
        if(dig1==0) break;
        cin.get(dig2);
        cin.get(dig3);
        val = 100*(int(dig1)-48)+10*(int(dig2)-48)-int(dig3)-48;
        memoria[i]=val;
    }

    o=0;
    int ops=0;
    val=memoria[o];
    while(val!=100){
        o++;
        memoria=operar(val, memoria);
        ops++;
        val=memoria[o];
    }
    cout<< ops <<endl;
}

int main(){
    int cases;
    char blank='1';
    cin >> cases;
    
    for(int i=0; i<cases; i++){
        simular();
    }
    return 0;
}