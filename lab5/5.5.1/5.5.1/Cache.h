#pragma once
#include <vector>
using namespace std;

template<typename T>
class Cache {
protected:
	vector<T> v;
public:

	Cache() {};

	~Cache() {};

	void put(T elem) {
		v.push_back(elem);
	};

	void operator+=(T elem)
	{
		put(elem);
	}

	bool contains(T elem) { 
		for (T e : v)
			if (e == elem)
				return true;
		return false;
	};
};

template<>
class Cache<string> {
	vector<string> v;
public:

	Cache() {};

	~Cache() {};

	void put(string elem) {
		v.push_back(elem);
	}

	void operator+=(string elem)
	{
		put(elem);
	}

	void add(string elem) {
		if (v.size() < 100) {
			put(elem);
		}
		else {
			throw exception("Превышен лимит!");
		}
	}

	bool contains(string elem) {
		for (string e : v)
			if (e[0] == elem[0])
				return true;
		return false;
	}
};




