#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
int n;
unordered_map<int,int> corners;
unordered_map<int,int> potencies;
int potency(int k){
    int curr=k;
    int total=0;
    for(int i=0; i<n;i++){
      curr=(1<<i) ^ k;
      total+=corners[curr];
    }
    return total;
}

int main(){
  while(!cin.eof() && cin >> n){
    corners.clear();
    potencies.clear();
    for(int i=0;i<pow(2,n);i++)
      cin >> corners[i];
    for(int i=0;i<pow(2,n);i++)
      potencies[i]=potency(i);

    int max=-1;
    int curr;
    for(int i=0;i<pow(2,n);i++){
      for(int j=0;j<n;j++){
        curr=(1<<j) ^ i;
        if(potencies[i]+potencies[curr]>max)
          max = potencies[i]+potencies[curr];
      }
    }

    cout << max << endl;
  }
  return 0;
}
