/* AC */
#include <iostream>
using namespace std;
int n, t;

int solve(){
	int ans = (n * 63 + 7492) * 5 - 498;
	if (ans < 0 ) ans *= -1;
	return (ans/10)%10;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cout << solve() << endl;
	}

	return 0;
}