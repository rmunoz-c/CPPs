/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 12:35:02 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 12:35:02 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file '" << filename << "' for reading" << std::endl;
		return (1);
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not open file '" << filename << ".replace' for writing" << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		std::string::size_type pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	return (0);
}
