
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

void quickSort( int *start, int *stop, int run) {
//[i][][][][j][p]
//[i][]  [][j][p]
  if(run == 0){ 
    srand(time(NULL));
    swap(start[rand()%(stop-start+1)],*stop);
  }
  int pivot = *stop;
  int i = 0;
  int j = stop-start-1;
  while(i <= j){
    if(start[i] >= pivot){
      if(start[j] <= pivot){
        swap(start[i],start[j]);
        i++;j--;
      }else{
        j--;
      }
    }else{
      i++;
    }
  }

  swap(start[i],*stop);

  if(start < start+i-1)
    quickSort(start, start+i-1,1);
  if(start+i+1 < stop)
    quickSort(start+i+1,stop,1);
  return;
}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  quickSort(Sequence, Sequence+arraySize-1,0); 
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
