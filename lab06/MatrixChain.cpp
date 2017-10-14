// This program output the minimum number of operations required to perform the matrix chain multiplication.
#include <iostream>
#include <stdio.h>
#include <vector> // you may use the vector class to represent a matrix, for ex: vector<vector<int>> M;
#include <algorithm>
#include <sys/time.h>
#include <climits>

using namespace std;

void PrintOptimalParens(vector<vector<int> > s, int i, int j){
  if(i == j){
    cout << "A" << i-1;
  } else{
    cout << "(";
    PrintOptimalParens(s, i, s[i][j]);
    PrintOptimalParens(s, s[i][j] + 1, j);
    cout << ")";
  }
}

void DynamicPunch(vector<int> matrix){
  int n = matrix.size();
  vector<vector<int> > m ( n, vector<int>(n,0));
  vector<vector<int> > s ( n, vector<int>(n,0));
  int sum, j;
// matrix 6 elements, 5 matracies
//                j
// [---][---][---][---][---][---]
// [---][  0][A01][   ][   ][   ]
// [---][---][  0][A12][   ][   ]
// [---][---][---][  0][A23][   ]  i
// [---][---][---][---][  0][A34]
// [---][---][---][---][---][  0]
  for (int l = 2; l < n; l++){
      for (int i = 1; i < n-l+1; i++){
          j = i + l -1;
          m[i][j] = INT_MAX;
          for (int k = i; k < j; k++){
              sum = m[i][k] + m[k+1][j] + matrix[i-1]*matrix[k]*matrix[j];
              if (sum < m[i][j]){
                  m[i][j] = sum;
                  s[i][j] = k;              
  } }  }  }
  cout <<m[1][n-1] <<endl;
  PrintOptimalParens(s, 1, n-1);
  cout << endl;
  return;
}

int main(int argc,char **argv){  
  int size;
  cin >> size;
  vector<int> matrix;

  int temp;
  for(int i = 0; i < size+1; i++){
    cin >> temp;    
    matrix.push_back(temp);
  } 
  DynamicPunch(matrix);

}
