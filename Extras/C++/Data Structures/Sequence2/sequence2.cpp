#include "sequence2.h"
#include <cassert>

using namespace Lab_4;

sequence::sequence(size_type entry) {
	data = new value_type[entry];
	used = 0;
	capacity = entry;
	current_index = 0;
}

sequence::sequence(const sequence& entry) {
	used = entry.used;
	capacity = entry.capacity;
	current_index = entry.current_index;

	data = new value_type[capacity];
	for (int i = 0; i < used; i++)
		data[i] = entry.data[i];
}

void sequence::start() {
	current_index = 0;
}

void sequence::advance() {
		current_index++;
}

void sequence::insert(const value_type& entry) {
	if (used >= capacity)
		resize(size_t(capacity * 1.1));
	if (is_item()) {
		for (int i = used; i > current_index; i--)
			data[i] = data[i - 1];
	}
	else {
		current_index = 0;
		for (int i = used; i > 0; i--)
			data[i] = data[i - 1];
	}

	data[current_index] = entry;
	used++;
}

void sequence::attach(const value_type& entry) {
	if (used >= capacity)
		resize(size_t(capacity * 1.1));
	if (is_item()) {
		current_index++;
		for (int i = used; i > current_index; i--)
			data[i] = data[i - 1];
	}
	else {
		current_index = used;
	}
	data[current_index] = entry;
	used++;
}

void sequence::remove_current() {
	assert(is_item());
	for (int i = current_index; i < used - 1; i++)
		data[i] = data[i + 1];
	used--;
}

void sequence::resize(size_type new_capacity) {
	if (new_capacity > used) {
		value_type *temp = new value_type[new_capacity];
		for (int i = 0; i < used; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		capacity = new_capacity;
	}
}

void sequence::operator =(const sequence&copy) {
	resize(copy.capacity);
	used = copy.used;
	current_index = copy.current_index;
	for (int i = 0; i < used; i++)
		data[i] = copy.data[i];
}

sequence::size_type sequence::size() const {
	return used;
}

bool sequence::is_item() const {
	return (used > current_index);
}

sequence::value_type sequence::current() const {
	assert(is_item());
	return data[current_index];
}

sequence::~sequence() {
	delete[] data;
}