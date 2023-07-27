#include <iostream>

// the function is f(x) = x^2 - n, f'(x) = 2x
double newtons_root(double n) {
	double root = n;
	double eps = 1e-42;
	while (abs(root * root - n) >= eps) {
		root = root - (root * root - n) / (2 * root);
	}
	return root;
}

int main() {
	std::cout.precision(42);
	std::cout << newtons_root(42.0) << std::endl;
	return 0;
}

