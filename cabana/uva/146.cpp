#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;

int main(){
	getline(cin, s);

	while(s != "#"){
		cout << (next_permutation(s.begin(), s.end()) ? s : "No Successor") << endl;
		getline(cin, s);
	}

	return 0;
}