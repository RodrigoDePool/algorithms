/* AC */
#include <iostream>
#include <algorithm>


using namespace std;

int integers, budget, hotels, weeks, price, space, ans, room, max_room, cost;


int main(){

	while(cin >> integers >> budget >> hotels >> weeks){

		cost = budget + 1;
		for(int i=0; i<hotels; i++){
			cin >> price;
			max_room = 0;
			for(int j=0; j<weeks; j++){
				cin >> room;
				max_room = max(room, max_room);
			}
			cost = min(cost, (max_room >= integers) ? price * integers : budget + 1 );
		}
		printf((cost == budget + 1)? "stay home\n" : "%d\n", cost);

	}

	return 0;
}