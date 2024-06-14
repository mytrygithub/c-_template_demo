#include "../../common/common.h"

using std::is_void;
using std::enable_if;

void test_enable_if() {
	enable_if<is_void<void>::value, int>::type is_void_true; 	//这里相当于 int is_void_true
	enable_if<is_void<int>::value, int>::type is_void_false;	//编译错误
	is_void_true = 1;
	is_void_false = 1;											//编译错误

	enable_if<true, int>::type true_flag;
	enable_if<false, int>::type false_flag;  					//编译错误

	printf_type_info("is_void_true", 	typeid(is_void_true).name());
	printf_type_info("is_void_false", 	typeid(is_void_false).name());
	printf_type_info("true_flag", 		typeid(true_flag).name());
}


int main() {
	test_enable_if();

	return 0;
}

