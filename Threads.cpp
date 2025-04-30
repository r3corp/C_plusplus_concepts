#include <thread>
//#include <jthread>
#include <vector>
#include <algorithm>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <iostream>


void test_tbb() {
  const int size = 100;
  std::vector<int> data(size, 1);

  tbb::parallel_for(tbb::blocked_range<size_t>(0, data.size()),
    [&data](const tbb::blocked_range<size_t>& range) {
      for (size_t i = range.begin(); i < range.end(); ++i) {
        data[i] *= 2; // Example operation
      }
    });

  // Print the result
  for (const auto& val : data) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

void run_on_all_cores() {
  unsigned int num_cores = std::thread::hardware_concurrency();
  if (num_cores == 0) {
    std::cerr << "Unable to detect the number of cores." << std::endl;
    return;
  }

  std::vector<std::thread> threads;
  threads.reserve(num_cores);

  for (unsigned int i = 0; i < num_cores; ++i) {
    threads.emplace_back([i] {
      std::cout << "Core " << i << " is running a computation." << std::endl;
      // Example computation
      long long sum = 0;
      for (long long j = 0; j < 1'000'000; ++j) {
        sum += j;
      }
      std::cout << "Core " << i << " finished computation with result: " << sum << std::endl;
    });
  }

  for (auto& thread : threads) {
    thread.join();
  }
}
int main() {
  test_tbb();

  std::thread thread_example([] {
    for (int i = 0; i < 10; ++i) {
      std::cout << "Thread running: " << i << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  thread_example.join();

  std::jthread jthread_example([] {
    for (int i = 0; i < 10; ++i) {
      std::cout << "jthread running: " << i << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  run_on_all_cores();

}