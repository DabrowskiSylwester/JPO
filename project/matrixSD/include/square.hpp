/***********************************************
 *              DESCRIPTION                    *
 * File contains a definition of a class 
 * SquareMatrix in the namespace sd, which is inherent
 * class of . The class implements the 
 * most general case of matrix - two dimensional
 * rectangle matrix - and apropriate methods.
 * It is a template class and because of it, it
 * has to contain all definitions in .hpp file
 * (prof. Cyganek 3.15.5).
 ***********************************************/

#pragma once

#include "matrix.hpp"

namespace sd{

  template <typename T>
  requires std::is_arithmetic_v<T>
  class SquareMatrix : public Matrix<T> {

  };

} //namespace