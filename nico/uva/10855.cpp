/* AC */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> A, B;
string line;
int n, N;


int check(int x, int y){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(A[i + x][j + y] != B[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
void rotate(){
	char temp = B[0][0];
	for(int i=0; i<n/2; i++){
		for(int j=i; j<n-i-1; j++){
			char temp = B[i][j];
			B[i][j] = B[n-j-1][i];
			B[n-j-1][i] = B[n-i-1][n-j-1];
			B[n-i-1][n-j-1] = B[j][n-i-1];
			B[j][n-i-1] = temp;
		}
	}
}

vector<int> solve(){
	vector<int> ans(4,0);
	for(int t=0; t<4; t++){
		for(int i=0; i<=N-n; i++){
			for(int j=0; j<=N-n; j++)
				ans[t] += check(i, j);
		}
		rotate();
	}
	return ans;
}


int main(){

	while ((cin >> N >> n) and (n and N)){
		A.clear(); B.clear();
		A.resize(N); B.resize(n);

		for(int i=0; i<N; i++){
			cin >> line;
			A[i] = line;
		}
		for(int i=0; i<n; i++){
			cin >> line;
			B[i] = line;
		}
		vector<int> ans = solve();
		printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
	}
	return 0;
}