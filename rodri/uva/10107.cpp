#include <queue>
#include <iostream>
using namespace std;
int main(){
  int n;
  priority_queue<int> lowpq;
  priority_queue<int> highpq;

  int median;
  cin >> n;
  median=n;
  cout << median<< endl;
  int turn=1;

  while(!cin.eof() && cin >> n){
    turn++;
    if(turn%2==0){
      if(median<n){
        lowpq.push(median);
        highpq.push(-n);
      }else{
        lowpq.push(n);
        highpq.push(-median);
      }
      median=(lowpq.top()+(-highpq.top()))/2;
    }else{
      if(n>lowpq.top() && n < -highpq.top()){
        median=n;
      }else if(n<lowpq.top()){
        median=lowpq.top();
        lowpq.pop();
        lowpq.push(n);
      }else{
        median=-highpq.top();
        highpq.pop();
        highpq.push(-n);
      }
    }
    cout << median << endl;
  }
  return 0;
}
