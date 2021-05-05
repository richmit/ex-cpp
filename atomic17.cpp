#include <iostream>
#include <string>
#include <thread>
#include <atomic>

std::atomic<long> anAtomicLong;

int main()
{
  anAtomicLong.store(10);

  std::cout << "Value:               " << anAtomicLong.load() << std::endl;
  anAtomicLong.fetch_add(10);
  std::cout << "Value:               " << anAtomicLong.load() << std::endl;

  std::cout << "is_lock_free:        " << anAtomicLong.is_lock_free() << std::endl;
  std::cout << "is always lock free: " << ( std::atomic<long>::is_always_lock_free ? "YES" : "NO" ) << std::endl;
  return 0;
}


// is_lock_free: evaluate to 0 => if the atomic type is never lock-free
//                           1 => if the lock-free status of the corresponding atomic type is a runtime property as described previously.
//                           2 => if the atomic type is always lock-free


// The only type that doesn’t provide an is_lock_free() member function is
// std::atomic_flag. This type is a simple Boolean flag, and operations on this type are
// required to be lock-free; once you have a simple lock-free Boolean flag, you can use that
// to implement a simple lock and implement all the other atomic types using that as a
// basis. When I said simple, I meant it: objects of the std::atomic_flag type are initialized
// to clear, and they can then either be queried and set (with the test_and_set()
// member function) or cleared (with the clear() member function). That’s it: no
// assignment, no copy construction, no test and clear, no other operations at all.


// #include <iostream>       // std::cout
// #include <atomic>         // std::atomic, std::memory_order_relaxed
// #include <thread>         // std::thread

// std::atomic_int foo (0);

// void set_foo(int x) {
//   foo.store(x,std::memory_order_relaxed);     // set value atomically
// }

// void print_foo() {
//   int x;
//   do {
//     x = foo.load(std::memory_order_relaxed);  // get value atomically
//   } while (x==0);
//   std::cout << "foo: " << x << '\n';
// }

// int main ()
// {
//   std::thread first (print_foo);
//   std::thread second (set_foo,10);
//   first.join();
//   //second.join();
//   return 0;
// }
// //output: foo: 10
