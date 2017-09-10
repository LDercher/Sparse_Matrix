#include <iostream>
#include <fstream>
#include <tuple>

#include "util.hpp"
#include "DoubleLL.hpp"
#include "node.hpp"
#include "SparseMatrix.hpp"

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
  tuple<int,int> dims = make_tuple(5,5);
  SparseMatrix* mySM = new SparseMatrix(dims);


  //read from the file and initialize the doubly link DoubleLL
//initialize(mySM, argCount, args);
  printMenu();
  cin >> option;
  while(option != 6){
    switch(option){
    case 1:
      cout << "Enter element to add to SparseMatrix: ";
      int newElement, col, row;
      cin >> newElement;
      cout << "Enter column to add at ";
      cin >> col;
      cout << "Enter row to add at ";
      cin >> row;
      mySM->add(make_tuple(col,row), newElement);
      mySM->print();
      break;
    case 2:
      // 2: delete
      cout << "Enter element to be deleted: ";
      cin >> elem;
    //  mySM->deleteAll(elem);
    //  mySM->print();
      break;
    case 3:
      //3: find
      cout << "Enter element to be searched: ";
      cin >> elem;
      printf("%i\n\n", myDoubleLL->find(elem));
      break;
    case 4:
      //4: print
      mySM->print();
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
delete mySM;
delete myDoubleLL;
//  cleanUp(myDoubleLL);
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

void initialize(DoubleLL*  myDoubleLL, int argCount, char** args){
    fstream inputData;
    int inc = 0;
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
        inc++;
      mySM->add(newElement,inc,0, myDoubleLL->getSize());
    }
    }
    inputData.close();
    mySM->print();
}

void cleanUp(DoubleLL* myDoubleLL){
  delete mySM;
} **/
