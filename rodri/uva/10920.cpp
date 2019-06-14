#include <iostream>
using namespace std;
int main(){
  int s,p;
  cin >> s >> p;
  while(s!=0){
    int tam=1;
    int curr=1, line=s/2+1, column=line;
    while(curr<p){
      tam+=2;
      // Value in the right corner of size==tam
      curr = curr + (tam-2)*4+4;
      line++; column++;
    }

    // Top and inf of the square we are handling (line and column)
    int inf=(1+s/2)-tam/2;
    int top=(1+s/2)+tam/2;
    int turn=0;
    while(curr>p){
      if(turn==0){
        if(line==inf){
          turn++;
        }else{
          curr--;
          line--;
        }
      }else if(turn==1){
        if(column==inf){
          turn++;
        }else{
          curr--;
          column--;
        }
      }else if(turn==2){
        if(line==top){
          turn++;
        }else{
          curr--;
          line++;
        }
      }else{
        curr--;
        column++;
      }
    }
    cout << "Line = " << line << ", column = "<< column << ".\n";
    cin >> s >> p;
  }
  return 0;
}
