#include <iostream>
#include <cmath>
using namespace std;

long long int s, p, n, c, d, x, y, o;

int main(){
	cin >> s >> p;

	while (s != 0 || p != 0){
		// Cada mitad de espiral añade el siguiente número impar de casillas
		// Paro cuando en c tengo la última mitad de espiral que no pisa p
		for (n = c = 0; c+2*n+1 < p; c += 2*(n++)+1);
		p -= c+1;

		d = ceil(n/2.0);

		//cout << "p: " << p << ", n: " << n << ", d: " << d;

		if (n%2 == 0){
			if (p < n){
				x = p-n/2;
				y = -d;
			} else if (p > n){
				p -= n;
				x = d;
				y = p-n/2;
			} else {
				x = d;
				y = -d;
			}
		} else {
			if (p < n){
				x = -(p-n/2);
				y = d;
			} else if (p > n){
				p -= n+1;
				x = -d;
				y = -(p-n/2);
			} else {
				x = -d;
				y = d;
			}
		}

		// Estas coordenadas son con la primera casilla como origen
		// Si les sumo las coordenadas del origen respecto a la esquina, quedan las que queremos
		o = ceil(s/2.0);
		//cout << ", o: " << o << endl;

		cout << "Line = " << y+o << ", column = " << x+o << '.' << endl;


		cin >> s >> p;
	}

	return 0;
}