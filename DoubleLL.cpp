#include "DoubleLL.hpp"

DoubleLL::DoubleLL() {

    m_size = 0;

    m_front = nullptr;

    m_back = nullptr;

}

DoubleLL::~DoubleLL() {
  node<std::string>* next;
	node<std::string>* curr = m_front;

  	while (curr != nullptr)
  	{

    	 next = curr->getNext();

    	 delete curr;

   	   curr = next;

   }
}

node<std::string>* DoubleLL::getFront()
{
  return m_front;
}

node<std::string>* DoubleLL::getBack()
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


void DoubleLL::add(string str, int ind) {

      if ( ind == 0)
      {

      	addFront(str);

      }
      else if (ind >= m_size )
      {

	      addBack(str);

      }
      else
      {

        node<std::string>* pos = m_back;

        //loop through DLL to find node at pos
        for(int i = 0; i < (m_size - 1) ; i++)
        {
          pos = pos->getPrev();
        }

        node<std::string>* new_node = new node<std::string>();

         m_size++;

        new_node->setValue(str);


        if( pos->getPrev() != nullptr)
        {

        pos->getPrev()->setNext (new_node);

        new_node->setPrev(pos->getPrev());

        pos->setPrev(new_node);

        new_node->setNext(pos);

       }

      }


 //print();

}

void DoubleLL::deleteAll(string str) {

  node<std::string>* temp = m_front;


    if (m_size == 0)
    {
      return;
    }


  while(find(str) != -1)
  {
    while(temp->getValue()!= str)
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
      node<std::string>* temp_prev = temp-> getPrev();

      node<std::string>* temp_next = temp->getNext();

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

    if (m_size == 0)
    {
      return;
    }


    node<std::string>* temp = m_front;

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

  	m_size--;

    }




}

void DoubleLL::addFront(string str)
{
   node<std::string>* new_node = new node<std::string>();

   new_node->setValue(str);

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

   m_size++;

}

void DoubleLL::addBack(string str)
{

   node<string>* new_node = new node<std::string>();

   new_node->setValue(str);

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

   }

    m_size++;

}


int DoubleLL::find(string str) {
  node<std::string>* temp = m_front;

  int i = 0;

     while (temp!= nullptr)
     {
          if (temp->getValue() == str)
          {

              return 1;

          }

	  i++;

          temp = temp->getNext();
     }

     return -1;

}


void DoubleLL::print() {

  if(m_size > 0){

        node<std::string>* temp = m_front;

	printf("List: ");

        for (int i = 0; i < m_size - 1; i++ )
        {
          printf(" %s ", temp->getValue());
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
