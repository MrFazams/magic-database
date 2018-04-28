#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container
{

	int size;
	int capacity;
	T * elements;

	void resizeUp() {
		T * temp = elements;
		elements = new T[2 * capacity];
		for (int i = 0; i < size; i++) {
			elements[i] = temp[i];
		}
		capacity *= 2;
		delete[] temp;
	}

public:

	Container(int capacity = 1, int size = 0, T * elements = NULL) {
		this->capacity = capacity;
		if (size > capacity) this->size = capacity;
		else this->size = size;
		if (elements != NULL && capacity != 0) for (int i = 0; i < size; i++) add(elements[i]);
	}

	Container(const Container & c) {
		*this = c;
	}
	~Container();

	int getSize() const {
		return size;
	}

	int getCapacity() const {
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
		if (c.getSize() > 0) for (int i = 0; i < c.getSize(); i++) add(c[i]);
	}

	T & operator[](unsigned int idx) {
		return elements[idx];
	}

};

#endif CONTAINER_H