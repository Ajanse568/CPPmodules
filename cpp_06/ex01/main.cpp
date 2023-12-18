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
	Data *data2 = Serializer::deserialize(ptr);
	std::cout << "data2->i: " << data2->i << std::endl;
	std::cout << "data2->s: " << data2->s << std::endl;
    std::cout << "&data2->i: " << &data2->i << std::endl;
    std::cout << "&data2->s: " << &data2->s << std::endl;
	std::cout << "&data2: " << &data2 << std::endl;
	return 0;
}
