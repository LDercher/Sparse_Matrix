#include <iostream>
#include <fstream>

#include "util.hpp"
#include "DoubleLL.hpp"
#include "node.hpp"

using namespace std;

void printMenu();
void initialize(DoubleLL* myDoubleLL, int argCount, char** args);
void cleanUp(DoubleLL* myDoubleLL);
/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
  int option;
  int elem;
  DoubleLL* myDoubleLL = new DoubleLL();

  //read from the file and initialize the doubly link DoubleLL
  initialize(myDoubleLL, argCount, args);
  printMenu();
  cin >> option;
  while(option != 6){
    switch(option){
    case 1:
      cout << "Enter element to add: ";
      int newElement, position;
      cin >> newElement;
      cout << "Enter position to add element: ";
      cin >> position;
      myDoubleLL->add(newElement, position);
      myDoubleLL->print();
      break;
    case 2:
      // 2: delete
      cout << "Enter element to be deleted: ";
      cin >> elem;
      myDoubleLL->deleteAll(elem);
      myDoubleLL->print();
      break;
    case 3:
      //3: find
      cout << "Enter element to be searched: ";
      cin >> elem;
      printf("%i\n\n", myDoubleLL->find(elem));
      break;
    case 4:
      //4: print
      myDoubleLL->print();
      break;
    case 5:
      cout << "Enter index to be deleted";
      cin >> elem;
      myDoubleLL->deleteAtInd(elem);
      myDoubleLL->print();
    default:
      cout << "Invalid argument. Please try again" << endl;
      break;
    }
    printMenu();
    cin >> option;
  }

  cleanUp(myDoubleLL);
  return 0;
}

/**
 * Prints the menu of choices to the user
 */
void printMenu(){
  cout << "Please choose one of the following commands:" << endl;
  cout << "1: add" << endl;
  cout << "2: delete" << endl;
  cout << "3: find" << endl;
  cout << "4: print" << endl;
  cout << "5: delete at index " << endl;
  cout << "6: exit" << endl;
  cout << ">> ";
}

/**
 * Initializes the data structures and program environment
 */
void initialize(DoubleLL*  myDoubleLL, int argCount, char** args){
    fstream inputData;
    if(argCount < 2){
      cout << "No input file given, using default data.txt" << endl;
      inputData.open("data.txt", ifstream::in);
    } else {
      cout << "Using data from " << args[1] << endl;
      inputData.open(args[1], ifstream::in);
    }
    while(!inputData.eof()){
      int newElement;
      inputData >> newElement;
      if (inputData.good()){
      myDoubleLL->add(newElement, myDoubleLL->getSize());
    }
    }
    inputData.close();
    myDoubleLL->print();
}

void cleanUp(DoubleLL* myDoubleLL){
  delete myDoubleLL;
}
