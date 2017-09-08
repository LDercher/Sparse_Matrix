/**
*	@file : SparesMatrix.hpp
*	@author :  Luke Dercher
*	@date : 2017.09.08
*	Purpose: Header file of SparseMatrix class
*/

#ifndef SparseMatrix_H
#define SparseMatrix_H
#include <tuple>
#include <stdexcept>

using namespace std;


class SparseMatrix {

  private:

    tuple<int,int> m_dims;

    int m_numElems;

    DoubleLL * m_SM;

  public:

    /**
    * @pre none
    * @post none
    * @return SM with given
    */
    SparseMatrix(tuple<int,int> dims);

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    ~SparseMatrix();

    /**
    * @pre none
    * @post adds value given as input to position given as input
    * throws exception if trying to out of bounds
    * replaces value if one already exists.
    * @return size of DLL
    */
    void add(tuple<int,int> pos, int val);

    /**
    * @pre none
    * @post removes value at position given, nothing if no elem exists
    * at
    * @return size of DLL
    */
    void remove(tuple<int,int> pos);

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    int getDim();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    int getNumElems();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    bool isEqual();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    SparseMatrix* transpose();

}




#endif SparseMatrix_H
