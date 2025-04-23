#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <utility>
#include <memory>

//###cppcon "conquering c++ 20 ranges"

//configure fibonacci forward iterator
struct fib_iterator{
  using value_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  const std::size_t& operator*() const { return curr_; }

  fib_iterator& operator++() {
      //exchange comes from utility
      curr_ = std::exchange(next_, curr_ + next_); 
      return *this;
  }

  fib_iterator operator++(int) {
      auto temp = *this;
      ++*this;
      return temp;
  }

  bool operator==(const fib_iterator&) const = default;

  private:
  std::size_t curr_ = 0;
  std::size_t next_ = 1;
};

namespace rng = std::ranges;
namespace views {
  // say that the sequence is limitless...unreachable_sentinel_t
  rng::subrange<fib_iterator, std::unreachable_sentinel_t> fibonacci; 
}

void fibfun(int n, int k){
  auto view =  views::fibonacci
              | std::views::filter([k](auto i) {return i%k ==0;})
              | std::views::take(n);
  rng::copy(view, std::ostream_iterator<std::size_t>(std::cout, ", "));
}


//###cppcon "conquering c++ 20 ranges"

template<typename V, typename Pred>
    //constraints on the predicate values
    requires std::ranges::bidirectional_range<V> &&
             std::indirect_unary_predicate<Pred, std::ranges::iterator_t<V>>
class drop_last_while_view 
    : public std::ranges::view_interface<drop_last_while_view<V, Pred>> {
        V base_;
        Pred pred_;
        std::optional<std::ranges::iterator_t<V>> cached_end_;
    public:
        drop_last_while_view() = default;

        drop_last_while_view(V base, Pred pred)
            : base_(std::move(base)),
              pred_(std::move(pred)) {
            
        }

        auto begin() {
            return std::ranges::begin(base_);
        }

        auto end() {
            if (!cached_end_){
                //return std::ranges::find_if_not(std::ranges::rbegin(base_), std::ranges::rend(base_), pred_).base();
                //alternative
                auto view = std::views::reverse(base_);
                cached_end_ = std::ranges::find_if_not(view, pred_).base();
            }
            return *cached_end_;

        }

};

struct drop_last_while_fn {
    template <std::ranges::viewable_range R, typename Pred>
    constexpr auto operator() (R&& r, Pred pred) const
        ->drop_last_while_view<std::views::all_t<R>, Pred>
    {
            return drop_last_while_view<std::views::all_t<R>, Pred>(
                    std::views::all(std::forward<R>(r)), std::move(pred));
    }
};

//inline constexpr auto drop_last_white = drop_last_white_fn{};

//inline constexpr auto trimfront = std::views::drop_white(::isspace);

//inline constexpr auto trimfront = std::views::drop_last_white(::isspace);


int main() {
  // Sample data
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Filter: Keep only even numbers
  auto even_numbers = numbers | std::ranges::views::filter([](int n) { return n % 2 == 0; });

  // Transform: Square the numbers
  auto squared_numbers = even_numbers | std::ranges::views::transform([](int n) { return n * n; });

  // Output the results
  std::cout << "Squared even numbers: ";
  for (int n : squared_numbers) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  // Combine filter and transform in a single pipeline
  auto combined_view = numbers 
    | std::ranges::views::filter([](int n) { return n % 2 != 0; }) // Odd numbers
    | std::ranges::views::transform([](int n) { return n * 3; });  // Multiply by 3

  std::cout << "Odd numbers multiplied by 3: ";
  for (int n : combined_view) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  // Sorting using ranges
  std::vector<int> unsorted = {5, 3, 8, 1, 4};
  std::ranges::sort(unsorted);

  std::cout << "Sorted numbers: ";
  for (int n : unsorted) {
    std::cout << n << " ";
  }
  std::cout << std::endl;

  fibfun(100,3);

  return 0;
}

