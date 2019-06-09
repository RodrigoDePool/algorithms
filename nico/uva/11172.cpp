/* AC */
#include <iostream>

using namespace std;
int t, a, b;

int main(){

	cin >> t;
	
	while(t--){
		cin >> a >> b;

		if(a == b) cout << "=\n";
		else if(a > b) cout << ">\n";
		else cout << "<\n";
	}
	return 0;
}