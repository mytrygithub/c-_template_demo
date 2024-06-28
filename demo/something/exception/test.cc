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

class my_test_ptr : public std::exception
  {
  public:
    virtual char const* what() const noexcept { return "my_test_ptr"; };

    virtual ~my_test_ptr() noexcept {};
  };

void test_exception() {
	try {
		throw my_test_ptr();
	} catch (std::exception &e) {
		cout << "e.what():" << e.what() << endl;
	}
}

int main() {
	test_exception();

	return 0;
}

