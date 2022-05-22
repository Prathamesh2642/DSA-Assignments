#include<iostream>
#include<math.h>

using namespace std;

class Heap {
  public:
    int * harr; 
  int capacity; 
  int heap_size;

  Heap(int cap) {
    heap_size = cap;
    capacity = cap;
    harr = new int[cap];
  }
  void UnsortedArray() {
    cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
    for (int i = 0; i < capacity; i++)
      cin >> harr[i];
  }
  int left(int i) {
    return (2 * i + 1);
  }

  int right(int i) {
    return (2 * i + 2);
  }
  void MinHeapify(int i) {
    int leftchild = left(i);
    int rightchild = right(i);
    int largest = i;
    if (leftchild < heap_size && harr[leftchild] > harr[largest])
      largest = leftchild;
    if (rightchild < heap_size && harr[rightchild] > harr[largest])
      largest = rightchild;
    if (largest != i) {
      swap(harr[i], harr[largest]);
      MinHeapify(largest);
    }
  }
  // Method to remove minimum element (or root) from min heap
  int extractMin() {
    if (heap_size <= 0)
      return 0;
    if (heap_size == 1) {
      heap_size--;
      return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
  }

  void heapSort() {
    int temp[capacity];
    for (int j = 0; j < capacity; j++) {
      temp[j] = extractMin();
      cout << temp[j] << " ";
    }
  }

};

int main() {
  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s;
  Heap h(s);
  h.UnsortedArray();
  for (int i = s / 2 - 1; i >= 0; i--) {
    h.MinHeapify(i);
  }
  cout << "Max heap :" << endl;
  h.heapSort();

}
