/* AC */
#include <iostream>

using namespace std;
int a, b, c, n, m, ans;

int solve(){
	if (a == 1) return b;
	if (a == 2){
		c = b % 4;
		if(c) return b/4*4 + ((c > 1) ? 4 : 2);
		else return b/4*4;
	}
	return (a*b+1)/2;
}

int main(){

	while((cin >> n >> m) and (n and m)){
		a = min(n, m), b = max(n, m);
		printf("%d knights may be placed on a %d row %d column board.\n", solve(), n, m);
	}

	return 0;
}