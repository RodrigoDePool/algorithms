#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int main(){
    double ma, mb, mc;
    double ar, a;

    while(cin >> ma >> mb >> mc){
        a = (ma + mb + mc +0.0)/2;
        if(a-ma<=0 || a-mb<=0 || a-mc<=0){
            cout << "-1.000" << endl;
        }else{
            ar = 4*(sqrt(a*(a-ma)*(a-mb)*(a-mc)))/3;
            int sol=round(ar*1000);
            printf("%d.%03d\n",sol/1000,sol%1000);
        }
    }



}