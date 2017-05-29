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

bool compare(int first, int second)
{
	return first > second;
}

template<class It, class Cmp>
void my_qsort(It bgn, It end, Cmp cmp)
{
	if (massSize(bgn, end) < 3)
		return;

	It tmp;
	It left = bgn;
	It right = end;
	--right;
	It middle = getMiddle(bgn, end);

	bool le = 0;
	bool ri = 0;

	while (left != right) {
		while (middle != left) {
			if (cmp(*left, *middle))
				break;
			++left;
		}
		while (right != middle) {
			if (cmp(*middle, *right))
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
	std::vector<int> mint = { 29358, 26962, 26500, 24464, 19169, 18467, 15724, 11478, 6334, 41 };

	my_qsort(mint.begin(), mint.end(), &compare);

	for (int i = 0; i < mint.size(); ++i)
	{
		std::cout << mint[i] << std::endl;
	}
	std::cout << std::is_sorted(mint.begin(), mint.end());
}
