/* AC */
#include <iostream>

using namespace std;
int a, b, c, d, ans;
int main(){

	while((cin >> a >> b >> c >> d) and (a or b or c or d) ){
		ans = 1080 + ( (a-b+40)%40 + (c-b+40)%40 + (c-d+40)%40 ) * 9;
		cout << ans << endl;
	}
	return 0;
}