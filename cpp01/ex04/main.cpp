/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:13:45 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/25 18:26:16 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "<name file> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string av1 = av[1];
	std::string av2 = av[2];
	if(av1.empty() == 1 || av2.empty() == 1)
	{
		std::cout << "Error: empty argument." << std::endl;
		return 1;
	}
	std::ifstream MyReadFile(av[1]);
	if (!MyReadFile.is_open()) {
		perror("Error");
		return 1;
	}
	std::string textFile;
	std::string nameFile = av[3];
	nameFile += ".replace";

	int j;
	int i;
	int first = 0;
	std::ofstream MyFile(nameFile);
	while (getline (MyReadFile, textFile)) {
		i = 0;
		if(first == 1)
		{
			MyFile << std::endl;
		}
		while(textFile[i] != '\0')
		{
			j = 0;
			if(textFile[i] == av[2][j])
			{
				while(textFile[i + j] == av[2][j])
				{
					j ++;
				}
				std::cout << j << std::endl;
				if(av[2][j] == '\0')
				{
					MyFile << av[3];
					i += j;
				}
			}
			MyFile << textFile[i];
			i++;
			first = 1;
		}
	}

    MyFile.close();
	MyReadFile.close();
	
}