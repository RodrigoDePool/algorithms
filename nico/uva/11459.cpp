/* AC */
#include <iostream>
#include <vector>

using namespace std;
int t, src, dest, roll, ladders_snakes, die_rolls, ret, num_players, player_num;
vector<int> board(101);
vector<int> player_pos;
bool win;


int main(){
	cin >> t;

	while(t--){
		
		for(int i=0; i<101; i++) board[i] = i;
		
		cin >> num_players >> ladders_snakes >> die_rolls;

		player_pos.clear();
		player_pos.resize(num_players+1, 1);

		for(int i=0; i<ladders_snakes; i++){
			cin >> src >> dest;
			board[src] = dest;
		}
		
		win = false;

		for(int i=0; i<die_rolls; i++){
			cin >> roll;
			if(!win){
				player_num = (i % num_players)+1;
				
				player_pos[player_num] += roll;
				if(player_pos[player_num] >= 100){
					player_pos[player_num] = 100;
					win = true;
				}
				player_pos[player_num] = board[ player_pos[player_num] ];
				if(player_pos[player_num] >= 100){
					player_pos[player_num] = 100;
					win = true;
				}
			}
		}

		for(int i=1; i<=num_players; i++)
			printf("Position of player %d is %d.\n", i, player_pos[i]);
	}


	return 0;
}