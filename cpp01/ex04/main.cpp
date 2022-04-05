#include <fstream>
#include <iostream>

int replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream infile;
    std::ofstream outfile;
	std::string buffer;
	char *buf = new char;

	infile.open(filename.c_str());
	if (!infile)
	{
		std::cout << "Error!\n";
		return (1);
	}

	outfile.open((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cout << "Error!\n";
		return (1);
	}

	while(!infile.eof())
	{
		int i = 0;
		buffer = "";

		infile.read(buf, sizeof(char));
		while (!infile.eof() && s1[i] && s1[i] == *buf)
		{
			buffer += *buf;
			i++;
			infile.read(buf, sizeof(char));
		}

		buffer += *buf;
		if (s1[i] == '\0')
			outfile.write((s2 + *buf).c_str(), (s2 + *buf).length());
		else
			outfile.write(buffer.c_str(), buffer.length());

	}

	delete buf;

	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error!\n";
		return (1);
	}
	
	printf("%s\n", argv[2]);

	return replace(argv[1], argv[2], argv[3]);
}