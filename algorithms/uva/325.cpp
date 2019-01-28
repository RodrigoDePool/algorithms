#include <regex> 
#include <string>
#include <iostream>
using namespace std;
int main(){
    string line;
    regex decimal("(\\+|-)?[[:d:]]+\\.[[:d:]]+((e|E)(-|\\+)?[[:d:]]+)?");
    regex exponent("(\\+|-)?[[:d:]]+(\\.[[:d:]]+)?((e|E)(-|\\+)?[[:d:]]+)");
    while(true){
	getline(cin,line);
	line = regex_replace(line, regex("(^ +| +$)"), "");	
	if(line=="*") break;
	if(regex_match(line, decimal) || regex_match(line,exponent))
	    cout << line << " is legal." << endl;	
	else
	    cout << line<<" is illegal." << endl;	
    }
    return 0;
}
