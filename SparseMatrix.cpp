#include "SparseMatrix.hpp"

using namespace std;

SparseMatrix::SparseMatrix(tuple<int,int> dims){

  m_dims = dims;

 for(int i = 0; i < max(get<0>(m_dims),get<1>(m_dims)) ; i++)
  {
    rowOrcolPointers[i] = nullptr;
  }

  m_orientation_row = true;

}

SparseMatrix::~SparseMatrix(){

  for(int i = 0; i < max(get<0>(m_dims),get<1>(m_dims)) ; i++)
   {
     if (rowOrcolPointers[i] != NULL)
     {
       delete rowOrcolPointers[i];
     }
   }

  delete rowOrcolPointers;

}

void SparseMatrix::add(tuple<int,int> pos, int val){

  try {

    if( get<0>(pos) > get<0>(m_dims))
    {

        throw std::out_of_range (" SparseMatrix position out of bounds");

    }
    else if(get<1>(pos) > get<1>(m_dims) )
    {
      throw std::out_of_range (" SparseMatrix position out of bounds");
    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n pos x = %i bound x = %i \n pos y = %i bound y = %i",oor.what(),get<0>(pos),get<0>(m_dims),get<1>(pos),get<1>(m_dims));

      return;

  }

  if( m_orientation_row)
  {
    if(rowOrcolPointers[get<0>(pos)] == nullptr)
    {
      rowOrcolPointers[get<0>(pos)] = new DoubleLL();

      rowOrcolPointers[get<0>(pos)]->addBack(val, get<0>(pos), get<1>(pos));
    }
    else
    {
     rowOrcolPointers[get<0>(pos)]->add(val, get<0>(pos), get<1>(pos));
    }
  }
  else{

    if(rowOrcolPointers[get<1>(pos)] == nullptr)
    {
      rowOrcolPointers[get<1>(pos)] = new DoubleLL();

      rowOrcolPointers[get<1>(pos)]->addBack(val, get<1>(pos), get<0>(pos));
    }
    else
    {
      rowOrcolPointers[get<1>(pos)]->add(val, get<1>(pos), get<0>(pos));
    }

  }

}

void SparseMatrix::print()
{
  node<int>* temp;
  if(m_orientation_row)
  {
    for( int i = 0; i < get<0>(m_dims); i++)
    {
      if (rowOrcolPointers[i] != nullptr)
      {
      temp = rowOrcolPointers[i]->getFront();
      }
      else{
        temp = nullptr;
      }
      for( int j = 0; j < get<1>(m_dims); j++)
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
  else
  {
    for( int i = 0; i < get<1>(m_dims); i++)
    {
      if (rowOrcolPointers[i] != nullptr)
      {
      temp = rowOrcolPointers[i]->getFront();
      }
      else{
        temp = nullptr;
      }
      for( int j = 0; j < get<0>(m_dims) ; j++)
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

tuple<int,int> SparseMatrix::getDims()
{
  return m_dims;
}

void SparseMatrix::setDims(tuple<int,int> dims)
{

  m_dims = dims;

}

DoubleLL** SparseMatrix::getIndArr()
{
  return rowOrcolPointers;
}

bool SparseMatrix::isEqual(SparseMatrix* SM)
{
  node<int>* temp_this;
  node<int>* temp_inp;
  bool isEq = false;

  if (get<0>(m_dims) != get<0>(SM->getDims()) ||get<1>(m_dims) != get<1>(SM->getDims()) )
  {
    return isEq;
  }
  else
  {
    for(int i = 0; i < max(get<0>(m_dims),get<1>(m_dims)); i++)
     {
       if (rowOrcolPointers[i] != nullptr)
       {
          if(SM->getIndArr()[i] != nullptr)
          {
            return isEq;
          }
       }
       else if ((SM->getIndArr()[i] != nullptr) & (rowOrcolPointers[i] != nullptr))
       {
         if(SM->getIndArr()[i]->getSize() != rowOrcolPointers[i]->getSize())
         {

          return isEq;

         }

         while(temp_this != nullptr)
         {

           temp_this = rowOrcolPointers[i]->getFront();

           temp_inp = SM->getIndArr()[i]->getFront();

           if( temp_inp == nullptr)
           {
             return isEq;
           }
           else if (temp_this->getValue() != temp_inp->getValue())
           {
             return isEq;
           }

           temp_this = temp_this->getNext();

           temp_inp = temp_inp->getNext();

        }

      }
      else
      {
          return isEq;
      }

     }

  }
isEq = true;

 return isEq;
}


void SparseMatrix::transpose()
{

  int temp_int;

  tuple<int,int> temp_dims;

  temp_int = get<0>(m_dims);

  get<0>(m_dims) = get<1>(m_dims);

  get<1>(m_dims) = temp_int;

  m_orientation_row = !m_orientation_row;

  node<int>* temp_np;

  if(!m_orientation_row)
  {
    for( int i = 0; i < get<0>(m_dims); i++)
    {
      if (rowOrcolPointers[i] != nullptr)
      {
      temp_np = rowOrcolPointers[i]->getFront();
      }
      else{
        temp_np = nullptr;
      }
      for( int j = 0; j < get<1>(m_dims); j++)
      {
        if( temp_np != nullptr)
        {
            temp_dims = temp_np->getCoord();

            temp_int = get<0>(temp_dims);

            get<0>(temp_dims) = get<1>(temp_dims);

            get<1>(temp_dims) = temp_int;

            temp_np->setCoord(get<0>(temp_dims),get<1>(temp_dims));

            temp_np = temp_np ->getNext();
        }
      }
    }
  }
  else
  {
    for( int i = 0; i < get<1>(m_dims); i++)
    {
      temp_np = rowOrcolPointers[i]->getFront();

      for( int j = 0; j < get<0>(m_dims) ; j++)
      {
        if( temp_np != nullptr)
        {
            temp_dims = temp_np->getCoord();

            temp_int = get<0>(temp_dims);

            get<0>(temp_dims) = get<1>(temp_dims);

            get<1>(temp_dims) = temp_int;

            temp_np->setCoord(get<0>(temp_dims),get<1>(temp_dims));

            temp_np = temp_np ->getNext();
        }
      }
    }

  }

}
