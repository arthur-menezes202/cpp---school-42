#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
#include <utility>
#include <ctime>

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
	private:
		std::vector<int> _v_elements;
		std::vector<int> _v_elementsBefore;
    	std::deque<int> _d_elements;
		double _timeVector;	
		double _timeDeque;	
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe & operator=(PmergeMe const &other);
		void sortVector(std::vector<int>& _v_elements);
		void sortDeque(std::deque<int>& vec);
		PmergeMe(char **av, int ac);
		std::vector<int> getVElemtents();
		std::deque<int> getDElemtents();

		void printSort(std::vector<int> vec);
		double getTimeVector();
		double getTimeDeque();

};

#endif