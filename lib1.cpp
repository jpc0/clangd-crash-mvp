module;
#include <iostream>

export module lib1;
import lib2;

namespace Lib1{
	export void print() { std::cout << "" << '\n'; };
};
