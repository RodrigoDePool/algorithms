#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int cases, chars, lines, cents;
    char paid;
    cin >> cases;
    for(int i=0; i<cases;i++){
	unordered_map<char,int> paidChars;
	cin >> chars;
	for(int j=0; j<chars;j++){
	    cin >> paid >> cents;
	    paidChars[paid]=cents;
	}
	cin >> lines;
	cin.ignore();
	int total=0;
	for(int j=0;j<lines;j++){
	    string line;
	    getline(cin, line);
	    for(int k=0;k<line.length();k++){
		if(paidChars.count(line[k])==1){
		    total+=paidChars[line[k]];
		}
	    }
	}
	printf("%d.%02d$\n",total/100,total%100);	
    }
    return 0;
}
