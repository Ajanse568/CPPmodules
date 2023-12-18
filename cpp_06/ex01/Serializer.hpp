//
// Created by allej on 12/11/2023.
//

#ifndef CPPMODULES_SERIALIZER_HPP
#define CPPMODULES_SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    int i;
    std::string s;
};
class Serializer {

private:
    Serializer();
    Serializer(const Serializer &obj);
    ~Serializer();
    Serializer &operator=(const Serializer &obj);
public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif //CPPMODULES_SERIALIZER_HPP
