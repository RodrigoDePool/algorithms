/* AC */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


class Contestant{
	public:
		vector<int> problems;
		vector<bool> solved;
		int id;
		
		Contestant(): problems(11, 0), solved(11, false) , id(0){}
		
		void add_id(int a){id = a;}
		void add(int p, int t, char label){
			if(label == 'C'){
				problems[p] += (!solved[p]) ? t : 0;
				solved[p] = true;
			}else if(label == 'I'){
				problems[p] += (!solved[p]) ? 20 : 0;
				
			}
		}

		int problems_solved() const{
			int ans = 0;
			for(int i=1; i<solved.size(); i++){
				if(solved[i]) ans++;
			}
			return ans;
		}
		int total_time() const{
			int ans=0;
			for(int i=1; i<problems.size(); i++)if(solved[i]) ans += problems[i];
			return ans;
		}
		
		bool operator< (const Contestant &b) const {
			if(this->problems_solved() == b.problems_solved()){
				if(this->total_time() == b.total_time()){
					return this->id < b.id;
				}else{
					return this->total_time() < b.total_time();
				}
			}else{
				return this->problems_solved() > b.problems_solved();
			}
		}
};


int main(){
	int t, c, p, cases;
	string L;
	string line;
	cin >> cases;
	cin.ignore(2);
	//getline(cin, line);
	bool second = false;
	while(cases--){
		vector<Contestant> contestant(105);
		printf((second)?"\n": "" );
		while(getline(cin, line) and line != ""){
			stringstream ss(line);
			ss >> c >> p >> t >> L;
			ss.ignore();
			contestant[c].add_id(c);
			contestant[c].add(p, t, L[0]);
		}

		sort(contestant.begin(), contestant.end());
		
		for(int i=0; i<105; i++){
			if(contestant[i].id){
				int p = contestant[i].problems_solved(), t = contestant[i].total_time();

				printf("%d %d %d\n", contestant[i].id,  p, t);
			}
		}
		
		second=true;

	}

	return 0;
}