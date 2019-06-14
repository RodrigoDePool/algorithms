#include <iostream>
#include <string>
using namespace std;
string inp;
string slice(string in, int i, int j){
  string a="";
  for(int x=i;x<=j;x++)
    a+=in[x];
  return a;
}
string reverse(string a){
  string c="";
  for(int i=a.length()-1;i>=0;i--)
    c+=a[i];
  return c;
}
string solve(int ini, int fin){
  if(ini==fin) return "";
  string sol=solve(ini+1,fin);
  if(sol!="")
    return sol;

  for(int bigger=fin; bigger>ini;bigger--){
    if(inp[bigger]>inp[ini]){
      sol=inp[bigger];
      sol+=reverse(slice(inp,ini+1,bigger-1)+inp[ini]+slice(inp,bigger+1,fin));
      return slice(inp,0,ini-1)+sol;
    }
  }
  return "";
}
int main(){
  while(cin >> inp && inp!="#"){
    string sol = solve(0,inp.length()-1);
    if(sol!="")
      cout << sol << endl;
    else
      cout << "No Successor" << endl;
  }
  return 0;
}
