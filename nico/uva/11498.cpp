/* AC */
#include <iostream>
#include <string>
using namespace std;
int a, b, x, y, n;

string solve(){
	if(x == a or y == b) return "divisa";
	if (a > x) return (b > y) ? "NE" : "SE" ;
	return (b > y) ? "NO" : "SO"; 
}

int main(){
	
	while(cin >> n and n){
		cin >> x >> y;
		for(int i=0; i<n; i++){
			cin >> a >> b;
			cout << solve() << endl;
		}
	}

	return 0;
}