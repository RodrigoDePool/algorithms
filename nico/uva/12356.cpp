/* AC */
#include <iostream>
#include <vector>

using namespace std;


struct Node{
	int left, right;	
};

Node node[100000+5];
int S, B, l, r;
int main(){

	while((cin >> S >> B) and (S and B)){
		for(int i=1; i<=S; i++){
			node[i].left = i-1;
			node[i].right = i+1;
		}
		node[S].right = 0;

		for(int i=0; i<B; i++){
			cin >> l >> r;
			printf((node[l].left) ? "%d " :  "* ", node[l].left);
			printf((node[r].right) ? "%d\n" : "*\n", node[r].right);
			
			node[ node[l].left ].right = node[r].right;
			node[ node[r].right ].left = node[l].left;
		}
		printf("-\n");
	}

	return 0;
}