#include <iostream>

struct Friend
{
	int length;
	char name[20];
};

int GetLength(char* name)
{
	char* ptr2 = name;
	int number{};

	while (*ptr2 != '\0')
	{
		ptr2++;
		number++;
	}

	return number;
};

int Max(Friend* name, int count)
{
	Friend* ptr3 = name;
	int temp{};
	int maxnum = ptr3[0].length;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			temp = ptr3[i].length > ptr3[j].length ? ptr3[i].length : ptr3[j].length;

			if (maxnum <= temp)
			{
				maxnum = temp;
			}
		}
	}

	return maxnum;
};

int main()
{
	int count, maximum{};
	std::cout << "몇 명의 친구가 있나요?" << std::endl;
	std::cin >> count;

	Friend* ptr1 = new Friend[count];

	for (int i = 0; i < count; i++)
	{
		std::cout << "친구 #" << i + 1 << ":";
		std::cin >> ptr1[i].name;
	}

	for (int i = 0; i < count; i++)
	{
		ptr1[i].length = GetLength(ptr1[i].name);
	}

	maximum = Max(ptr1, count);

	for (int i = 0; i < count; i++)
	{
		if (ptr1[i].length == maximum)
		{
			std::cout << "이름이 가장 긴 친구는 " << ptr1[i].name << "입니다.";
		}
	}

	delete[] ptr1;
	ptr1 = nullptr;
}