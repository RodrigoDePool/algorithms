#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
// Este problema tiene AC en aceptaelreto. Sin embargo, creo
// que debe de haber una solucion mejor. INVESTIGAR

// Una pequena mejora sobre el algoritmo actual podria ser: Convertir la
// estructura datae a pares (bool, enteros) donde el segundo elem del par
// indique la posicion del array hasta donde seguro sabemos que bool es
// true. Esto podria ahorrarnos reescribir valores booleanos en intervalos
// que ya lo tienen. Hay algo aun mejor?
void resolver(vector<int> hs){
    vector<int> cop=hs;
    sort(cop.begin(), cop.end());
    // Corr maps heighs and its normalized value (1, 2, ..., n)
    unordered_map<int, int> corr; 
    for(int i=0; i<cop.size();i++)
        corr[cop[i]]=i;
    
    vector<bool> datae(hs.size(), false);
    int currval, prevval;
    prevval=corr[hs[0]];
    for(int i=0;i<hs.size();i++){
        currval=corr[hs[i]];
        if(datae[currval]){
            cout << "ELEGIR OTRA" << endl;
            return;
        }else if(currval>prevval){
            for(int j=prevval+1; j<currval; j++)
                datae[j]=true; 
        }
        prevval=currval;
    }
    cout << "SIEMPRE PREMIO" << endl;
    return;
}
int main(){
    int n;
    while(!cin.eof() && cin >> n){
        vector<int> hs(n);
        int aux;
        for(int i=0; i<n; i++){
            cin >> aux;
            hs[i]=aux;
        }
        resolver(hs);
    }
    return 0;
}
