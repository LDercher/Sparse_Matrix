#include "DoubleLL.hpp"

DoubleLL::DoubleLL() {

    m_size = 0;

    m_front = nullptr;

    m_back = nullptr;

}

DoubleLL::~DoubleLL() {

node<int>* curr = m_front;
node<int>* next = nullptr;

  while (curr != nullptr)
  {
    next = curr->getNext();

    delete curr;

    curr = next;
  }

}

node<int>* DoubleLL::getFront()
{
  return m_front;
}

node<int>* DoubleLL::getBack()
{
  return m_back;
}

bool DoubleLL::isEmpty() {

    if (m_size > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

  return true;
}

int DoubleLL::getSize(){
  return m_size;
}

void DoubleLL::incSize(){
  m_size++;
}

void DoubleLL::add(int elem, int Xcoord, int Ycoord) {

      if ( Ycoord == 0)
      {

      	addFront(elem, Xcoord, Ycoord);

        printf("adding front!! size = %i ycoord = %i\n", m_size,Ycoord);

      }
      else if (Ycoord >= m_size )
      {

	      addBack(elem, Xcoord, Ycoord);

        printf("adding Back!! size = %i ycoord = %i\n", m_size,Ycoord);
        if(m_back->getNext())
        {
        printf("\n\n\nm_front get next pointing at null in list > 0 (after addback call)\n\n\n");
        }

      }
      else
      {
        printf("Adding at %i size = %i \n\n",Ycoord,m_size);

        node<int>* pos = m_back;

        if(pos->getPrev() == nullptr)
        {
          printf("\n\n\nM_BACK GET PREV IS NULLPTR ON LL WITH SIZE > 0\n\n\n");
        }

        //loop through DLL to find node at pos
        for(int i = 0; i < (m_size - 1) - Ycoord; i++)
        {
          pos = pos->getPrev();
        }

        node<int>* new_node = new node<int>();

        incSize();

        new_node->setValue(elem);

        new_node -> setCoord(Xcoord, Ycoord);

        if( pos->getPrev() != nullptr)
        {

        pos->getPrev()->setNext (new_node);

        new_node->setPrev(pos->getPrev());

        pos->setPrev(new_node);

        new_node->setNext(pos);

       }

      }


 print();

}

void DoubleLL::deleteAll(int elem) {

  node<int>* temp = m_front;

  while(find(elem) != -1)
  {
    while(temp->getValue()!= elem)
    {

      temp = temp->getNext();

    }

    if(temp == m_front)
    {

      m_front = m_front->getNext();

      m_front->setPrev(nullptr);

      delete temp;

      temp = m_front;

    }
    else if(temp == m_back)
    {
      m_back = m_back->getPrev();

      m_back->setNext(nullptr);

      delete temp;

      temp = m_back;

    }
    else
    {
      node<int>* temp_prev = temp-> getPrev();

      node<int>* temp_next = temp->getNext();

      temp_prev->setNext(temp_next);

      temp_next->setPrev(temp_prev);

      delete temp;

      temp = temp_prev;

    }

    m_size--;

  }

}

void DoubleLL::deleteAtInd(int ind)
{
  try {

    if( ind > m_size || ind < 0 )
    {

        throw std::out_of_range ("index out of bounds");

    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n",oor.what());

      return;

  }

  node<int>* temp = m_front;

  int searchInd = 0;

  if ( ind == 0)
  {

    m_front = m_front->getNext();

    delete temp;

  }
  else if( ind == (m_size - 1))
  {

    temp = m_back;

    m_back = m_back->getPrev();

    delete temp;

  }
  else
  {

      while ( ind != searchInd )
      {
        searchInd++;

        temp = temp->getNext();

      }
      temp->getPrev()->setNext(temp->getNext());

      temp->getNext()->setPrev(temp->getPrev());

      delete temp;

  }

  m_size--;


}

void DoubleLL::addFront(int elem, int x, int y)
{
   node<int>* new_node = new node<int>();

   new_node->setValue(elem);

   new_node->setCoord(x,y);

   if(m_size == 0)
   {

     m_front = new_node;

     m_back = new_node;

   }
   else
   {

   new_node->setNext(m_front);

   m_front->setPrev(new_node);

   m_front = new_node;

   }

   incSize();

}

void DoubleLL::addBack(int elem, int x, int y)
{

   node<int>* new_node = new node<int>();

   new_node->setValue(elem);

   new_node->setCoord(x,y);

   if(m_size == 0)
   {

     m_front = new_node;

     m_back = new_node;

   }
   else
   {

     new_node->setPrev(m_back);

     m_back->setNext(new_node);

     m_back = new_node;

     if(m_size == 2 )
     {
       m_front->setNext(new_node);
     }
   }

   incSize();

}


int DoubleLL::find(int elem) {
  node<int>* temp = m_front;

  int i = 0;

     while (temp!= nullptr)
     {
          if (temp->getValue() == elem)
          {

              return temp->getValue();

          }

	  i++;

          temp = temp->getNext();
     }

     return -1;

}

int DoubleLL::findInd(int elem) {
  node<int>* temp = m_front;

  int i = 0;

     while (temp!= nullptr)
     {
          if (temp->getValue() == elem)
          {

              return i;

          }

	  i++;

          temp = temp->getNext();
     }

     return -1;

}

void DoubleLL::print() {

  if(m_size > 0){

        node<int>* temp = m_front;

	printf("List: ");

        for (int i = 0; i < m_size - 1; i++ )
        {
          printf(" %i ", temp->getValue());
          if(temp->getNext() != nullptr)
          {
          temp = temp->getNext();
          }
        }
	printf("\n\n");
      }
      else{

          printf("empty DoubleLL\n");

      }

     }


DoubleLL* DoubleLL::getPositionList( DoubleLL* list ){

    int tempVal;

    DoubleLL* posList = new DoubleLL();

    node<int>* listIter = list->getFront();

    while(listIter != nullptr)
    {

      tempVal = find(listIter->getValue());

      posList->addBack(tempVal, 0, 0);

      listIter = listIter->getNext();

    }

    return posList;

}
