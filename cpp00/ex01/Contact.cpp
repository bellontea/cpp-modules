#include "Contact.hpp"

std::string Contact::field_name[] = {
	"firstname",
	"lastname",
	"nickname",
	"phone",
	"secret"
};

Contact::Contact()
{
	for (size_t i = 0; i < FIELD_SIZE; i++)
		contact[i] = std::string();
}

Contact::~Contact()
{

}

std::string Contact::get_field(std::string field)
{
	for (size_t i = 0; i < FIELD_SIZE; i++)
		if (field_name[i] == field)
			return (contact[i]);
	return ("");
}

void Contact::set_field(std::string field, std::string value)
{
	for (size_t i = 0; i < FIELD_SIZE; i++)
		if (field_name[i] == field)
			contact[i] = value;
}

std::string Contact::get_field_name(int index)
{
	return (field_name[index]);
}

void Contact::print_contact()
{
	for (size_t i = 0; i < FIELD_SIZE; i++)
		std::cout << get_field_name(i) << ": " << contact[i] << "\n";
	
}