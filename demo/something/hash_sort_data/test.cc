#include "../../common/common.h"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <memory>

using std::set;
using std::unordered_set;
using std::shared_ptr;
using std::make_shared;
using std::hash;
using std::map;
using std::unordered_map;
using std::pair;

/*template<typename T>
struct node:public shared_ptr<T> {
	bool operator<(node const &other) {
		return *this < *other;
	}

	//using element_type = shared_ptr<T>::element_type;
};*/



template<typename T>
struct myhash {
    size_t operator()(const T& k) const {
        // 返回一个基于MyClass对象的hash值
        return hash<typename T::element_type>()(*k);
    }
};

template<typename T>
struct mycompare {
    size_t operator()(const T& a, const T& b) const {
        return *a < *b;
    }
};

template<typename K, typename V>
struct hash_sort_data {
	hash_sort_data(int size = 1024) {
		hash_data.reserve(size);
	}
	~hash_sort_data() {
		//for (auto const &items:sort_data) {
		for (auto const &items:hash_data) {
			delete items.second;
		}
	}

	void insert(K k, V v) {
		auto node = new V(v);
		sort_data.insert({k,node});
		hash_data[k] = node;
	}

	void erase(K k) {
		sort_data.erase(k);
		hash_data.erase(k);
	}

	V &get_sort_data(K k) {
		return *sort_data[k];
	}

	V &get_hash_data(K k) {
		return *hash_data[k];
	}

	size_t size() {
		return sort_data.size();
	}

private:
	map<K, V*> sort_data;
	unordered_map<K, V*> hash_data;
};

// 16G
// node shared_ptr ptr count k v 24
// sort k 4 tree_node 32   1*shared_ptr+1*node 8+32 40
// hash k 4	v ptr 8       16
//
// all 64  基本统计 实际会有空隙，malloc自动适配 方便使用 所以空间估计和实际使用不同
void test_hash_sort_data() {
	int const n = 1000*1000*10;
	hash_sort_data<int, int> memory_data(n);

	{
		cout << "insert" << endl;
		print_process_time cost_time;
		for (int i = 0; i < n; i++) {
			memory_data.insert(i,i);
		}
	}
	{
		cout << "get_sort_data" << endl;
		print_process_time cost_time;
		for (int i = 0; i < n; i++) {
			memory_data.get_sort_data(i);
		}
	}
	{
		cout << "get_hash_data" << endl;
		print_process_time cost_time;
		for (int i = 0; i < n; i++) {
			memory_data.get_hash_data(i);
		}
	}
	cout << "sort data size:" << memory_data.size()/1000/1000 << "M" << endl;
}

struct test_des {
	~test_des() { cout << "~test_des" << endl; }
	int a;
};

// map 中value 指针不会执行析构函数
void tmp_test_func() {
	map<int, test_des*> data1;
	data1[1] = new test_des();
	map<int, test_des> data2;
	data2[1] = test_des();
}

int main() {
	test_hash_sort_data();
	//tmp_test_func();
	while(true){};
	return 0;
}

