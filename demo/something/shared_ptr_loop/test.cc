#include <iostream>  
#include <memory>  
  
class B; // 前置声明，因为A中需要用到B的指针  
  
class A {  
public:  
    std::shared_ptr<B> b_ptr;  
    ~A() { std::cout << "Destroying A\n"; }  
};  
  
class B {  
public:  
    std::shared_ptr<A> a_ptr;  
    ~B() { std::cout << "Destroying B\n"; }  
};  


// ~__shared_ptr() 为什么只会执行两次 而不是4次 ？？？  因为引用计数都是2减到1 没有执行对应类 A和B的析构函数，所以没有执行a_ptr、b_ptr 的析构函数
void test_func() {
	std::shared_ptr<A> a = std::make_shared<A>();  
    std::shared_ptr<B> b = std::make_shared<B>();  
  
    // 创建循环引用  
    a->b_ptr = b;  
    b->a_ptr = a;  
}
  
int main() {  
	test_func();

    // 此时，即使main函数结束，a和b也不会被销毁，因为它们的引用计数都大于1  
    std::cout << "Exiting main\n";  
    return 0;  
}  
  
// 预期输出中不会看到"Destroying A"和"Destroying B"，因为存在循环引用