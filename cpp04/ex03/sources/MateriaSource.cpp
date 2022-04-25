  #include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materials[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
		materials[i] = NULL;
	operator=(copy);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if(materials[i])
			delete materials[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (materials[i])
			delete materials[i];
		if(copy.materials[i])
			materials[i] = copy.materials[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	unsigned int i = 0;

	for (i = 0; i < 4; i++)
	{
		if (!materials[i])
		{
			materials[i] = materia->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && materials[i]; i++)
		if (materials[i] && materials[i]->getType() == type)
			return materials[i]->clone();
	return NULL;
}