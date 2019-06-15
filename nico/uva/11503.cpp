/* AC */
#include <iostream>
#include <string>
#include <map>
using namespace std;

int p[100001], t, sz[100001], connections, i, r[100001]; //r is for make less operations with union_set
map<string, int> mp;
string A, B;

void make(){
	for(int i=0; i<100001; i++){ p[i] = i; sz[i] = 1; r[i]=0;}
}
int find(int i){return (i == p[i]) ? i : (p[i] = find(p[i])) ;} //with path compression

void union_set(int a, int b){
	int x = find(a), y = find(b);
	if(x != y){
		if(r[x] > r[y]){
			p[y] = x; sz[x] += sz[y]; r[x]++;
		}else{
			p[x] = p[y]; sz[y] += sz[x]; r[y]++;
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		cin >> connections;
		i = 0;
		make(); mp.clear();

		while(connections--){
			cin >> A >> B;
			if(!mp[A]) mp[A] = ++i;
			if(!mp[B]) mp[B] = ++i;

			union_set(mp[A], mp[B]);

			cout << sz[find(mp[A])] << endl;
		}
	}

	return 0;
}