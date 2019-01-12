#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;
typedef pair<char,char> card;
bool match(card a, card b){
    return a.first==b.first || a.second==b.second;
}
int main(){
    char num, pinta;
    bool end=false;
    while(true){
        list <stack<card>> pilas;
        for(int i=0;i<52;i++){
            cin >> num;
            if(num=='#'){
                end=true;
                break;
            }
            cin >> pinta;
            stack<card> pila;
            pila.push(pair<char, char>(num, pinta));
            pilas.push_back(pila);
        }
        if(end) break;
        list<stack<card>>::iterator first = pilas.begin();
        list<stack<card>>::iterator curr = first;
        list<stack<card>>::iterator aux;
        while(curr!=pilas.end()){
            // Check third left neighbour
            aux = curr;
            card currcard=curr->top();
            if(aux!=first 
               && (--aux)!=first 
               && (--aux)!=first
               && match(currcard, (--aux)->top())){
                curr->pop();
                if(curr->empty())
                    pilas.erase(curr);
                curr=aux;
                curr->push(currcard);
            }else if((aux=curr)!=first
                     && match(currcard, (--aux)->top())){
                curr->pop();
                if(curr->empty())
                    pilas.erase(curr);
                curr=aux;
                curr->push(currcard);
            }else{
                curr++;
            }
        }
        cout << pilas.size() << " ";
        if(pilas.size()>1)
            cout << "piles";
        else
            cout << "pile";
        cout << " remaining:";
        for(curr=first; curr!=pilas.end();curr++){
            cout << " " << curr->size();
        }
        cout << endl;
    }
    return 0;
}
