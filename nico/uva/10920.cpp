/* AC */
#include <iostream>
#include <cmath>
using namespace std;

long long int a, p, sz, row, col, center, b, corner;

void solve(){
	a = ceil(sqrt(p)) * ceil(sqrt(p));
	b = sqrt(a);
	center = (sz+1)/2; 
	corner = a-b+1; // number of possible moves

	if(a % 2 == 0){
		row = center + 1 - b/2;
		col = center - b/2;
		while(a != p){
			if(a > corner) row++;
			else col++;
			a--;
		}
	}else{
		row = center + b/2;
		col = center + b/2;
		while(a!= p){
			if(a > corner) row--;
			else col--;
			a--;
		}
	}
}

int main(){

	while((cin >> sz >> p) and (sz and p)){
		solve();
		printf("Line = %lld, column = %lld.\n", row, col);
	}
	return 0;
}