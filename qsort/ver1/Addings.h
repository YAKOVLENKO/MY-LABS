#include<iostream>


template<class It>
int size_of_mass(It left, It right)
{
	int size = 0;
	while (left != right)
	{
		++size;
		++left;
	}
	return size;
}

template<class It>
It getMiddle(It left,It right)
{
	It middle = left;
	int s = size_of_mass(left, right);
	for (int i = 0; i < ( (int)(s / 2)); ++i)
	{
		++middle;
	}
	return middle;
}

template<class It, class Cmp>
void qsort_for_one(It beg, It end, Cmp cmp)
{
	//if (size_of_mass(beg, end) < 3)
	//	return;

	It tmp;
	It left = beg;
	It right = end;
	//test tmp1;
	It middle = getMiddle(left, right);
	--right;
	while (left != right)
	{
		while (left != middle)
		{
			if (cmp(*left, *middle))
			{
				break;
			}
			++left;
		}
		while (right != middle)
		{
			if (cmp(*middle, *right))
			{
				break;
			}
			--right;
		}

		if (left == right) break;
		std::swap(*left, *right);
		//std::itersw
		//*tmp = left;
		//left = right;
		//right = tmp;
		//tmp1 = *left;
		//*left = *right;
		//*right = tmp1;
		left = beg;
		right = end;
		middle = getMiddle(left, right);
		--right;

		//tmp = left;
		//left = right;
		//right = tmp;
	}
}
