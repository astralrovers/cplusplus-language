#include <cstdio>
#include <vector>

int main(void)
{
	std::vector<int> a{2, 3, 4, 5, 6};

	for (auto item : a)
	{
		printf("%d\n", item);
	}
	return 0;
}
