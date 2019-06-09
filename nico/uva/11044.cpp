/* AC */
#include <iostream>

using namespace std;
int t, n, m;
int main(){

	cin >> t;
	while(t--){
		cin >> n >> m;
		cout << (n/3) * (m/3) << endl;
	}
	return 0;
}