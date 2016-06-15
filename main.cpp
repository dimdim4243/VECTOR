#include <iostream>
#include <Windows.h>


using namespace std;

template <typename T> 
class Vector{
	T * array;
	size_t _size;
	size_t _capacity;
public:
	typedef T* iterator;

	Vector():_size(0), _capacity(0), array(0){}
	
	Vector(const Vector<T>& V){
		*this = V;
	}

    Vector(const size_t n):Vector(n, T()) { }
    Vector(size_t n, const T &a):_size(n), _capacity(n){}


	~Vector(){
		delete (array);
	}

	iterator begin();
    iterator end();

	size_t size(){return _size;}
	size_t capacity(){return _capacity;}

	T &operator[](size_t i){
		return _data[i];
	}

	void push_back(const T &value){
		array[_size++] = value;
		return *this;
	}
    void pop_back(){
		(array + --_size)->~T();
		return *this;
	}

	bool empty(){
		return _size == 0;
	}

	void clear(){
		while (!empty()){
			pop_back();
		}
	}
};

int main(){

}