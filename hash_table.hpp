/**
*	@file : SparesMatrix.hpp
*	@author :  Luke Dercher
*	@date : 2017.09.08
*	Purpose: Header file of hash_table class
*/

#ifndef hash_table_H
#define hash_table_H
#include <tuple>
#include <cstdint>
#include <math.h>

#include "DoubleLL.hpp"

using namespace std;


class hash_table {

  private:

  int size_ind;

  int m_prime_sizes[1000];

  DoubleLL** ind;

  int m_size;

  int curr_members;

  public:

    /**
    * @pre none
    * @post none
    * @return SM with given
    */
    hash_table();

    void init_prime_sizes();


    void prettyprint();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    ~hash_table();

    /**
    * @pre none
    * @post adds value given as input to position given as input
    * throws exception if trying to out of bounds
    * replaces value if one already exists.
    * @return size of DLL
    */
    void add(string str);

    int hash(string inp);

    bool searchValue(string str);

    void deleteValue(string str);


    void rehash();


    /**
    * @pre none
    * @post prints hash_table
    * @return none
    */
    void print();



};




#endif //hash_table_H
