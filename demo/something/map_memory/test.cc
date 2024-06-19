#include "../../common/common.h"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <vector>

#include <unistd.h>

using std::set;
using std::unordered_set;
using std::shared_ptr;
using std::make_shared;
using std::hash;
using std::map;
using std::unordered_map;
using std::pair;
using std::vector;

//
// 3*ptr(parent left right) + my_Rb_tree_color tree node 32 应该是有struct对齐
//

// 16G
// tree node  + 1*pair<k,v> 32+1*8 40   malloc 40 统计结果为48,这是实现相关忽略就可以
//
// all 
void test_map_memory() {
	int const n = 1024*1024*10;
	map<int, int> map_data;

	{
		cout << "insert" << endl;
		print_process_time cost_time;
		for (int i = 0; i < n; i++) {
			//map_data[i] = i;
		}
	}
	{
		cout << "get" << endl;
		print_process_time cost_time;
		for (int i = 0; i < n; i++) {
			map_data.find(i);
			auto tmp = map_data[i];
		}
	}

	while(true){};
}
struct node {
	node():a(1),b(2){}
	long a;
	long b;
	long c;
	long d;
	long f;
	char data[1];  //加上后 那个node 占用 64字节 不加时48字节
};

// 初步分析 malloc基础大小是32, 16一步向上增加
const int tmp_malloc_dest = 471964*1024/1000/1000/10;
void tmp_malloc() {
	const int n = 1000*1000*10;
	auto start_size = getpagesize();
	//vector<int*> ptr_array(n);
	for (int i = 0; i < n; i++) {
		//ptr_array[i] = new int(i);
		auto tmp = new node();
	}

	auto end_size = getpagesize();

	cout << "tmp_malloc size:" << end_size - start_size << endl;
	//cout << "capacity:" << ptr_array.capacity() << endl;

	auto ptr1 = new int(1);
	auto ptr2 = new int(2);
	cout << "ptr2 - ptr1:" << ptr2 - ptr1 << endl;

	while(true){}
}

int main() {
	test_map_memory();
	//tmp_malloc();

	return 0;
}

