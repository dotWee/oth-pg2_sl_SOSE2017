#include <thread>
#include <iostream>
#include <mutex>

#define NUM 10000

using namespace std;

int value = 0;
mutex Mu1;

void increase() {
    for (int i = 0; i < NUM; i++) {
        {
            lock_guard<mutex> lock1(Mu1);
            value++;
        }
    }
    //cout << "increased to " <<(ptr) << endl;
}

void decrease() {
    for (int x = 0; x < NUM; x++) {
        {
            lock_guard<mutex> lock1(Mu1);            
            value--;
        }
    }
    //cout << "decreased to " <<(ptr) << endl;
}

int main() {

    // TODO: thread 1 => value += 1;
    thread t1 {increase};

    //       thread 2 => value -= 1;
    thread t2 {decrease};

    // pauses until t1 finishes
    t1.join();       

    // pauses until t2 finishes
    t2.join();

    cout << "END-LOCK_GUARD of main value = " << value << endl;    
    return 0;
}