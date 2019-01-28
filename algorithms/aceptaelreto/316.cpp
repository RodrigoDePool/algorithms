#include <iostream>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    for(int ww=0; ww<cases; ww++){
        int days;
        cin >> days;
        int inicurr, aux;
        int initotal, fintotal;
        int maxcurr=0, maxtotal=0;
        for(int i=0; i<days; i++){
            cin >> aux;
            if(aux>=aux+maxcurr){
                maxcurr=aux;
                inicurr=i;
            }else{
                maxcurr+=aux;
            }

            if(maxcurr>maxtotal){
                maxtotal=maxcurr;
                initotal=inicurr;
                fintotal=i;
            }else if(maxcurr==maxtotal){
                if(i-inicurr<fintotal-initotal){
                    initotal=inicurr;
                    fintotal=i;
                }
            }
        }
        cout << (initotal+1) << " " << (fintotal+1) << endl;
    }

    return 0;
}
