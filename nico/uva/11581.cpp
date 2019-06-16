/* AC */
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> grid;

grid empty(){
	grid A;
	for(int i=0; i<3; i++) A.push_back(vector<int>(3,0));
	return A;
}

grid copy(grid A){
	grid B = empty();
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			B[i][j] = A[i][j];
	return B;
}

grid f(grid B){
	grid A = empty();
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			A[0][0]=(B[0][1]+B[1][0])%2;
  			A[0][1]=(B[0][0]+B[1][1]+B[0][2])%2;
			A[0][2]=(B[0][1]+B[1][2])%2;

			A[1][0]=(B[1][1]+B[0][0]+B[2][0])%2;
			A[1][1]=(B[1][0]+B[1][2]+B[0][1]+B[2][1])%2;
			A[1][2]=(B[0][2]+B[2][2]+B[1][1])%2;

			A[2][0]=(B[2][1]+B[1][0])%2;
			A[2][1]=(B[2][0]+B[1][1]+B[2][2])%2;
			A[2][2]=(B[2][1]+B[1][2])%2;
		}
	}
	return A;
}

int t, ans, aux;


int main(){
	cin >> t;

	while(t--){
		grid O = empty();
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				scanf("%1d", &aux);
				O[i][j] = aux;
			}
		}

		grid slow = copy(O), fast = copy(O);
		
		do{
			slow = f(slow); fast = f(f(fast));
		}while(slow != fast);

		ans = -1;
		while(slow != O){
			slow = f(slow);
			O = f(O);
			ans++;
		}
		printf("%d\n", ans);


	}

	return 0;
}