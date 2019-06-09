/* AC */

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string line;
int t, a, ans, num_case=0;

int main(){
	cin >> t;
	cin.ignore();
	
	while(t--){
		getline(cin, line);
		stringstream ss(line);
		ans = -1e6;
		while(ss >> a) ans = max(ans, a);
		printf("Case %d: %d\n", ++num_case, ans);
	}

	return 0;
}