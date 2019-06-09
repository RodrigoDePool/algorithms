#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, i=0, a, b, c;
vector <int> arr;

int main(){
	cin >> t;
	
	while(t--){
		arr.clear();
		cin >> a >> b >> c;
		arr.push_back(a); arr.push_back(b); arr.push_back(c);
		sort(arr.begin(), arr.end());

		printf("Case %d: %d\n", ++i, arr[1]);
	}

	return 0;
}