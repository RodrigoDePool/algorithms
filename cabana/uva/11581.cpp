#include <iostream>
#include <bitset>
#include <string>
#include <array>
using namespace std;

bitset<9> f(bitset<9> g){
	bitset<9> r;
	r[0] = (g[1]+g[3])%2;
	r[1] = (g[0]+g[2]+g[4])%2;
	r[2] = (g[1]+g[5])%2;
	r[3] = (g[0]+g[4]+g[6])%2;
	r[4] = (g[1]+g[3]+g[5]+g[7])%2;
	r[5] = (g[2]+g[4]+g[8])%2;
	r[6] = (g[3]+g[7])%2;
	r[7] = (g[6]+g[4]+g[8])%2;
	r[8] = (g[7]+g[5])%2;
	return r;
}

int n, i, r;
array<int,(1<<9)> check;
string tmp, grid;
bitset<9> g;

int main(){
	cin >> n;
	cin.ignore();

	while (n--){
		getline(cin, tmp);
		grid.clear();

		getline(cin, tmp);
		grid += tmp;
		getline(cin, tmp);
		grid += tmp;
		getline(cin, tmp);
		grid += tmp;

		check.fill(-1);
		i = 0;
		g = bitset<9>(grid);
		check[g.to_ulong()] = 0;
		//cout << g.to_string() << endl;
		while(1){
			g = f(g);
			//cout << g.to_string() << endl;
			i++;
			if ((r = check[g.to_ulong()]) >= 0) break;
			check[g.to_ulong()] = i;
		}
		cout << r-1 << endl;
	}


	return 0;
}