#include "../../common/common.h"
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <mcheck.h>

using std::set;
using std::unordered_set;
using std::shared_ptr;
using std::make_shared;
using std::hash;
using std::unordered_map;

using std::_Sp_counted_ptr;
using std::_Sp_counted_base;

using mutex_base = std::_Mutex_base<__gnu_cxx::_S_atomic>;
using test_base = _Sp_counted_base<__gnu_cxx::_S_atomic>;
using test_derived = _Sp_counted_ptr<int*, __gnu_cxx::_S_atomic>;

struct tmp_base1{};
struct tmp_derived:public tmp_base1 {
	int a;
};

struct tmp_base_virtual {
	tmp_base_virtual() {};
	void virtual func1() {};
	void virtual func2() {};
	void virtual func3() {};

	long a;
};

struct tmp_derived_virtual:public tmp_base_virtual {
	tmp_derived_virtual() {};
	int b;
};

int main() {
	auto *virtual_base_ptr = new tmp_base_virtual();
	auto *virtual_derived_ptr = new tmp_derived_virtual();

	mtrace();

	int* int_ptr = new int(1);
	test_base *count_ptr = new test_derived(int_ptr);
	muntrace();

	cout << "test_base size:" << sizeof(test_base) << endl;
	cout << "test_derived size:" << sizeof(test_derived) << endl;

	cout << "_Mutex_base size:" << sizeof(mutex_base) << endl;

	cout << "tmp_base1 size:" << sizeof(tmp_base1) << endl;
	cout << "tmp_derived size:" << sizeof(tmp_derived) << endl;
	
	cout << "tmp_base_virtual size:" << sizeof(tmp_base_virtual) << endl;
	cout << "tmp_derived_virtual size:" << sizeof(tmp_derived_virtual) << endl;


	return 0;
}

