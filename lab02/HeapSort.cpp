
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

void heap(int *array, int arraySize, int node){
  int max = node;
  int left = node*2+1;
  int right = node*2+2;
  

  if(left < arraySize && array[left] > array[max])
    max = left;
  if(right < arraySize && array[right] > array[max])
    max = right;

  if(max != node){
    swap(array[max],array[node]);
    heap(array,arraySize,max);
  } 
  return;
}

void heapSort( int *array, int arraySize) {
  for(int i = arraySize; 0 <= i; i--)
    heap(array, arraySize, i);

  for(int i = arraySize-1; i > 0; i--){
    swap(array[0],array[i]);
    heap(array,i,0);
  }
}


int main(int argc,char **argv) {
  int *Sequence;
  int arraySize;

  cin >> arraySize;
  Sequence = new int[arraySize];
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];
  heapSort(Sequence, arraySize); 
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
  delete[] Sequence;
}
