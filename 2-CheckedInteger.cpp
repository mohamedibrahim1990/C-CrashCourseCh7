#include <iostream>
#include <limits>
#include <cstdio>
#include <stdexcept>

struct CheckedInteger {
	CheckedInteger(unsigned int value) : value{ value } {}

	CheckedInteger operator+(unsigned int other) const {
		CheckedInteger result{ value + other };
		if (result.value < value) throw std::overflow_error{ "OverFlow!" };
		return result;
	}

	const unsigned int value;
};

int main() {
	CheckedInteger a{ 100 };
	auto b = a + 200;
	printf("a + 200 = %u\n", b.value);
	try {
		std::cout << "max of unsigned int " << std::numeric_limits<unsigned int>::max() 
			<< std::endl;
		auto c = a + std::numeric_limits<unsigned int>::max();
	}
	catch (const std::overflow_error& e) {
		printf("(a+max) Exception: %s\n", e.what());
	}
}
