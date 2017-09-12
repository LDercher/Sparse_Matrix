/**
*	@file : SparesMatrix.hpp
*	@author :  Luke Dercher
*	@date : 2017.09.08
*	Purpose: Header file of SparseMatrix class
*/

#ifndef SparseMatrix_H
#define SparseMatrix_H
#include <tuple>
#include <cstdint>

#include "DoubleLL.hpp"

using namespace std;


class SparseMatrix {

  private:

  tuple<int,int> m_dims;

  bool m_orientation_row;

  DoubleLL** rowOrcolPointers = new DoubleLL* [max(get<0>(m_dims),get<1>(m_dims))];

  public:

    /**
    * @pre none
    * @post none
    * @return SM with given
    */
    SparseMatrix(tuple<int,int> dims);

    void prettyprint();

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
    * @post prints SparseMatrix
    * @return none
    */
    void print();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    tuple<int,int> getDims();

    /**
    * @pre none
    * @post set_mdims to new value
    * @return none
    */
    void setDims(tuple<int,int> dims);

    /**
    * @pre none
    * @post none
    * @return index array for sparse matrix
    */
    DoubleLL** getIndArr();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    bool isEqual(SparseMatrix* SM);

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    void transpose();

};




#endif //SparseMatrix_H
