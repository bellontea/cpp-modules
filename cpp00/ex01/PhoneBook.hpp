#pragma once

#include "Contact.hpp"

#define CONTACTS_SIZE 8

class PhoneBook
{
private:
	Contact phone_book[CONTACTS_SIZE];
	int index_replace;

public:
	PhoneBook();
	~PhoneBook();
	void AddContact(Contact &contact);
	Contact GetContact(int index);
};


