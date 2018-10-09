#ifndef NEURONE_H
#define NEURONE_H

#include <map>
#include <string>

template <typename T>
class Neurone {

protected:
  //all of the neurones are stocked here for communication purposes
  static std::map<unsigned, Neurone> everyNeurs;

private:
    //every neurone has an id easy research
    static unsigned id;
    //dunno if I'll add unary neurones
    T _val1, _val2;
    //useful for map type
    bool exists (const unsigned & id) const;

public:
    Neurone(const T & val1, const T & val2);
    //will only call specific nerone constructor
    virtual T useNeur (const T & val1, const T & val2) = 0;
    //once again for easier research
    virtual const std::string getType () const = 0;
    unsigned getId() const;
    const T & getFirstVal () const;
    const T & getSecondVal () const;
    //todo
    //main use of the "neuronal network" I think I'll change it later
    void communicateWith (const unsigned & NeurId) const;
    virtual ~Neurone ();
};

template<typename T>
Neurone<T>::Neurone (const T & val1, const T & val2) {
    _val1 = val1;
    _val2 = val2;
    ++id;
}

template<typename T>
bool Neurone<T>::exists(const unsigned & id) const {
    //search through each neurone id to know if it exists in the list
    for (unsigned currId : everyNeurs.first ())
        if (currId == id)
            return true;
    return false;
}

template <typename T>
unsigned Neurone<T>::getId () const {
    return this->id;
}

template<typename T>
const T &Neurone<T>::getFirstVal() const {
    return this->_val1;
}

template<typename T>
const T &Neurone<T>::getSecondVal() const {
    return this->_val2;
}

template<typename T>
void Neurone<T>::communicateWith(const unsigned &NeurId) const {
    if (exists(NeurId))
        everyNeurs[NeurId].useNeur (this->_val1, this->_val2);
    else
        throw ("Neurone inexistant");
}



#endif // NEURONE_H
