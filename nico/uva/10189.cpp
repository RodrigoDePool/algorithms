/* AC */
#include <iostream>

using namespace std;

char B[101][101];
int N[101][101]={0};
int dx[] = {1,  1,  0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1,  0,  1, 1, 1};
int r, c, field;
bool second;

bool save(int x, int y){ return (x >= 0 and x < r and y >= 0 and y<c) ? true : false;}

void add(int x, int y){ if(save(x, y)) N[x][y]++;}

void solve(){
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(B[i][j] == '*'){
				for(int t=0; t<8; t++){
					add(i+dx[t], j+dy[t]);
				}
			}
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(B[i][j] == '*') printf("*");
			else printf("%d", N[i][j]);

			B[i][j] = '.'; N[i][j]=0;/* reset */ 
		}
		printf("\n");
	}
}



int main(){
	field = 1;
	second = false;

	while( (cin >> r >> c)  and (r and c)){
		if(second){
			printf("\n");
		}
		second = true;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin >> B[i][j];
			}
		}
		
		printf("Field #%d:\n", field++);
		solve();

	}



	return 0;
}