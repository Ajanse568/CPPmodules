//
// Created by allej on 12/11/2023.
//

#ifndef CPPMODULES_SERIALIZER_HPP
#define CPPMODULES_SERIALIZER_HPP

#include <iostream>

struct Data {
    int i;
};
class Serializer {

private:
    Serializer();
    Serializer(const Serializer &obj);
    ~Serializer();
    Serializer &operator=(const Serializer &obj);
public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(void* raw);
};


#endif //CPPMODULES_SERIALIZER_HPP
