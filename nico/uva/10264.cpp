/* AC */
#include <iostream>
#include<vector>

using namespace std;

int weight[1 << 15], potency[1 << 15], N, vertices, i, j, ans;

int main(){
	while(cin >> N){

		vertices = 1 << N;
		for( i = 0; i<vertices; i++){
			cin >> weight[i];
		}
		//connect vertices
		for(i = 0; i<vertices; i++){
			potency[i] = 0;
			for(j = 0; j<N; j++){
				potency[i] += weight[ i ^ (1 << j)];
			}
		}
		//calculate sum
		ans = 0;
		for(i = 0; i<vertices; i++){
			for(j = 0; j<N; j++){
				ans = max(ans, potency[i] + potency[ i ^ (1 << j)]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}