#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(tuple<int,int> dims){

  m_dims = dims;

  m_SM = new DoubleLL();
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

  int searchInd = 0;

  node<int>* temp1 = m_SM->getFront();

  node<int>* temp2 = temp1->getNext();

  while(temp2 != nullptr){

  if(get<0>(temp1->getCoord()) > get<0>(pos) && get<1>(temp1->getCoord()) > get<1>(pos))
  {

    m_SM->addFront(val);

  }

  if(get<0>(m_SM->getBack()->getCoord()) > get<0>(pos) && get<1>(m_SM->getBack()->getCoord()) > get<1>(pos))
  {

    m_SM->addBack(val);

  }

  if( get<0>(temp1->getCoord()) > get<0>(pos) && get<0>(temp2->getCoord()) < get<0>(pos))
  {

    if( get<1>(temp1->getCoord()) > get<1>(pos) && get<1>(temp2->getCoord()) < get<1>(pos) )
    {

      m_SM->add(val,get<0>(pos), get<1>(pos), searchInd + 1);

    }
    else
    {
      temp1 = temp1->getNext();

      temp2 = temp2->getNext();

      searchInd++;
    }

  }
  if( get<0>(temp1->getCoord()) == get<0>(pos) && get<0>(temp2->getCoord()) < get<0>(pos))
  {

    if( get<1>(temp1->getCoord()) > get<1>(pos) && get<1>(temp2->getCoord()) < get<1>(pos) )
    {

      m_SM->add(val,get<0>(pos), get<1>(pos), searchInd + 1);

    }
    else
    {
      temp1 = temp1->getNext();

      temp2 = temp2->getNext();

      searchInd++;
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
