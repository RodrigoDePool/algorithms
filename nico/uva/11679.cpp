/* AC */
#include <iostream>
#include <vector>
using namespace std;

vector<int> banks;
int bank, debentures, aux, money, debtor, creditor;

int main(){
	while(( cin >> bank >> debentures) and (bank != 0 and debentures != 0)){
		banks.clear();

		for(int i=0; i<bank; i++){cin >> aux; banks.push_back(aux);}

		for(int i=0; i<debentures; i++){
			cin >> debtor >> creditor >> money;
			banks[--debtor] -= money;
			banks[--creditor] += money;
		}
		bool no = false;
		for(int i=0; i<bank and !no; i++) if(banks[i] < 0) no=true;
		printf((no)? "N\n": "S\n");
	}

	return 0;
}