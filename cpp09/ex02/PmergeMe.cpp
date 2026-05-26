#include <stdexcept>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe & PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other) {
			(void)other;
		}
		return *this; 
}

PmergeMe::PmergeMe(char **av, int ac)
{
	int i = 1;
	while(i < ac)
	{
		std::stringstream ss(av[i]);
		int number;

		if (!(ss >> number) || !ss.eof()) {
			throw std::invalid_argument("Error: bad input");
		} else {
			if(number < 0)
				throw std::invalid_argument("ERROR");
			_v_elementsBefore.push_back(number);
			_v_elements.push_back(number);
			_d_elements.push_back(number);
		}
		i ++;
	}
	for (std::vector<int>::iterator it = _v_elements.begin(); it != _v_elements.end(); ++it) {
		std::vector<int>::iterator next_it = it + 1;
		std::vector<int>::iterator found = std::find(next_it, _v_elements.end(), *it);

		if (found != _v_elements.end()) {
			throw std::invalid_argument("value repited find");
		}
	}

}

std::vector<size_t> getJacobOrders(size_t pend_size) {
	std::vector<size_t> order;
	if (pend_size == 0) return order;

	order.push_back(0);
	
	size_t last_jacob = 1;
	size_t curr_jacob = 3;
	size_t last_pos = 0;

	while (last_pos < pend_size - 1) {
		size_t target_pos = (curr_jacob - 1 < pend_size) ? (curr_jacob - 1) : (pend_size - 1);
		
		size_t i = target_pos;
		while (i > last_pos) {
			order.push_back(i);
			i--;
		}
		
		last_pos = target_pos;
		size_t next_jacob = curr_jacob + 2 * last_jacob;
		last_jacob = curr_jacob;
		curr_jacob = next_jacob;
	}
	return order;
}

void PmergeMe::sortVector(std::vector<int>& vec) {
	clock_t start = clock();
	if (vec.size() <= 1)
		return;

	bool haveImp = false;
	int imp = 0;
	if (vec.size() % 2 != 0) {
		imp = vec.back();
		vec.pop_back();
		haveImp = true;
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::vector<int> highest;
	for (size_t i = 0; i < pairs.size(); i++) {
		highest.push_back(pairs[i].first);
	}

	sortVector(highest);
	std::vector<int> main_chain = highest;
	std::vector<int> pend;

	for (size_t i = 0; i < main_chain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (main_chain[i] == pairs[j].first) {
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	std::vector<size_t> order = getJacobOrders(pend.size());

	if (!pend.empty()) {
		main_chain.insert(main_chain.begin(), pend[0]);
	}

	for (size_t i = 1; i < order.size(); i++) {
		int element = pend[order[i]];
		std::vector<int>::iterator insertion_point = std::upper_bound(main_chain.begin(), main_chain.end(), element);
		main_chain.insert(insertion_point, element);
	}

	if (haveImp) {
		std::vector<int>::iterator insertion_point = std::upper_bound(main_chain.begin(), main_chain.end(), imp);
		main_chain.insert(insertion_point, imp);
	}

	vec = main_chain;
	clock_t end = clock();
	_timeVector = (double)(end - start) / CLOCKS_PER_SEC;
}

std::deque<size_t> getJacobOrdersDeque(size_t pend_size) {
	std::deque<size_t> order;
	if (pend_size == 0) return order;

	order.push_back(0);
	
	size_t last_jacob = 1;
	size_t curr_jacob = 3;
	size_t last_pos = 0;

	while (last_pos < pend_size - 1) {
		size_t target_pos = (curr_jacob - 1 < pend_size) ? (curr_jacob - 1) : (pend_size - 1);
		
		size_t i = target_pos;
		while (i > last_pos) {
			order.push_back(i);
			i--;
		}
		
		last_pos = target_pos;
		size_t next_jacob = curr_jacob + 2 * last_jacob;
		last_jacob = curr_jacob;
		curr_jacob = next_jacob;
	}
	return order;
}


void PmergeMe::sortDeque(std::deque<int>& vec) {
	clock_t start = clock();
	if (vec.size() <= 1)
		return;

	bool haveImp = false;
	int imp = 0;
	if (vec.size() % 2 != 0) {
		imp = vec.back();
		vec.pop_back();
		haveImp = true;
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::deque<int> highest;
	for (size_t i = 0; i < pairs.size(); i++) {
		highest.push_back(pairs[i].first);
	}

	sortDeque(highest);
	std::deque<int> main_chain = highest;
	std::deque<int> pend;

	for (size_t i = 0; i < main_chain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (main_chain[i] == pairs[j].first) {
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	std::deque<size_t> order = getJacobOrdersDeque(pend.size());

	if (!pend.empty()) {
		main_chain.insert(main_chain.begin(), pend[0]);
	}

	for (size_t i = 1; i < order.size(); i++) {
		int element = pend[order[i]];
		std::deque<int>::iterator insertion_point = std::upper_bound(main_chain.begin(), main_chain.end(), element);
		main_chain.insert(insertion_point, element);
	}

	if (haveImp) {
		std::deque<int>::iterator insertion_point = std::upper_bound(main_chain.begin(), main_chain.end(), imp);
		main_chain.insert(insertion_point, imp);
	}

	vec = main_chain;
	clock_t end = clock();
	_timeDeque = (double)(end - start) / CLOCKS_PER_SEC;
}

std::vector<int> PmergeMe::getVElemtents()
{
	return _v_elements;
}

std::deque<int> PmergeMe::getDElemtents()
{
	return _d_elements;
}

double PmergeMe::getTimeVector()
{
	return _timeVector;
}

double PmergeMe::getTimeDeque()
{
	return _timeDeque;
}

void printfVector(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << " ";
			if(i > 4)
			{
				std::cout << "[..]";
				break;
			}
	}
	std::cout << "" << std::endl;
}

void PmergeMe::printSort(std::vector<int> vec)
{
	std::cout << "Before:   ";
	printfVector(_v_elementsBefore);
	std::cout << "After:    ";
	printfVector(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "<< _timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "<< _timeDeque << " us" << std::endl;

}

