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

int DoubleLL::size(){
  return m_size;
}

void DoubleLL::add(int elem, int position) {

  try {

    if( m_size < position)
    {

        throw std::out_of_range ("position out of bounds");

    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n",oor.what());

      return;

  }


  if (m_size == 0 && position == 0)
  {
      //if no elements in list
      m_back = new node<int>();

      m_back -> setValue(elem);

      m_front = m_back;

  }
  else
  {

      if ( position == 0)
      {

      	addFront(elem);

      }
      else if (position == m_size )
      {

	      addBack(elem);

      }
      else
      {

        node<int>* pos = m_front;

        //loop through DLL to find node at pos
        for(int i = 0; i < position; i++) //Might need to set i = 1 at beginning
        {
          pos = pos->getNext();
        }

        node<int>* new_node = new node<int>();

        new_node->setValue(elem);

        pos->getPrev()->setNext (new_node);

        new_node->setPrev(pos->getPrev());

        pos->setPrev(new_node);

        new_node->setNext(pos);

      }
  }

  m_size ++;

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

void DoubleLL::addFront(int elem)
{
   node<int>* new_node = new node<int>();

   new_node->setValue(elem);

   new_node->setNext(m_front);

   m_front->setPrev(new_node);

   m_front = new_node;

}

void DoubleLL::addBack(int elem)
{

   node<int>* new_node = new node<int>();

   new_node->setValue(elem);

   new_node->setPrev(m_back);

   m_back->setNext(new_node);

   m_back = new_node;

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

        for (int i = 0; i < m_size; i++ )
        {
          printf(" %i ", temp->getValue());
          temp = temp->getNext();
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

      posList->addBack(tempVal);

      listIter = listIter->getNext();

    }

    return posList;

}
