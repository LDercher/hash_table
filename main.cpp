#include <iostream>
#include <fstream>
#include <tuple>
#include <chrono>
#include <thread>

#include "util.hpp"
#include "DoubleLL.hpp"
#include "node.hpp"
#include "hash_table.hpp"
//#include "SparseMatrix.hpp"

using namespace std;


/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){

  hash_table* ht = new hash_table();

  ht->add("a");

  ht->add("aa");

  ht->add("aba");

  ht->print();

  return 0;
}
