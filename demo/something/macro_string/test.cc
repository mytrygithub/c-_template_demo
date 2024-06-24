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

#define STRINGIZE(x) #x  
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x) 
int main() {
	cout << "_GLIBCXX_INLINE_VERSION\t" << STRINGIZE_VALUE_OF(_GLIBCXX_INLINE_VERSION) << endl;
	cout << "_GLIBCXX_BEGIN_NAMESPACE_VERSION:" << STRINGIZE_VALUE_OF(_GLIBCXX_BEGIN_NAMESPACE_VERSION) << endl;

	return 0;
}

