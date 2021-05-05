#include <iostream>                                                      /* C++ iostream            C++11    */
#include <thread>                                                        /* threads                 C++11    */
#include <string>                                                        /* C++ strings             C++11    */
#include <mutex>                                                         /* Mutexes                 C++11    */

std::mutex stdout_mutex;

class oneShotMethod {
  private:
    static void callMeOnlyOnce(int message) {
      std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
      std::cout << "CALL WITH: " << message << std::endl;
    }
  public:
    static void aFuncOneShotFunc(int message) {
      static std::once_flag daOnceFlag;
      { std::lock_guard<std::mutex> stdout_guard(stdout_mutex);
        std::cout << "TRY CALL WITH: " << message << std::endl;
      }
      std::call_once(daOnceFlag, callMeOnlyOnce, message);
    }
};

int main() {
    std::thread t1(oneShotMethod::aFuncOneShotFunc, 1);
    std::thread t2(oneShotMethod::aFuncOneShotFunc, 2);
    std::thread t3(oneShotMethod::aFuncOneShotFunc, 3);
    std::thread t4(oneShotMethod::aFuncOneShotFunc, 4);
 
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
