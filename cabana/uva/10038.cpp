#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int l, c, n, i;
string line;
stringstream ss;
bitset<3000> bs;

int main(){
	getline(cin, line);

	while(!line.empty()){
		ss.clear();
		ss.str(line);
		bs.reset();

		ss >> n;
		ss >> l;

		if (n == 1){
			cout << "Jolly" << endl;
			continue;
		}
		
		i = n-1;
		while(i--){
			ss >> c;
			bs.set(abs(c-l)-1);
			l = c;
		}

		if (bs == bitset<3000>((1 << n-1)-1)) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
		getline(cin, line);
	}

	return 0;
}