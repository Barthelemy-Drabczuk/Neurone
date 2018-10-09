#ifndef ADDER_H
#define ADDER_H

#include "neurone.hpp"

template<typename T >
class Adder : public Neurone<T> {

public:
  Adder (const T & val1, const T & val2) : Neurone (val1, val2)
};

#endif // ADDER_H
