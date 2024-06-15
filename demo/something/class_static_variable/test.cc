#include "../../common/common.h"

struct my_test_class {
	static int a;
	int b;
};

int my_test_class::a = 1;

void test_struct_static_variable() {
	my_test_class t1;
	my_test_class t2;
	t1.a = 1;
	cout << "t1.a:" << t1.a << endl;

	t2.a = 2;
	cout << "t2.a:" << t2.a << endl;
	cout << "t1.a:" << t1.a << endl;
}

int main() {
	test_struct_static_variable();

	return 0;
}

