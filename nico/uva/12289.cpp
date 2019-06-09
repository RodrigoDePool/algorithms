/* AC */
#include <iostream>
#include <string>

using namespace std;
int t;
string word, one="one", two="two", three="three";

int check(){
	int o=0, tw=0, th=0;
	for(int i=0; i<word.size(); i++){
		if(i<one.size()) if(word[i] == one[i]) o++;
		if(i<two.size()) if(word[i] == two[i]) tw++;
		if(i<three.size()) if(word[i] == three[i]) th++;
	}
	
	if(o > tw and o> th) return 1;
	else if (tw > o and tw > th) return 2;
	return 3;
}

int main(){
	cin >> t;
	while(t--){
		cin >> word;
		cout << check() << endl;
	}
	return 0;
}