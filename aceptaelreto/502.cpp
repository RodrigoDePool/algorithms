#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    while(!cin.eof() && cin >>n ){
        vector<int> pilas;
        int curr;
        for(int i=0; i<n; i++){
            cin >> curr;
            if(pilas.size()==0 || (pilas[pilas.size()-1]<=curr))
                pilas.push_back(curr);
            else{
                vector<int>::iterator big=upper_bound(pilas.begin(),pilas.end(),curr);
                *big=curr;
            }
        }
        cout << pilas.size() << endl;
    }
    return 0;
}
