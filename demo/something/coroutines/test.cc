#include <coroutine>
#include <iostream>
#include <stdexcept>
#include <thread>

using std::cout;
using std::endl;
 
auto switch_to_new_thread(std::jthread& out)
{
    struct awaitable
    {
        std::jthread* p_out;
        bool await_ready() { cout << "await_ready" << endl; return false; }
        void await_suspend(std::coroutine_handle<> h)
        {
			cout << "await_suspend" << endl << endl;
            std::jthread& out = *p_out;
            if (out.joinable())
                throw std::runtime_error("Output jthread parameter not empty");
            out = std::jthread([h] { h.resume(); });
            // Potential undefined behavior: accessing potentially destroyed *this
            // std::cout << "New thread ID: " << p_out->get_id() << '\n';
            //std::cout << "New thread ID: " << out.get_id() << '\n'; // this is OK
			//cout << "end await_suspend" << endl;
        }
        void await_resume() { cout << "await_resume" << endl; }
    };
    return awaitable{&out};
}
 
struct task
{
    struct promise_type
    {
        task get_return_object() { cout << "get_return_object" << endl; return {}; }
        std::suspend_never initial_suspend() { cout << "initial_suspend" << endl << endl; return {}; }
        std::suspend_never final_suspend() noexcept { cout << "final_suspend" << endl; return {}; }
        void return_void() {cout << "return_void" << endl; }
        void unhandled_exception() { cout << "unhandled_exception" << endl; }
    };
};
 
task resuming_on_new_thread(std::jthread& out)
{
    //std::cout << "Coroutine started on thread: " << std::this_thread::get_id() << '\n';
	cout << "start co_await" << endl;
    co_await switch_to_new_thread(out);
	cout << "end co_await" << endl << endl;
    // awaiter destroyed here
    //std::cout << "Coroutine resumed on thread: " << std::this_thread::get_id() << '\n';
}
 
int main()
{
    std::jthread out;
    resuming_on_new_thread(out);
}