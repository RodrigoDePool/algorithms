#include <iostream>
using namespace std;
int main(){
    int cases;
    float curr, var;
    cin >> cases;
    for(int i=0; i<cases;i++){
        cin >> curr >> var;
        if (curr+var>=0)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
