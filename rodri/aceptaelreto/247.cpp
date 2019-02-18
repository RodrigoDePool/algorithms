#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  bool sol;
  cin >> n;
  while (n != 0) {
    int prev, curr;
    prev = -1;
    sol = true;
    for (int i = 0; i < n; i++) {
      cin >> curr;
      if (curr <= prev)
        sol = false;
      prev = curr;
    }
    if (sol)
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
    cin >> n;
  }
  return 0;
}
