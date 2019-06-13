/* AC */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string line;
vector<int> A;
vector<bool> R;
int n;

bool solve(){
	
	for(int i=0; i<A.size()-1; i++){
		int diff = abs(A[i]-A[i+1]);
		if(diff >= 1 and diff < n) R[diff] = true;
	}

	for(int i=1; i<R.size(); i++){
		if(R[i] == false) return false;
	}
	return true;
}

int main(){
	while(getline(cin, line)){
		A.clear(); R.clear();
		stringstream ss(line);
		ss >> n;
		A.resize(n); R.resize(n, false);
		for(int i=0; i<n; i++) ss >> A[i];
		
		printf( (solve()) ? "Jolly\n" : "Not jolly\n");
	}

	return 0;
}