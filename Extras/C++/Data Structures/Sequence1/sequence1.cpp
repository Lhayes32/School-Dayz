#include "sequence1.h"
#include <cassert>

namespace main_savitch_3
{
	sequence::sequence(){
		used = 0;
	}

	void sequence::start(){
		current_index = 0;
	}

	void sequence::advance(){
		if (is_item())
			++current_index;
	}

	void sequence::insert(const value_type& entry){
		assert(size() < CAPACITY);
		
		//If there is no item, current index is 0
		if (!is_item()) current_index = 0;	
		
		//The old data is moved up and the entry is placed in the sequence
		for (size_type i = used; i > current_index; --i)
			data[i] = data[i - 1];
		data[current_index] = entry;
		++used;
	}

	void sequence::attach(const value_type& entry){
		assert(size() < CAPACITY);

		//When there is no item, the current index becomes one less the amount used
		//and regardless the index will be incremented.
		if (!is_item()) current_index = used - 1;
		++current_index;

		//Every entry is moved up, leaving space at the end to attach a new entry
		for (size_type i = used; i > current_index; --i)
			data[i] = data[i - 1];
		data[current_index] = entry;
		++used;
	}

	void sequence::remove_current(){
		
		//If there is an item, move all items after the current index forward
		//clearing out the first. Reduce the amount used.
		if (is_item()) {
			for (size_type i = current_index; i < used; i++)
				data[i] = data[i + 1];
			--used;
		}

		
	}

	sequence::size_type sequence::size() const {
		return used;
	}

	bool sequence::is_item() const{
		return (current_index >= 0 && current_index < used);
	}

	sequence::value_type sequence::current() const {
		if(is_item())
			return data[current_index];
	}
}