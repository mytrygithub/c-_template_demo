#include "../../common/common.h"

using std::is_array;

void test_is_array() {
	is_array<int[]> i_no_size;
	is_array<int[16]> is_size_16;
	is_array<int> is_not_size;

	is_array<int[]>::value_type i_no_size_value = is_array<int[]>::value;
	is_array<int[16]>::value_type is_size_16_value = is_array<int[16]>::value;
	is_array<int>::value_type is_not_size_value = is_array<int>::value;
	
	cout << "i_no_size_value:" << i_no_size_value << endl;
	cout << "is_size_16_value:" << is_size_16_value << endl;
	cout << "is_not_size_value:" << is_not_size_value << endl;
	
	printf_type_info("i_no_size", typeid(i_no_size).name());
	printf_type_info("is_size_16", typeid(is_size_16).name());
	printf_type_info("is_not_size", typeid(is_not_size).name());

	printf_type_info("i_no_size_value", typeid(i_no_size_value).name());
	printf_type_info("is_size_16_value", typeid(is_size_16_value).name());
	printf_type_info("is_not_size_value", typeid(is_not_size_value).name());

	int del_int;
	int del_int_array[]{1,2,3};
	int del_int_array_32[32];
	decltype(del_int) del_int_variable;
	decltype(del_int_array) del_int_array_variable;
	decltype(del_int_array_32) del_int_array_32_variable;

	is_array<decltype(del_int)> del_int_is_array;
	is_array<decltype(del_int_array)> del_int_array_is_array;
	is_array<decltype(del_int_array_32)> del_int_array_32_is_array;

	printf_type_info("del_int_is_array", typeid(del_int_is_array).name());
	printf_type_info("del_int_array_is_array", typeid(del_int_array_is_array).name());
	printf_type_info("del_int_array_32_is_array", typeid(del_int_array_32_is_array).name());
}


int main() {
	test_is_array();

	return 0;
}

