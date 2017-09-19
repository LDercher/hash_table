#include "hash_table.hpp"

using namespace std;

hash_table::hash_table(tuple<int,int> dims){

  m_dims = dims;

  ind = new DoubleLL* [m_size];

 for(int i = 0; i < m_size; i++)
  {
    ind[i] = nullptr;
  }

}

hash_table::~hash_table(){

  for(int i = 0; i < m_size; i++)
   {
     if (ind[i] != NULL)
     {
       delete ind[i];
     }
   }

}

int hash_table::hash(string inp)
{

  int totAscii = 0;

    for(char& c : inp)
    {
    totAscii += (int) c;
    }

    return totAscii % m_size;

}


void hash_table::add(string str){


    if(ind[hash(str)] == nullptr)
    {
      ind[hash(str)] = new DoubleLL();
      ind[hash(str)]->addBack(str);
    }
    else
    {
     ind[hash(str)]->addBack(str);

    }
}

void hash_table::prettyprint(){
  node<std::string>* temp;
  bool empty = true;

    for(int j = 0; j < m_size; j++){
      empty = true;
      if(ind[j] != nullptr )
      {
        empty = false;
        temp = ind[j]->getFront();
      }
      for(int i=0; i < ind[i]->getSize() ; i++)
      {
        if(empty)
        {
          printf("-");
        }
        else
        {
          printf("%s", temp->getValue() );
          if (temp->getNext() == nullptr)
          {
            empty = true;
          }
          temp = temp->getNext();

        }

      }
      printf("\n");
    }

}

void hash_table::print()
{
  node<std::string>* temp;
    for( int i = 0; i < get<0>(m_dims); i++)
    {
      if (ind[i] != nullptr)
      {
      temp = ind[i]->getFront();
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
          if(j == get<1>(temp->getCoord()))
          {
            printf("value= %s at ind= (%i,%i) \n\n", temp->getValue(), get<0>(temp->getCoord()),get<1>(temp->getCoord()));
            temp = temp->getNext();
          }

        }
      }
    }

}
