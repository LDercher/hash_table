/**
*	@file : DoubleLL.hpp
*	@author :  Luke Dercher
*	@date : 2017.09.08
*	Purpose: Header file of doulbe linked list data structure class
*/

#ifndef DoubleLL_H
#define DoubleLL_H
#include "node.cpp"
#include "util.hpp"
#include <stdexcept>
#include <tuple>

using namespace std;

class DoubleLL {

private:

   node<std::string>* m_front;

   node<std::string>* m_back;

   int m_size;

  //Member functions
 public:

  /**
   * @pre none
   * @post none
   * @return a doubly linked list w/ no contents
   */
  DoubleLL();

  /**
  * @pre none
  * @post deletes doubly linked list
  * @return none
   */
  ~DoubleLL();

  /**
  * @pre none
  * @post none
  * @return a bool to indicate if DLL is empty
   */
  bool isEmpty();

  /**
  * @pre none
  * @post none
  * @return popinter to front node of DLL
  */
  node<std::string>* getFront();

  /**
  * @pre none
  * @post none
  * @return a pointer to the back nod of DLL
  */
  node<std::string>* getBack();

  /**
  * @pre none
  * @post none
  * @return size of DLL
  */
  int getSize();

  /**
   * @pre none
   * @post add and element on a specific position
   * Should throw an exception if the value of position
   * is not in range of [0, this.size()]
   # @return none
   */
  void add(string str, int ind) ;

  /**
  * @pre none
  * @post deletes all instances of input element does nothing if element isn't in list
  * @return none
  */
  void deleteAll(string str);

  /**
  * @pre none
  * @post deletes element at index given, throw exception if bad input given
  * @return none
  */
  void deleteAtInd(int ind);


  /**
  * @pre none
  * @post none
  * @returns the emelent in the list or -1 if element isn't in the list.
  */
  int find(string str);


  /**
  * @pre none
  * @post add element to front of the list with value of the input
  * @return none
  */
  void addFront(string str);

  /**
  * @pre none
  * @post none
  * @return an element to the back of the list with a vlue of the given input
  */
  void addBack (string str);

  /**
  * @pre none
  * @post print contents of the list
  * @return none
  */
  void print();

};

#endif //DOUBLY_LINKED_DoubleLL_H defined
