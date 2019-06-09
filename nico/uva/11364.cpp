/* AC */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n, location, ans;
vector<int> place;

int main(){

	cin >> t;
	while(t--){
		place.clear();

		cin >> n;
		for(int i=0; i<n; i++){
			cin >> location;
			place.push_back(location);
		}

		sort(place.begin(), place.end());

		ans = 0;
		for(int i=1; i<n; i++) ans += abs(place[i] - place[i-1]);
			
		cout << ans*2 << endl;
	}
	return 0;
}