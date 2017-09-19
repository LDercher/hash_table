#include "hash_table.hpp"

using namespace std;

hash_table::hash_table(){

  init_prime_sizes();

  size_ind = 0;

  m_size = m_prime_sizes[size_ind];

  curr_members =0;

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

bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);

        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

void hash_table::init_prime_sizes()
{
  int prime_add =0;
  int prime = 0;

  while(prime_add < 1000)
  {
    if(isPrime(prime))
    {
      m_prime_sizes[prime_add] = prime;
      prime_add++;
    }
    else
    {
      prime++;
    }

  }

}

void hash_table::rehash()
{

  size_ind++;

  int t;

  DoubleLL** temp = new DoubleLL*[m_prime_sizes[size_ind]];

  node<string>* tempNode;

  for(int j = 0; j < m_size; j++){
    if(ind[j] != nullptr )
    {

      temp[j] = new DoubleLL();

      tempNode = ind[j]->getFront();

      t = ind[j]->getSize();

      for(int i=0; i <  t; i++)
      {

        temp[j]->addBack(tempNode->getValue());

        tempNode = tempNode->getNext();

      }
    }

  }

  delete ind;

  ind = temp;

  m_size = m_prime_sizes[size_ind];


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

bool hash_table::searchValue(string str)
{

  if (ind[hash(str)]->find(str) == -1)
  {
    return false;
  }
  else{
    return true;
  }


}

void hash_table::deleteValue(string str)
{
  if(find(str))
  {

    ind[hash(str)]->deleteAll(str);

  }


}


void hash_table::add(string str){


    if(((float)curr_members/m_size) > 0.5)
    {

      rehash();

    }
        if(ind[hash(str)] == nullptr)
        {
          ind[hash(str)] = new DoubleLL();
          ind[hash(str)]->addBack(str);
        }
        else
        {
         ind[hash(str)]->addBack(str);

        }
        curr_members++;

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
    for( int i = 0; i < m_size; i++)
    {
        cout << i << " -> ";

        if(ind[i] != nullptr)
        {

          temp = ind[i]->getFront();

          for (int j=0; j < ind[i]->getSize(); j++)
          {

            cout << "'" << temp->getValue() << "' ";

            temp = temp->getNext();

          }
          printf("\n");

        }
      }


}
