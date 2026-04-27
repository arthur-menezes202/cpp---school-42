/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:57:31 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 11:58:15 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

std::string transform_line(std::string line, const std::string& s1, const std::string& s2) {
	if (s1.empty()) return line;

	std::string result;
	size_t pos = 0;
	size_t found_pos;
	while ((found_pos = line.find(s1, pos)) != std::string::npos) {
		result.append(line, pos, found_pos - pos);
		result.append(s2);
		pos = found_pos + s1.length();
	}
	result.append(line, pos, std::string::npos);
	
	return result;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 (string to find) cannot be empty." << std::endl;
		return 1;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		perror("Error opening input file");
		return 1;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		perror("Error creating output file");
		inputFile.close();
		return 1;
	}

	std::string line;
	bool first_line = true;
	while (std::getline(inputFile, line)) {
		if (!first_line) {
			outputFile << "\n";
		}
		if (!line.empty() && line[line.size() - 1] == '\r') {
			line.erase(line.size() - 1);
		}
		outputFile << transform_line(line, s1, s2);
		
		first_line = false;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}
