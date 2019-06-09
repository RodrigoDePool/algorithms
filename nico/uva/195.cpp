/* AC */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string word;
int t;

bool comparator(char a, char b){
	if(tolower(a) == tolower(b))
		return a < b;
	return tolower(a) < tolower(b);
}

int main(){

	cin >> t;

	while(t--){
		cin >> word;

		sort(word.begin(), word.end(), comparator);
		do{
			cout << word << endl;
		}while(next_permutation(word.begin(), word.end(), comparator));
	}

	return 0;
}