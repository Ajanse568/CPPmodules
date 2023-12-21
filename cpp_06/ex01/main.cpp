#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
	Data *data = new Data;
	data->i = 3;
	data->s = "Haii";
    std::cout << "Dataptr: " << data << std::endl;
    std::cout << "&Dataptr: " << &data << std::endl;
    std::cout << "&data->i: " << &data->i << std::endl;
    std::cout << "&data->s: " << &data->s << std::endl << std::endl;
	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "uintptr_t: " << ptr << std::endl;
    std::cout << "uintptr_t to hex: 0x" << std::hex << ptr << std::endl;
    std::cout << "&uintptr_t:: " << &ptr << std::endl << std::endl;
	data = Serializer::deserialize(ptr);
	std::cout << "data2->i: " << data->i << std::endl;
	std::cout << "data2->s: " << data->s << std::endl;
    std::cout << "&data2->i: " << &data->i << std::endl;
    std::cout << "&data2->s: " << &data->s << std::endl;
	std::cout << "&data2: " << &data << std::endl;
	return 0;
}
