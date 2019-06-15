/* TLE */
#include <iostream>
using namespace std;

long long int col, row, turn, sz, p, i;

void solve(){
	long long int right = 1, up = 1, left = 2, down = 2;
	turn = 0;
	row = sz/2, col = sz/2;
	p--;
	while(true){
		if(turn == 0){ //right
			for( i=0; i<right; i++){
				if(p == 0) return;
				p--; col++;
				
			}
			right += 2;
		}else if(turn == 1){ //up
			for( i=0; i<up; i++){
				if(p == 0) return;
				p--; row--;
				
			}
			up += 2;
		}else if(turn == 2){ //left
			for( i=0; i<left; i++){
				if(p == 0) return;
				p--; col--;
				
			}
			left += 2;
		}else{ //down
			for( i=0; i<down; i++){
				if(p == 0) return;
				p--; row++;
				
			}
			down += 2;
		}
		turn = (turn + 1) % 4;
	}
}

int main(){

	while((cin >> sz >> p) and (sz and p)){
		solve();
		printf("Line = %lld, column = %lld.\n", col+1, row+1);
	}
	return 0;
}