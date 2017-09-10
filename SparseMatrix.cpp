#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(tuple<int,int> dims){

  m_dims = dims;

/*  for(int i = 0; i < max(get<0>(m_dims),get<1>(m_dims)); i++)
  {
    rowOrcolPointers[i] = nullptr;
  } */

  m_orientation_row = true;

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
    if(rowOrcolPointers[get<1>(pos)]->getFront() == nullptr)
    {
      rowOrcolPointers[get<1>(pos)] = new DoubleLL();

      rowOrcolPointers[get<1>(pos)]->addBack(val, get<0>(pos), get<1>(pos));
    }
    else
    {
     rowOrcolPointers[get<1>(pos)]->add(val, get<0>(pos), get<1>(pos));
    }
  }
    if(rowOrcolPointers[get<0>(pos)]->getFront() == nullptr)
    {
      rowOrcolPointers[get<0>(pos)] = new DoubleLL();

      rowOrcolPointers[get<0>(pos)]->addBack(val, get<1>(pos), get<0>(pos));
    }
    else
    {
      rowOrcolPointers[get<0>(pos)]->add(val, get<1>(pos), get<0>(pos));
    }

}

void SparseMatrix::print()
{

  if(m_orientation_row)
  {
    for( int i = 0; i < get<0>(m_dims); i++)
    {
      node<int>* temp = rowOrcolPointers[i]->getFront();

      for( int j = 0; j < get<1>(m_dims); j++)
      {
        if( temp == nullptr)
        {
            printf("value= %i(i) at ind= (%i,%i) \n\n", 0,i,j);
        }
        else
        {
            printf("value= %i(else) at ind= (%i,%i) \n\n", temp->getValue(), get<0>(temp->getCoord()),get<1>(temp->getCoord()));

            temp = temp->getNext();
        }
      }
    }
  }
  else
  {
    for( int i = 0; i < get<1>(m_dims); i++)
    {
      node<int>* temp = rowOrcolPointers[i]->getFront();

      for( int j = 0; j < get<0>(m_dims); j++)
      {
        if( temp == nullptr)
        {
            printf("value= %i at ind= (%i,%i) \n\n", 0,i,j);
        }
        else
        {
            printf("value= %i at ind= (%i,%i) \n\n", temp->getValue(), get<0>(temp->getCoord()),get<1>(temp->getCoord()));

            temp = temp->getNext();
        }
      }
    }

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
