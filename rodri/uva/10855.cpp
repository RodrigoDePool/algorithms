#include <vector>
#include <iostream>
using namespace std;
typedef vector<vector<char>> matc;
int main(){
  int N, n;
  cin >> N >> n;
  while(N!=0){
    matc mN, mn;

    for(int i=0;i<N;i++){
        mN.push_back(vector<char>(N));
        for(int j=0;j<N;j++)
          cin >> mN[i][j];
    }

    for(int i=0;i<n;i++){
        mn.push_back(vector<char>(n));
        for(int j=0;j<n;j++)
          cin >> mn[i][j];
    }

    for(int i=0;i<4;i++){
      int val=0;
      if(i!=0){
        // Rotar
        matc aux;
        for(int i=0;i<n;i++){
            aux.push_back(vector<char>(n));
            for(int j=0;j<n;j++)
              aux[i][j]=mn[n-1-j][i];
        }
        mn=aux;
      }
      // Comprobar
      for(int a=0;a+n-1<N;a++){
        for(int b=0;b+n-1<N;b++){
          bool ok = true;
          for(int c=a;c<a+n;c++){
            for(int d=b;d<b+n;d++){
              if(mN[c][d]!=mn[c-a][d-b]){
                ok=false;
                break;
              }
            }
            if(!ok) break;
          }
          if(ok) val++;
        }
      }
      if(i!=0) cout << " ";
      cout << val;
    }
    cout << endl;


    cin >> N >> n;
  }

  return 0;
}
