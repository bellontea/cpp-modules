#include <iostream>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw) {

	return reinterpret_cast<Data*>(raw);
}


int	main() {

	Data	data;

	data.name = "Data";

	std::cout << "before serialization:	" << &data << std::endl;

	uintptr_t	ser = serialize(&data);
	std::cout << "serialization:	" << (void *)(ser) << std::endl;
	Data*		des = deserialize(ser);

	std::cout << "after serialization:	" << des << std::endl;

	des->name = "Man";

}