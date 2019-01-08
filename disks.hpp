///////////////////////////////////////////////////////////////////////////////
// disks.hpp
//
// Definitions for two algorithms that each solve the alternating disks
// problem.
//
// As provided, this header has four functions marked with TODO comments.
// You need to write in your own implementation of these functions.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <sstream>
#include <string>
#include <vector>

// State of one disk, either light or dark.
enum disk_color { DISK_LIGHT, DISK_DARK };

// Data structure for the state of one row of disks.
class disk_state {
private:
  std::vector<disk_color> _colors;

public:

  disk_state(size_t light_count)
    : _colors(light_count * 2, DISK_LIGHT) {

      assert(light_count > 0);

      for (size_t i = 0; i < _colors.size(); i += 2) {
        _colors[i] = DISK_DARK;
      }
  }

  // Equality operator for unit tests.
  bool operator== (const disk_state& rhs) const {
    return std::equal(_colors.begin(), _colors.end(), rhs._colors.begin());
  }

  size_t total_count() const {
    return _colors.size();
  }

  size_t light_count() const {
    return total_count() / 2;
  }

  size_t dark_count() const {
    return light_count();
  }

  bool is_index(size_t i) const {
    return (i < total_count());
  }

  disk_color get(size_t index) const {
    assert(is_index(index));
    return _colors[index];
  }

  void swap(size_t left_index) {
    assert(is_index(left_index));
    auto right_index = left_index + 1;
    assert(is_index(right_index));
    std::swap(_colors[left_index], _colors[right_index]);
  }

  std::string to_string() const {
    std::stringstream ss;
    bool first = true;
    for (auto color : _colors) {
      if (!first) {
        ss << " ";
      }

      if (color == DISK_LIGHT) {
        ss << "L";
      } else {
        ss << "D";
      }

      first = false;
    }
    return ss.str();
  }

  // Return true when this disk_state is in alternating format. That means
  // that the first disk at index 0 is dark, the second disk at index 1
  // is light, and so on for the entire row of disks.
  bool is_alternating() const {
    if(_colors[0]==DISK_DARK){
		  for (size_t i = 0; i < _colors.size(); i++){
			  if (_colors[i]!=_colors[_colors.size()-1-i]){
				  return true;
			  }
		  }
	 }
    return false;
  }

  // Return true when this disk_state is fully sorted, with all light disks
  // on the left (low indices) and all dark disks on the right (high
  // indices).
  bool is_sorted() const {
   	  if (_colors[0] == DISK_LIGHT){
		  //check first halft
		  for (size_t i = 0; i < _colors.size() / 2; i++){
			  if (_colors[i] == DISK_DARK){
				  return false;
			  }
		  }
		  //check second halft
		  for (size_t i = _colors.size() / 2; i < _colors.size() / 2; i++){
			  if (_colors[i] == DISK_LIGHT){
				  return false;
			  }
		  }
	  }

	  else
		  return false;
    return true;
  }
};

// Data structure for the output of the alternating disks problem. That
// includes both the final disk_state, as well as a count of the number
// of swaps performed.
class sorted_disks {
private:
  disk_state _after;
  unsigned _swap_count;

public:

  sorted_disks(const disk_state& after, unsigned swap_count)
    : _after(after), _swap_count(swap_count) { }

  sorted_disks(disk_state&& after, unsigned swap_count)
    : _after(after), _swap_count(swap_count) { }

  const disk_state& after() const {
    return _after;
  }

  unsigned swap_count() const {
    return _swap_count;
  }
};

// Algorithm that sorts disks using the left-to-right algorithm.
sorted_disks sort_left_to_right(const disk_state& before) {
  
	auto sorted(before);
	int numSwap = 0;//number of swap time

	if ((!before.is_sorted()) && (before.is_alternating())){
		//keep swapping if it is not sorted yet.
		while (!sorted.is_sorted()){
			for (size_t i = 0; i < before.total_count() - 1; i++){
				//if the one before and the one after it is like DL then we swap. if not keep going.
				if ((sorted.get(i) == DISK_DARK) && (sorted.get(i + 1) == DISK_LIGHT)){
					sorted.swap(i);
					numSwap++;
				}
			}
		}
	}
  return sorted_disks(sorted, numSwap);
}

// Algorithm that sorts disks using the lawnmower algorithm.
sorted_disks sort_lawnmower(const disk_state& before) {
  
	auto sorted(before);
	int numSwap = 0;//number of swap time

	if ((!before.is_sorted()) && (before.is_alternating())){
		//keep swapping if it is sorted yet.
		while (!sorted.is_sorted()){
			size_t i = 0;
			for (; i < before.total_count() - 1; i++){
				//if the one before and the one after it is like DL then we swap. 
				if ((sorted.get(i) == DISK_DARK) && (sorted.get(i + 1) == DISK_LIGHT)){
					sorted.swap(i);
					numSwap++;
				}
			}
			//start from the disk before the rightmost disk to the left
			for (size_t j = i-1 ; j > before.total_count() -i - 1; j--){
				//if the one before and the one after it is like DL then we swap. if not keep going.
				if ((sorted.get(j) == DISK_DARK) && (sorted.get(j + 1) == DISK_LIGHT)){
					sorted.swap(j);
					numSwap++;
				}
			}
		}
		
	}
  return sorted_disks(sorted, numSwap);
}
