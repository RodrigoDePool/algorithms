#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int l, c, n, i;
// string line;
stringstream ss;
bitset<3000> bs;

int main(){
	while(cin >> n){
		bs.reset();

		cin >> l;

		if (n == 1){
			cout << "Jolly" << endl;
			continue;
		}
		
		i = n-1;
		while(i--){
			cin >> c;
			if (abs(c-l) >= n || c == l) break;
			bs.set(abs(c-l)-1);
			l = c;
		}

		if (bs == bitset<3000>((1 << n-1)-1)) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}