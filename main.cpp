#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex my_mutex ;

void thread_function(int num_to_increment, const char * some_str)
{
    for(int i = 0 ; i < 100000 ; i++)
    {
        my_mutex.lock() ;
        printf("Something is going on thread 1 ... %d, %s \n",i,some_str);
        num_to_increment++ ;
        printf("Num is: %d \n",num_to_increment);
        my_mutex.unlock() ;
    }
}

void second_thread_function(int num_to_increment, const char * some_str)
{
    for(int i = 0 ; i < 100000 ; i++)
    {
        my_mutex.lock() ;
        printf("Something is going on thread 2 ... %d,%s \n",i,some_str);
        num_to_increment++ ;
        printf("Num is: %d \n",num_to_increment);
        my_mutex.unlock() ;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int some_num = 55 ;
    std::thread my_thread(thread_function, some_num,"hello") ;
    std::thread second_thread(second_thread_function, some_num, "hello");
    my_thread.join() ;
    second_thread.join() ;
    return 0;
}
