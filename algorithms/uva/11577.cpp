#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// FALTA SUBIR PERO FUNCIONA CON LOS CASOS DE PRUEBA MIOS
// PROBAR CON EL DEL ENUNCIADO
int main(){
    int cases;
    string inp;
    cin >> cases;
    cin.ignore();

    for(int i=0; i<cases;i++){
	vector<int> counter(26,0);
	getline(cin, inp);
	int max = -1;
	int current;
	for(int j=0; j<inp.length();j++){
	    if(inp[j]>=97 && inp[j]<=122){
		// Lower case letter
		current = inp[j]-'a';
		counter[current]++;
	    }else if(inp[j]>=65 && inp[j]<=90){
		// Upper case letter
		current = inp[j]-'A';
		counter[current]++;
	    }
	    if(counter[current]>max)
		max = counter[current]; 
	}
	// iterate the whole array to get maxes (only 26)
	char aux;
	for(int j=0; j<26;j++){
	    if(counter[j]==max){
		aux = j+'a';
		cout << aux;
	    }
	}
	cout << endl;
	
    }
    return 0;
}
