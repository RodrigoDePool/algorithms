#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, i, aux;
    int dif; 
    cin >> n;
    while(n!=0){
        vector<long> esquis(n);
        vector<long> personas(n);
        for(i=0; i<n;i++){
            cin >> aux;
            personas[i]=aux;
        }
        for(i=0; i<n;i++){
            cin >> aux;
            esquis[i]=aux;
        }

        sort(personas.begin(), personas.end()); 
        sort(esquis.begin(), esquis.end()); 
        dif=0;
        for(i=0; i<n;i++){
            if(personas[i]>esquis[i])
                dif+=(personas[i]-esquis[i]);
            else
                dif+=(esquis[i]-personas[i]);
        }
        cout << dif << endl;
        cin >> n;
    }
    return 0;
}
