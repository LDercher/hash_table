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

#include "DoubleLL.hpp"

using namespace std;


class hash_table {

  private:

  tuple<int,int> m_dims;


  DoubleLL** ind;

  int m_size;

  public:

    /**
    * @pre none
    * @post none
    * @return SM with given
    */
    hash_table(tuple<int,int> dims);

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
    void add(tuple<int,int> pos, int val);

    int hash(string inp);

    /**
    * @pre none
    * @post prints hash_table
    * @return none
    */
    void print();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    tuple<int,int> getDims();

    /**
    * @pre none
    * @post set_mdims to new value
    * @return none
    */
    void setDims(tuple<int,int> dims);

    /**
    * @pre none
    * @post none
    * @return index array for sparse matrix
    */
    DoubleLL** getIndArr();

    /**
    * @pre none
    * @post none
    * @return size of DLL
    */
    bool isEqual(hash_table* SM);


};




#endif //hash_table_H
