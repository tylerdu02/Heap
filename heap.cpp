/*
  * Tyler Du 
  * 2/5/23
  * Heap. Numbers are put into a max heap and able to remove and enter them.
  */

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void sort(int* heap, int count);
void print(int* heap, int location, int space);

int main() {
  int count = 0;
  int* heap = new int[100];
  for(int i = 0; i<100; i++){
    heap[i] = 0;
  }

  char input[10];
  bool running = true;

  while (running == true) {
    cout << "Add, File, Print, Delete, Quit" << endl;
    cout << "Typing file will use the numbers from the file" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (input[1] == 'D' || input[1] == 'd') { 
      int numnums;
      bool done = false;
      if (count >= 100) { // checks if heap is full
        cout << "Heap is Full!" << endl;
      }
      else { // adding numbers to heap
        cout << "Input numbers 1-1000, type '0' when done" << endl;
        while (done == false) {
          cin >> numnums;
          cin.ignore(1, '\n');
          if (numnums >= 1 && numnums <= 1000) {
            heap[count] = numnums;
            count++;
          }
          else if (numnums == 0) {
            done = true;
            sort(heap, count);
          }
          else {
            cout << "Invalid input" << endl;
          }
        }
      }
    }
    else if (input[0] == 'F' || input[0] == 'f') { // generates numbers from txt file
      ifstream numbers;
      numbers.open("heap.txt");
      int total = 0;

      if (count > 100) { 
        break;
        cout << "Heap is full!" << endl;
      }
      for (int i = count; i < 20; i++) { 
        if (count > 100) {
          break;
          cout << "Heap is full!" << endl;
        }
        else {
          numbers >> heap[i];
          count++;
        }
      }
      numbers.close();
      sort(heap, count);
    }
    else if (input[1] == 'R' || input[1] == 'r') { // prints
      if (count == 0) { 
        cout << "Heap is empty!" << endl;
      }
      else { 
        cout << "Heap: " << endl;
        print(heap, 0, 0);
      }
    }
    else if (input[0] == 'D' || input[0] == 'd') { // delete
      char tempInput[10];
      cout << "Do you want to delete the root or all. Type 'root or 'all'" << endl;
      cin.get(tempInput, 10);
      cin.ignore(1, '\n');

      if (tempInput[0] == 'R' || tempInput[0] == 'r') { // deletes root
        if (count == 0) { 
          cout << "Heap is empty!" << endl;
        }
        else {
          cout << "Deleted: " << heap[0] << endl;
          for (int i = 0; i < count; i++) {
            heap[i] = heap[i + 1];
          }
          count--;
          sort(heap, count);
        }
      }
      else if (tempInput[0] == 'A' || tempInput[0] == 'a') { // deletes whole list
        for (int i = 0; i < 100; i++) { 
          heap[i] = 0;
        }
        count = 0;
      }
      else {
        cout << "Invalid input" << endl;
      }
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // quit
      running = false;
    }
    else {
      cout << "Invalid input" << endl;
    }
  }  
  return 0;
}