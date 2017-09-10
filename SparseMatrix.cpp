#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(tuple<int,int> dims){

  m_dims = dims;

  for(int i = 0; i < max(get<0>(m_dims),get<1>(m_dims)); i++)
  {

    rowOrcolPointers[i] = new DoubleLL();

  }

}

SparseMatrix::~SparseMatrix(){

}

void SparseMatrix::add(tuple<int,int> pos, int val){

  try {

    if( (get<0>(pos) > get<0>(m_dims)) ||(get<1>(pos) > get<1>(m_dims)) )
    {

        throw std::out_of_range ("position out of bounds");

    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n",oor.what());

      return;

  }

  if( m_orientation_row)
  {
     rowOrcolPointers[get<1>(pos)]->add(val, get<0>(pos), get<1>(pos));
  }
  else
  {
    rowOrcolPointers[get<0>(pos)]->add(val, get<1>(pos), get<0>(pos));

  }

}


void SparseMatrix::remove(tuple<int,int> pos)
{
  try {

    if( (get<0>(pos) > get<0>(m_dims)) ||(get<1>(pos) > get<1>(m_dims)) )
    {

        throw std::out_of_range ("position out of bounds");

    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n",oor.what());

      return;

  }



}
