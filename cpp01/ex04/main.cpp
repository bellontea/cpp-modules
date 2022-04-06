#include <fstream>
#include <iostream>

int replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream infile;
    std::ofstream outfile;
	std::string buffer;
	size_t pos;

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
		infile.close();
		return (1);
	}

	while(getline(infile, buffer))
	{
		while ((pos = buffer.find(s1)) != std::string::npos)
		{
			outfile << buffer.substr(0, pos) << s2;
			buffer = buffer.substr(pos + s1.size());
		}
		outfile << buffer << std::endl;
	}

	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error!\n";
		return (1);
	}

	return replace(argv[1], argv[2], argv[3]);
}