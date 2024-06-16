#include "../../common/common.h"

using std::remove_cv;

void test_remove_cv() {
	int i = 1;
	int const i_c = 1;
	int const volatile i_c_v = 1;
	int volatile const i_v_c = 1;
	const int volatile c_i_v = 1;
	const volatile int c_v_i = 1;
	volatile const int v_c_i = 1;
	volatile int const v_i_c = 1;
	int &ref_i = i;
	
	printf_type_info("int", typeid(i).name());
	printf_type_info("int const", typeid(i_c).name());

	printf_type_info("int const volatile", typeid(i_c_v).name());  // typeid 可以获取运行时类型 所以const 和 volatile 运行时不会有记录，只有int 返回
	printf_type_info("int volatile const", typeid(i_v_c).name());
	printf_type_info("const int volatile", typeid(c_i_v).name());
	printf_type_info("const volatile int", typeid(c_v_i).name());
	printf_type_info("volatile const int", typeid(v_c_i).name());
	printf_type_info("volatile int const", typeid(v_i_c).name());

	printf_type_info("ref_i", typeid(ref_i).name());
}


int main() {
	test_remove_cv();

	return 0;
}

