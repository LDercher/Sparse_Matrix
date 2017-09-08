
SparseMatrix::SparseMatrix(tuple<int,int> dims){

  m_dims = dims;

  m_SM = new DoubleLL();
}

SparseMatrix::~SparseMatrix(){

}

void SparesMatrix::add(tuple<int,int> pos, int val){

  try {

    if( (get<0>pos > get<0>m_SM) ||(get<1>pos > get<1>m_SM) )
    {

        throw std::out_of_range ("position out of bounds");

    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n",oor.what());

      return;

  }

  node<int>* temp1 = m_SM->getFront();

  node<int>* temp2 = temp1->getNext();

  if( get<0>(temp1->getCoord()) > get<0>(pos) && get<0>(temp2->getCoord()) < get<0>(pos))
  {

    if( get<1>(temp1->getCoord()) > get<1>(pos) && get<1>(temp2->getCoord()) < get<1>(pos) )
    {

      m_Sm->add()

    }

  }
}

void SparseMatrix::remove(tuple<int,int> pos)
{
  try {

    if( (get<0>pos > get<0>m_SM) ||(get<1>pos > get<1>m_SM) )
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
