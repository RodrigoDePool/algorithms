/* AC */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string word;

int main(){

	while((cin >> word) and (word != "#")){
		printf((next_permutation(word.begin(), word.end())) ? "%s\n" : "No Successor\n", word.c_str() );
	}

	return 0;
}