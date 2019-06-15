#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, i;
vector<int> v;

int main(){
	n = 0;
	while(cin >> i){
		v.push_back(i);
		n++;
		if (n%2){
			nth_element(v.begin(), v.begin()+n/2, v.end());
			cout << v[n/2] << endl;
		} else {
			nth_element(v.begin(), v.begin()+n/2-1, v.end());
			i = v[n/2-1];
			nth_element(v.begin(), v.begin()+n/2, v.end());
			cout << (i + v[n/2])/2 << endl;
		}

	}


	return 0;
}