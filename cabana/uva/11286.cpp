#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m, c;
vector<int> courses(5);
map<vector<int>, int> counter;
map<vector<int>, int>::iterator it;

int main(){
	cin >> n;
	while (n){
		counter.clear();
		while (n--){
			cin >> courses[0] >> courses[1] >> courses[2] >> courses[3] >> courses[4];
			sort(courses.begin(), courses.end());
			counter[courses]++;
		}
		m = 0;
		c = 0;
		for (it = counter.begin(); it != counter.end(); it++){
			if (it->second == m){
				c+=it->second;
			}
			if (it->second > m){
				m = it->second;
				c = it->second;
			}
		}
		cout << c << endl;
		cin >> n;
	}

	return 0;
}