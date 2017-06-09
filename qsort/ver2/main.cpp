#include <iostream>
#include <vector>
#include <algorithm>

template<class It>
int massSize(It bgn, It end)
{
	It left = bgn;
	int size = 0;
	while (left != end)
	{
		++size;
		++left;
	}
	return size;
}

template<class It>
It getMiddle(It bgn, It end)
{
	It middle = bgn;
	int size = massSize(bgn, end);
	for (int i = 0; i < size / 2 + (size % 2); ++i)
	{
		++middle;
	}
	return middle;
}
template<typename smth>
bool compare(smth first, smth second)
{
	return first < second;
}

template<class It, class Cmp>
void my_qsort(It bgn, It end, Cmp cmp)
{
	It tmp;
	It left = bgn;
	It right = end;
	--right;
	It middle = getMiddle(bgn, end);

	if (massSize(bgn, end) < 3)
	{
		if (cmp(*right, *left))
			std::iter_swap(left, right);

		return;
	}



	bool le = 0;
	bool ri = 0;

	while (left != right) {
		while (middle != left) {
			if (!(cmp(*left, *middle)) && (*middle != *left))
				break;
			++left;
		}
		while (right != middle) {
			if (!(cmp(*middle, *right)) && (*middle != *right))
				break;
			--right;
		}
		if (right != left) {
			if (right == middle)
				ri = 1;
			if (left == middle)
				le = 1;
		}
		std::iter_swap(right, left);
		middle = getMiddle(bgn, end);
		if (ri == 1) {
			right = end;
			--right;
			ri = 0;
		}
		if (le == 1) {
			left = bgn;
			le = 0;
		}
	}
	my_qsort(bgn, middle, cmp);
	my_qsort(middle, end, cmp);
};



int main() {
	//const size_t N = 10;
	std::vector<int> mint = {1, 2, 6, 6, 3, 2, 2, 7};
	//std::generate(mint.begin(), mint.end(), rand);
	my_qsort(mint.begin(), mint.end(), &compare<int>);

	for (int i = 0; i < mint.size(); ++i)
	{
		std::cout << mint[i] << std::endl;
	}
	std::cout << std::is_sorted(mint.begin(), mint.end(), &compare<int>);
}
