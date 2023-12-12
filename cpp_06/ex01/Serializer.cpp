//
// Created by allej on 12/11/2023.
//

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &obj) {
    *this = obj;
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=(const Serializer &obj) {
    if (this != &obj)
        *this = obj;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}