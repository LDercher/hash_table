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

void hash_table::add(tuple<int,int> pos, int val){

  try {

    if( get<0>(pos) > get<0>(m_dims) -1 )
    {

        throw std::out_of_range (" hash_table position out of bounds");

    }
    else if(get<1>(pos) > get<1>(m_dims) -1 )
    {
      throw std::out_of_range (" hash_table position out of bounds");
    }

  }
  catch(std::out_of_range &oor)
  {

      printf("exception found: %s \n pos x = %i bound x = %i \n pos y = %i bound y = %i",oor.what(),get<0>(pos),get<0>(m_dims),get<1>(pos),get<1>(m_dims));

      return;

  }

    if(ind[get<0>(pos)] == nullptr)
    {
      ind[get<0>(pos)] = new DoubleLL();
  //   printf("Creating new dll for col %d\n", get<0>(pos));
      ind[get<0>(pos)]->add(val, get<0>(pos), get<1>(pos));
//    printf("Adding to new DLL. at col %i  Current size %d\n", get<0>(pos),ind[get<0>(pos)]->getSize());
    //  prettyprint();
    }
    else
    {
  //    printf("front at  %i  value = %d\n", get<0>(pos), ind[get<0>(pos)]->getFront());
  //  printf("Adding at col %i. row %i  Current size %d\n", get<0>(pos),get<1>(pos),ind[get<0>(pos)]->getSize());
     ind[get<0>(pos)]->add(val, get<0>(pos), get<1>(pos));

  //  prettyprint();
    }
}

void hash_table::prettyprint(){
  node<int>* temp;
  bool empty = true;

  if(m_orientation_row){
    for(int j = 0; j < get<0>(m_dims); j++){
      empty = true;
      if(ind[j] != nullptr )
      {
        empty = false;
        temp = ind[j]->getFront();
      }
      for(int i=0; i < get<1>(m_dims) ; i++)
      {
        if(empty)
        {
          printf("-");
        }
        else
        {
          printf("%i", temp->getValue() );
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
  else{
    for(int j = 0; j < get<1>(m_dims); j++){
      empty = true;
      if(ind[j] != nullptr)
      {
        empty = false;
        temp = ind[j]->getFront();
      }
      for(int i=0; i < get<0>(m_dims) ; i++)
      {
        if(empty)
        {
          printf("-");
        }
        else
        {
          printf("%i", temp->getValue() );
          temp = temp->getNext();
        }

      }

    }
    printf("\n");
  }

}

void hash_table::print()
{
  node<int>* temp;
  if(m_orientation_row)
  {
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
            printf("value= %i at ind= (%i,%i) \n\n", temp->getValue(), get<0>(temp->getCoord()),get<1>(temp->getCoord()));
            temp = temp->getNext();
          }

        }
      }
    }
  }
  else
  {
    for( int i = 0; i < get<1>(m_dims); i++)
    {
      if (ind[i] != nullptr)
      {
      temp = ind[i]->getFront();
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
          if(j == get<0>(temp->getCoord()))
          {
            printf("value= %i at ind= (%i,%i) \n\n", temp->getValue(), get<0>(temp->getCoord()),get<1>(temp->getCoord()));
            temp = temp->getNext();
          }
        }
      }
    }

  }
  prettyprint();
}

tuple<int,int> hash_table::getDims()
{
  return m_dims;
}

void hash_table::setDims(tuple<int,int> dims)
{

  m_dims = dims;

}

DoubleLL** hash_table::getIndArr()
{
  return ind;
}

bool hash_table::isEqual(hash_table* SM)
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
    for(int i = 0; i < m_size; i++)
     {
       if (ind[i] != nullptr)
       {
          if(SM->getIndArr()[i] != nullptr)
          {
            return isEq;
          }
       }
       else if ((SM->getIndArr()[i] != nullptr) & (ind[i] != nullptr))
       {
         if(SM->getIndArr()[i]->getSize() != ind[i]->getSize())
         {

          return isEq;

         }

         while(temp_this != nullptr)
         {

           temp_this = ind[i]->getFront();

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
