
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

  if( m_SM<0>  )
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
