#pragma once

#include <iostream>
#include <string.h>
#include <stdint.h>

#define FIELD_SIZE 5

class Contact
{
private:
	std::string contact[FIELD_SIZE];
	static std::string field_name[FIELD_SIZE];

public:
	Contact();
	~Contact();
	
	std::string get_field(std::string field);
	void set_field(std::string field, std::string value);
	static std::string get_field_name(int index);
	void print_contact();
};
