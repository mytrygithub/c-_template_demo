#include "../../common/common.h"

using std::is_void;
using std::is_constructible;

// 暂时无法验证 __is_constructible 的实现方式，待分析
void test_is_constructible() {
#if defined(__has_builtin)
	cout << "__has_builtin true" << endl;
#else
	cout << "__has_builtin false" << endl;
#endif
#if 0 //__has_builtin(__is_constructible)
	cout << "__is_constructible is builtin" << endl;
#endif
	//printf_type_info("true_flag",  typeid(true_flag).name());
}

struct A { A (int,int) {}; };

int main() {
	test_is_constructible();

	cout << std::boolalpha;
	cout << "is_constructible:" << endl;
	cout << "int: " << is_constructible<int>::value << endl;
	cout << "int(float): " << is_constructible<int,float>::value << endl;
	cout << "int(float,float): " << is_constructible<int,float,float>::value << endl;
	cout << "A: " << is_constructible<A>::value << endl;
	cout << "A(int): " << is_constructible<A,int>::value << endl;
	cout << "A(int,int): " << is_constructible<A,int,int>::value << endl;
	cout << "A(int,int,int): " << is_constructible<A,int,int,int>::value << endl;

	return 0;
}

