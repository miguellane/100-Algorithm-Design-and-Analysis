
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
void print2D(int** array, int arraySize, int digits){
  for(int i=0; i<arraySize; i++){
    for(int j=0; j < digits; j++){
      cout << array[i][j]<<";";
    }
    cout<<endl;
  }
}

void countSort(int** array, int arraySize, int digits, int j){
  int **output;  
  output = new int *[arraySize];
  for(int i = 0; i <arraySize; i++)
    output[i] = new int[digits]; 

  int count[10];
  for(int c = 0; c < 10; c++)
    count[c] = 0;

  for(int i = 0; i < arraySize; i++)
    count[array[i][j]]++;
  for(int c = 1; c < 10; c++)
    count[c] += count[c-1];

  for (int i = arraySize-1; i >= 0; i--){
    swap(output[--count[array[i][j]]], array[i]);
//    --count[array[i][j]];
  }
  for (int i = 0; i<arraySize; i++)
    swap(array[i] , output[i]);
  delete[] output;
}

void radixSort(int** array, int arraySize, int digits) {
  for(int j=digits-1; j >= 0; j--){
    countSort(array,arraySize,digits,j);
  }
  return;
}

int main(int argc,char **argv) {
//Sequence[Vector#][Digit]
  int digits = 10;
  int arraySize;
  cin >> arraySize;
  int **Sequence;  
  Sequence = new int *[arraySize];
  for(int i = 0; i <arraySize; i++)
    Sequence[i] = new int[digits]; 

  for ( int i=0; i<arraySize*digits; i++ )
    cin >> Sequence[i/digits][i%digits];

  radixSort(Sequence, arraySize, digits); 

  print2D(Sequence,arraySize,digits);

  delete[] Sequence;
}
