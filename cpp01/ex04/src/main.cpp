/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:27:43 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/14 11:29:37 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/*check arguments*/ 
bool	check_args(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: please add three parameters: filename, s1 and s2\n";
		return false;
	}
	if (std::string(argv[2]).empty())
	{
		std::cerr << "Error: s1 (the string to be replaced) cannot be empty.\n";
		return false;
	}
	return true;
}

/*open and create files*/
bool	open_files(std::string filename, std::ifstream &infile, std::ofstream &outfile)
{
	std::string			outfilename;

	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file " << filename << "\n";
		return false;
	}
	outfilename = filename + ".replace";
	outfile.open(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not create file " << filename << ".replace\n";
		return false;
	}
	return true;
}

/*
- Reads each line from infile.
- Replaces every occurrence of s1 with s2.
- Writes the modified line to outfile.

std::string::npos is a special constant in C++ that means "not found"
*/
void	read_and_replace(std::ifstream &infile, std::ofstream &outfile, char ** argv)
{
	std::string			line;
	std::string			outline;
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	size_t				pos_start;
	size_t				pos_found;


	while (std::getline(infile, line))
	{
		outline = "";
		pos_start = 0;
		pos_found = line.find(s1, pos_start);
		while (pos_found != std::string::npos)
		{
			outline += line.substr(pos_start, pos_found - pos_start);
			outline += s2;
			pos_start = pos_found + s1.length();
			pos_found = line.find(s1, pos_start);
		}
		outline += line.substr(pos_start);
		outfile << outline << "\n";
	}
}

int	main(int argc, char** argv)
{
	std::string 	filename;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (!check_args(argc, argv))
		return 1;
	filename = argv[1];
	if (!open_files(filename, infile, outfile))
		return 1;
	read_and_replace(infile, outfile, argv);
	infile.close();
	outfile.close();
	return 0;
}
