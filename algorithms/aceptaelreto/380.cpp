#include <iostream>
using namespace std;
int main(){
    long n;
    cin >> n;
    while(n>0){
        long suma=0;
        long aux;
        for(long i=0;i<n;i++){
            cin >> aux;
            suma += aux;
        }
        cout << suma << endl;
        cin >> n;
    }
    return 0;
}
