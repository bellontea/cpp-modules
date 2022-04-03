#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (size_t i = 0; i < CONTACTS_SIZE; i++)
		phone_book[i] = Contact();
	index_replace = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact(Contact &contact)
{
	phone_book[index_replace] = contact;
	index_replace++;
	if (index_replace >= CONTACTS_SIZE)
		index_replace = 0;
}

Contact PhoneBook::GetContact(int index)
{
	if (index >= 0 && index < CONTACTS_SIZE && !phone_book[index].get_field("firstname").empty())
		return (phone_book[index]);
	return (Contact());
}