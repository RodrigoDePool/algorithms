#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int s, b, l, r, i;
list<int> line;
list<int>::iterator it;

int main(){
	cin >> s >> b;
	while (s != 0 || b != 0){
		line.clear();
		for (i = 1; i <= s; i++) line.push_back(i);
		while (b--){
			cin >> l >> r;
			if (l == line.front()){
				it = line.begin();
				cout << "* ";
			} else {
				for (it = line.begin(); *it < l; it++);
				cout << *prev(it, 1) << ' ';
			}

			for (; it != line.end() && *it <= r; line.erase(it++));

			if (it == line.end()){
				cout << '*' << endl;
			} else {
				cout << *it << endl;
			}
		}
		cout << '-' << endl;

		cin >> s >> b;
	}


	return 0;
}