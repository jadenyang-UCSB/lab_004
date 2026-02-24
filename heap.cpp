// heap.cpp
// Diba Mirza
//Jaden
#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time

Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end);
  for(int i = (int)vdata.size()/2 - 1; i >= 0; i--){
    siftup(i);
  }
}

void Heap::siftup(int value){
  int parent = (value - 1)/2;

  if(vdata[parent] > vdata[value]){
    int temp = vdata[parent];
    vdata[parent] = vdata[value];
    vdata[value] = temp;
    return;
  }
  return;
}
// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  // if(vdata.size() == 0){
  //   return;
  // }
  // else{
  //   for(int i = vdata.size() - 1; i >= 0; i--){
  //     siftup(i);
  //   }
  //   return;
  // }

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(empty()){
    return;
  }
  for(int i = vdata.size() - 1; i >= 0; i--){
    siftup(i);
  }
  vdata.erase(vdata.begin());
  for(int i = vdata.size() - 1; i >= 0; i--){
    siftup(i);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if(empty()){
    return -1;
  }
  for(int i = vdata.size() - 1; i >= 0; i--){
    siftup(i);
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0){
    return true;
  }
  return false;
}


    