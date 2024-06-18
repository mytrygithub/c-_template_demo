#include "../../common/common.h"
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <memory>

using std::set;
using std::unordered_set;
using std::shared_ptr;
using std::make_shared;
using std::hash;
using std::unordered_map;

struct A{
	int a;
};

struct B{
	double b;
};

struct C:public A{
	//explicit C(int n) { a = n; }
};

void test_static_cast() {
	A a;
	B b;
	C c;

	// error: no matching function for call to ‘B::B(A&)’
	//auto c = static_cast<B>(a);
	// error: no matching function for call to ‘C::C(A&)’
	//auto c_cast = static_cast<C>(a);
	A* a_ptr = new A();
	B* b_ptr = new B();
	C* c_ptr = new C();

	//error: invalid static_cast from type ‘A*’ to type ‘B*’
	//auto d_ptr = static_cast<B*>(a_ptr);
	auto e_ptr = static_cast<A*>(c_ptr);
	auto f_ptr = static_cast<C*>(a_ptr);
}

int main() {
	test_static_cast();

	return 0;
}

