
#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;  // Heap data stored in a vector
  int m_;                // Ary-ness of the heap
  PComparator comp_;      // Comparator object

  // Helper functions
  void trickleUp(size_t index);
  void trickleDown(size_t index);

};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// Push an item into the heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  data_.push_back(item);
  trickleUp(data_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  return data_[0];
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    throw std::underflow_error("Heap is empty");
    // ================================
  }
  std::swap(data_[0], data_.back());
  data_.pop_back();
  trickleDown(0);
}

// Check if the heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

// Return the size of the heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}

// Trickle up to maintain heap property
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t index)
{
  while (index > 0) {
    size_t parent = (index - 1) / m_;
    if (comp_(data_[index], data_[parent])) {
      std::swap(data_[index], data_[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

// Trickle down to maintain heap property
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t index)
{
  while (true) {
    size_t priorityChild = index;
    for (size_t i = 1; i <= m_; ++i) {
      size_t child = m_ * index + i;
      if (child < data_.size() && comp_(data_[child], data_[priorityChild])) {
        priorityChild = child;
      }
    }
    if (priorityChild != index) {
      std::swap(data_[index], data_[priorityChild]);
      index = priorityChild;
    } else {
      break;
    }
  }
}


#endif
