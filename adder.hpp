#ifndef ADDER_H
#define ADDER_H

#include "neurone.hpp"

template<typename T >
class Adder : public Neurone<T> {

private:
  Adder (const T & val1, const T & val2);

public:
    void useNeur (const T & val1, const T & val2);
    const std::string getType () const;
    ~Adder ();
};

template<typename T>
Adder<T>::Adder (const T & val1, const T & val2) {
    Neurone<T> myNeur (val1, val2);
    this->everyNeurs.push_back (myNeur);
    return myNeur.getFirstVal() + myNeur.getSecondVal();
}

template<typename T>
const std::string Adder<T>::getType() const {
    return "Adder" ;
}


template<typename T>
void useNeur (const T & val1, const T & val2){
    Adder<T> (val1, val2);
}

#endif // ADDER_H

