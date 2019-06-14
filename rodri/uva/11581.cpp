#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> grid;
grid emptygrid(){
  grid c;
  for(int i=0;i<3;i++)
    c.push_back(vector<int>(3,0));
  return c;
}
grid copy(grid a){
  grid c=emptygrid();
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      c[i][j]=a[i][j];
  }
  return c;
}
grid f(grid a){
  grid c=emptygrid();
  c[0][0]=(a[0][1]+a[1][0])%2;
  c[0][1]=(a[0][0]+a[1][1]+a[0][2])%2;
  c[0][2]=(a[0][1]+a[1][2])%2;

  c[1][0]=(a[1][1]+a[0][0]+a[2][0])%2;
  c[1][1]=(a[1][0]+a[1][2]+a[0][1]+a[2][1])%2;
  c[1][2]=(a[0][2]+a[2][2]+a[1][1])%2;

  c[2][0]=(a[2][1]+a[1][0])%2;
  c[2][1]=(a[2][0]+a[1][1]+a[2][2])%2;
  c[2][2]=(a[2][1]+a[1][2])%2;
  return c;
}
int main(){
  int t;
  int aux;
  cin>>t;
  while(t--){
    grid inp=emptygrid();
    for(int i=0;i<3;i++){
      cin >> aux;
      inp[i][0]=aux/100;
      inp[i][1]=(aux%100)/10;
      inp[i][2]=(aux%100)%10;
    }

    grid fast, slow;
    slow=copy(inp);
    fast=f(inp);
    while(slow!=fast){
      slow=f(slow);fast=f(f(fast));
    }

    int i=-1;
    grid curr=copy(inp);
    while(curr!=slow){
      slow=f(slow); curr=f(curr);
      i++;
    }
    cout<<i<<endl;

  }
  return 0;
}
