#include <iostream>
#include <memory>
#include <boost/align.hpp>
#include <chrono>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include <sys/resource.h>

long getMemoryUsage() {
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    return r_usage.ru_maxrss; 
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::vector<boost::multiprecision::int1024_t> vec;
    for(int i = 0; i < 10000; i++){
        boost::multiprecision::int1024_t Op("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
        vec.push_back(Op);
    }
    for(std::size_t t = 0; t < vec.size(); t++){
        std::cout << boost::lexical_cast<std::string>(vec[t]) << std::endl;
    }
    
//
    //std::cout<< "time: " <<  el << "\nMemory:" << getMemoryUsage() << std::endl;   

    //std::vector<boost::multiprecision::int512_t, boost::alignment::aligned_allocator<boost::multiprecision::int1024_t>> vec;
    //for(int i =0; i < 10000; i++){
    //    boost::multiprecision::int512_t Op = 98765432109876543210;
    //    vec.push_back(Op);
    //}
    //for(std::size_t t = 0; t < vec.size(); t++){
    //    std::cout << vec[t] << std::endl;
    //}
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> el = end - start;

    std::cout<< "time: " <<  el.count() << "\nMemory:" << getMemoryUsage() << std::endl;


}