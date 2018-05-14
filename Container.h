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

	Container(unsigned int capacity = 0, unsigned int size = 0, T * elements = NULL) {
		this->capacity = 0;
		this->size = 0;
		this->elements =NULL;
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
		if (size == capacity || capacity == 0) resizeUp();
		elements[size] = el;
		++size;
	}

	const Container & operator=(const Container & c) {
		this->capacity = c.getCapacity();
		this->size = c.getSize();
		if (this->capacity > 0) {
			this->elements = new T[capacity];
			for (unsigned int i = 0; i < c.getSize(); i++) add(c[i]);
		}
		else this->elements = NULL;
	}

	T & operator[](unsigned int idx) {
		return elements[idx];
	}

};

#endif CONTAINER_H