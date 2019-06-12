#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int n, m, p;
float count;
string s;
char c;
map<char, int> t;

int main(){
	cin >> n;

	while (n--){
		t.clear();
		count = 0;

		cin >> m;
		while (m--){
			cin >> c >> p;
			t[c] = p;
		}

		cin >> m;
		cin.ignore();
		while (m--){
			getline(cin, s);
			// for (char &i : s){
			// 	count += t[i];
			// }
			for (int i = 0; i < s.length(); i++){
				count += t[s[i]];
			}
		}

		cout << fixed << setprecision(2) << count/100 << '$' << endl;
	}
	
	return 0;
}