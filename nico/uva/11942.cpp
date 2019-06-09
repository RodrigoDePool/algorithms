/* AC */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
vector<int> A;
string line;
int n, aux;

int main(){
	cin >> n;
	cin.ignore();

	printf("Lumberjacks:\n");

	while(n--){
		getline(cin, line);
		stringstream ss(line);
		A.clear();

		while(ss >> aux) A.push_back(aux);

		if(is_sorted(A.begin(), A.end()) or is_sorted(A.rbegin(), A.rend()))
			printf("Ordered\n");
		else
			printf("Unordered\n");


	}

	return 0;
}