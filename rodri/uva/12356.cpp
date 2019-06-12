#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
#define left(x,i) x[i].first
#define right(x,i) x[i].second


int main(){
  int b,s;
  cin >> s >> b;
  while(b!=0 || s!=0){
    vector<ii> sold = vector<ii>(s);
    sold[0]=ii(-1,1);
    for(int i=1;i<s-1;i++)
      sold[i]=ii(i-1, i+1);
    sold[s-1]=ii(s-2,-1);
    int l,r;
    for(int i=0;i<b;i++){
      cin >> l >> r;
      l-=1;
      r-=1;
      if(left(sold, l)>=0){
        sold[left(sold,l)] = ii(left(sold,left(sold,l)),
                                right(sold, r));
        cout << left(sold,l)+1;
      }else
        cout << "*";
      if(right(sold, r)>=0){
        sold[right(sold,r)] = ii(left(sold,l),
                                 right(sold, right(sold,r)));
        cout << " "<< right(sold,r)+1<< endl;
      }else
        cout << " *\n";
    }
    cout << "-" << endl;
    cin >> s >> b;
  }
  return 0;
}
