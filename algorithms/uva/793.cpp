#include <stack>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <regex>
#include <sstream>
using namespace std;
class component{
    public:
        int id=-1;
        component *parent=NULL; 
};
bool connected(unordered_map<int, component> grafo, int c1, int c2){
    if(c1==c2) return true;
    else if(grafo[c1].parent==NULL || grafo[c2].parent==NULL) return false;

    component auxp;
    int id1;
    auxp = grafo[c1];
    while(auxp.parent!=NULL)
        auxp = *auxp.parent;
    id1=auxp.id;
    auxp = grafo[c2];
    while(auxp.parent!=NULL)
        auxp = *auxp.parent;
    return auxp.id == id1;
}
int lastid=0;
int main(){
    int cases, n;
    string line;
    char q;
    int c1, c2;
    regex blank("[ ]*");
    cin >> cases;
    cin.ignore();
    getline(cin, line);
    vector<component*> clean;
    for(int w=0; w<cases;w++){
        if(w!=0) cout << endl;
        unordered_map<int, component> grafo;
        int succ=0, unsucc=0;
        cin>>n;
        cin.ignore();
        while(true){
            getline(cin, line);
            if(regex_match(line, blank)) break;
            stringstream ss(line);
            ss >> q >> c1 >> c2;
            if(q=='c'){
                component *auxp, *parent;
                parent = new component();
                clean.push_back(parent);
                lastid++;
                parent->id=lastid;
                auxp = &(grafo[c1]);
                while(auxp->parent!=NULL){
                    auxp = auxp->parent;
                }
                auxp->parent = parent; 
                auxp = &(grafo[c2]);
                while(auxp->parent!=NULL){
                    auxp = auxp->parent;
                }
                // If they are not already connected
                if(auxp->id != parent->id)
                    auxp->parent = parent; 
            }else if(connected(grafo, c1, c2)){
                succ++;
            }else{
                unsucc++;
            }
        }
        cout << succ << "," << unsucc << endl;
    }
    for(component*p:clean)
        delete p;
    return 0;
}
