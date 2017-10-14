
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int* mergeSort(int* array, int size){
//  if(size == 1)
//    return array;
  if(size<10)
     insertSort(array, size);


  int hSize = size/2;
  int diff = size - hSize;
  int* a = mergeSort(array, hSize);
  int* b = mergeSort(array+hSize, diff);
  int* arr = new int[size];
  int i = 0;
  int j = 0;
  int k = 0;

//Thread Back Together In Order on New Array
  while(i < hSize && j < diff){
    if(a[i] < b[j]){
      arr[k++] = a[i++];
    }else if(a[i] >= b[j]){
      arr[k++] = b[j++];
    }
  }
  while(i < hSize && j == diff){
    arr[k++] = a[i++];
  }
  while(i == hSize && j < diff){
    arr[k++] = b[j++];
  }
//Save New Array Back Onto Original
  for(int k = 0; k < size; k++)
    array[k] = arr[k];
  return arr;
}


void insertSort(int* array, int size){
  for(int i = 1; i < size; i++){
    int j = i - 1;
    int key = array[i];
    while(array[j] > key && j >= 0){
      int temp = array[j+1];
      array[j+1] = array[j];
      array[j] = temp;
      j--;

    }
  }
}


int main(int argc,char **argv) {

  int *array;
  int arraySize;
  cin >> arraySize;
  array = new int[arraySize];
  for ( int i=0; i<arraySize; i++ )
    cin >> array[i];
    mergeSort(array, arraySize);
  for(int i=0; i<arraySize; i++)
      cout << array[i] << endl;
    
  delete[] array;
}
