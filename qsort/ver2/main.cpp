#include <iostream>
#include <vector>

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
	return first >= second;
}

template<class It, class Cmp>
void my_qsort(It bgn, It end, Cmp cmp)
{
	It tmp;
	It left = bgn;
	It right = end;
	--right;
	It middle = getMiddle(bgn, end);

	bool le = 0;
	bool ri = 0;
	if (massSize(bgn, end) < 3)
	{
		if (cmp(*left, *right))
		{
			std::iter_swap(left, right);
		}
		return;
	}


	while (left != right) {
		while (cmp(*middle, *left)) {
			if (cmp(*left, *middle))
				break;
			++left;
		}
		while (cmp(*right, *middle)) {
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
			right = --end;
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
	std::vector<int> mint = { 1, 5, 7, 3, 6, 4, 8, 10, 2, 1 };

	my_qsort(mint.begin(), mint.end(), &compare);
	for (int i = 0; i < mint.size(); ++i)
	{
		std::cout << mint[i] << std::endl;
	}
}