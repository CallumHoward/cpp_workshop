
#include <iostream>
#include <iomanip> // to use the setprecision manipulator

int main() {
	std::cout << 1331 << std::endl;
	std::cout << "In hex " << std::hex << 1331 << std::endl;
	std::cout << 1331.123456 << std::endl;
	std::cout.setf(std::ios::scientific, std::ios::floatfield);
	std::cout << 1331.123456 << std::endl;
	std::cout << std::setprecision(3) << 1331.123456 << std::endl;
	std::cout << std::dec << 1331 << std::endl;
	std::cout.fill('X');
	std::cout.width(8);
	std::cout << 1331 << std::endl;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout.width(8);
	std::cout << 1331 << std::endl;
	return 0;
}

