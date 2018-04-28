#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container
{

	unsigned int size;
	unsigned int capacity;
	T * elements;

	void resizeUp() {
		if (capacity == 0) {
			++capacity;
			this->elements = new T[1];
		}
		else {
			T * temp = elements;
			elements = new T[2 * capacity];
			for (unsigned int i = 0; i < size; i++) {
				elements[i] = temp[i];
			}
			capacity *= 2;
			delete[] temp;
		}
	}

public:

	Container(unsigned int capacity = 1, unsigned int size = 0, T * elements = NULL) {
		this->capacity = capacity;
		if (size > capacity) this->size = capacity;
		else this->size = size;
		if (elements != NULL && capacity > 0) for (unsigned int i = 0; i < size; i++) add(elements[i]);
		else this->elements = NULL;
	}

	Container(const Container & c) {
		*this = c;
	}

	~Container() {
		delete[] elements;
	}

	unsigned int getSize() const {
		return size;
	}

	unsigned int getCapacity() const {
		return capacity;
	}

	void add(T& el) {
		if (size == capacity) resizeUp();
		elements[size] = el;
		++size;
	}

	const Capacity & operator=(const Capacity & c) {
		this->capacity = c.getCapacity();
		this->size = c.getSize();
		if (c.getSize() > 0) for (unsigned int i = 0; i < c.getSize(); i++) add(c[i]);
		else this->elements = NULL;
	}

	T & operator[](unsigned int idx) {
		return elements[idx];
	}

};

#endif CONTAINER_H