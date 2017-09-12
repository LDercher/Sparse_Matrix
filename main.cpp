#include <iostream>
#include <fstream>
#include <tuple>
#include <chrono>
#include <thread>

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
  bool adding = true;
  char yes_or_no;
  tuple<int,int> dims;
  SparseMatrix* sm1;
  SparseMatrix* sm2;

printf( "\n\n\nWelcome to the Matrix! \n\n\n\n");
printf("In this excerise the user will create two  sparse matrices (meaning they have very few elements). \n\n");
printf("The user will specify the dimensions and add values to the matrix \n\n");
printf("the user will be able to print the matrices, test them for equality,\n\n");
printf("As well as transpose the matrices and see them printed afterwards.\n\n");
int col, ro, val;
      cout << "Enter element the dimensions of the first SparseMatrix: \n";
      cout << "Enter the number of columns:\n";
      cin >> ro;
      cout << "Enter the number of rows:\n";
      cin >> col;
      dims = make_tuple(col, ro);
      sm1 = new SparseMatrix(dims);
      while(adding)
      {
        cout << "Enter element of the first SparseMatrix and placement of it (not too many): \n";
        cout << "Enter value\n";
        cin >> val;
        cout << "Enter column number to place it in (be careful to not go out of bounds!)\n";
        cin >> ro;
        cout << "Enter row number to place it in (be careful to not go out of bounds!)\n";
        cin >> col;
        cout << "Adding value to first SparesMatrix\n";
        dims = make_tuple(col, ro);
        sm1->add(dims,val);
        cout << "done adding? (y for yes, n for no) \n\n";
        cin >> yes_or_no;
        if(yes_or_no == 'y')
        {
          adding = false;
        }

      }
      adding = true;
      sm1->print();
      cout << "\n\nEnter element the dimensions of the second SparseMatrix: \n";
      cout << "Enter the number of columns:\n";
      cin >> ro;
      cout << "Enter the number of rows:\n";
      cin >> col;
      dims = make_tuple(col, ro);
      sm2 = new SparseMatrix(dims);
      while(adding)
      {
        cout << "Enter element of the second SparseMatrix and placement of it (not too many): \n";
        cout << "Enter value\n";
        cin >> val;
        cout << "Enter column number to place it in (be careful to not go out of bounds!)\n";
        cin >> ro;
        cout << "Enter row number to place it in (be careful to not go out of bounds!)\n";
        cin >> col;
        cout << "Adding value to second SparesMatrix\n";
        dims = make_tuple(col, ro);
        sm2->add(dims,val);
        cout << "done adding? (y for yes, n for no) \n\n";
        cin >> yes_or_no;
        if(yes_or_no == 'y')
        {
          adding = false;
        }

      }
      sm2->print();
      cout << "\n\n\n Now let's see if the matrices you created are equal.\n\n\n";
      cout << "checking equality.....\n\n\n";
      if(sm1->isEqual(sm2))
      {
        cout << "Your matrices are equal \n\n\n Good Job!!\n\n\n";
      }
      else
      {
        cout << "Your matrices are not equal \n\n\n:-(";
      }
      cout << "Now let's transpose them! \n\n\n";
      sm1->transpose();
      sm2->transpose();
      printf("SparseMatrix 1 transposed is:\n");
      sm1->print();
      printf("\n\nSparseMatrix two transposed is:\n");
      sm2->print();


delete sm1;
delete sm2;

  return 0;
}
