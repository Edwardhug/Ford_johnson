# include "../includes/lib.hpp"
# include "../includes/PmergeMe.hpp"
# include <sys/time.h>
# include <ctime>

void *atoui(char *str) {
	unsigned long int ret;
	ret = 0;
	int i = 0;
	int	j = 1;

	while (str[i] && str[i + 1]) 
		i++;
	while (i >= 0) {
		ret += (str[i] - '0') * j;
		j *= 10;
		i--;
	}
	if (ret > 4294967295)
		throw (std::exception());
	void *addr = new unsigned long int(ret);
	return (addr);
}

void	PmergeMe::printResult(std::vector<std::pair<void *, void *> *> vec) {
	_deep = 1;
	for (std::vector<std::pair<void *, void *> *>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << dataOfPairVector(it) << " ";
	}
	std::cout << std::endl;
}

long long	getCurrentTimeInMilliseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}