#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;



vector<vector<vector<int>>> sums;



void prepare(vector<vector<int>> matrix, int size){
    int left_col, right_col, i, prev;    
    sums.clear();
    for(i=0;i<size;i++){
	vector<vector<int>>aux123;
	sums.push_back(aux123);
	for(left_col=0; left_col<size; left_col++){
	    sums[i].push_back(vector<int>(size));
	    prev=0;
	    for(right_col=left_col; right_col<size; right_col++){
		if(left_col==0){
		    sums[i][left_col][right_col]= prev + matrix[i][right_col];
		    prev = sums[i][left_col][right_col];
		}else{
		    sums[i][left_col][right_col]=sums[i][left_col-1][right_col]-matrix[i][left_col-1];
		}
	    }
	}
    }
}

int max_kadane_special(vector<vector<int>>matrix,
		       int from_col,
		       int to_col,
		       int size){
    int sum,i;
    int max_current = sums[0][from_col][to_col];
    int max_total=max_current;
    for(i=1;i<size;i++){
	sum = sums[i][from_col][to_col];
	max_current = max(max_current+sum, sum);
	max_total = max(max_total, max_current);
    }
    return max_total;
}

int main(){
    int n, aux,i,j;
    while(cin >> n){
        vector<vector <int>> matrix(n);
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		cin >> aux;
	    	matrix[i].push_back(aux);
	    }
	}
	prepare(matrix, n);
	int  maxv=INT_MIN;
	for(i=0;i<n;i++){
	    for(j=0; j<=i; j++){
		aux = max_kadane_special(matrix, j, i, n);
		if(aux>maxv) maxv=aux;	
	    }
	}
	cout << maxv << endl;
    }
    return 0;
}
