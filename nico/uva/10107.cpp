/* AC */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int> M;
priority_queue<int, vector<int>, greater<int>> m;

vector<int> three;

int diff, a, b, n;

int my_abs(int a, int b){
	return (a-b)< 0 ? -(a-b) : a-b;
}

void reorder(){
	diff = my_abs(M.size(),m.size());
	
	if(m.size() == 0 and diff == 1) return;
	
	else if(m.size() == 0 and diff == 2){
		m.push(M.top());
		M.pop();
	}
	else if(diff == 1){
		a = M.top(), b = m.top();
		M.pop(); m.pop();
		M.push(min(a, b)); m.push(max(a, b));
	}else{ //diff == 2
		three.clear();
		three.push_back(M.top()); M.pop(); three.push_back(M.top()); M.pop();
		three.push_back(m.top()); m.pop();

		sort(three.begin(), three.end());
		M.push(three[0]); m.push(three[1]); m.push(three[2]);
	}
}
	

int main(){
	while(cin >> n){
		M.push(n);

		reorder();

		if(M.size() > m.size()) cout << M.top() << endl;
		else cout << (M.top() + m.top()) / 2 << endl;
	}

	return 0;
}