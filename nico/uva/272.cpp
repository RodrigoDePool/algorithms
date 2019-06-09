/* AC */
#include <iostream>

using namespace std;


int main(){
	string lines;
	
	int open = 1;
	char chr;

	while(scanf("%c", &chr) != EOF){
		if(chr == '"'){
			printf( (open) ? "``" : "''");
			open = 1 - open;
		}else{
			printf("%c", chr);
		}			
	}

	return 0;
}

