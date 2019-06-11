#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

map<string, int> counter;
map<string, int>::iterator it;
int n, s;
string name;

int main(){
	cin >> n;
	cin.ignore();
	getline(cin, name);

	while(n--){
		counter.clear();
		s = 0;
		getline(cin, name);

		while(!name.empty()){
			counter[name]++;
			s++;
			getline(cin, name);
		}

		for (it = counter.begin(); it != counter.end(); it++){
			cout << it->first << ' ' << fixed << setprecision(4) << (float)it->second/s*100 << endl;
		}
		if (n > 0) cout << endl;
	}

	return 0;
}