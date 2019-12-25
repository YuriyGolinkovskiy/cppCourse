#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class DataManager {
protected:
	T array[64];
	int N;
public:

	DataManager() {
		N = 0;
	};

	~DataManager() {};

	void push(T elem) {
		if (N < 64) {
			T arr[64];
			N++;
			arr[0] = elem;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < 64; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			N = 1;
			array[0] = elem;
		}
	};

	void push(T elems[], int n) {
		T arr[64];
		T temp;
		for (int i = 0; i < n; i++) {
			arr[i] = elems[i];
		}
		for (size_t i = 0; i < n - 1; i++)
		{
			for (size_t j = 0; j < n - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		if (N+n <= 64) {			
				
			N += n;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < N; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			if (n > 64)
				N = 64;
			else {
				N = n;
				for (int i = 0; i < N; i++) {
					array[i] = arr[i];
				}
			}
		}
	};

	T peek() { 
		if (N < 2)
			return 0;
		else
			return array[N-2];		
	};

	T pop() { 
		if (N != 0) {
			N--;
			return array[N];
		}
	};

	void print() {
		for (int i = 0; i < N; i++) {
			cout << array[i] <<" ";
		}
		cout << endl ;
	};
};

template<>
class DataManager<char> {
protected:
	char array[64];
	int N;
public:
	DataManager() {
		N = 0;
	};
	~DataManager() {};
	void push(char elem) {
		if (elem == '!' || elem == '?' || elem == '/' || elem == '.' || elem == ',' || elem == ' ' || elem == '-')
			elem = '_';
		if (N < 64) {
			char arr[64];			
			N++;
			arr[0] = elem;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < 64; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			N = 1;
			array[0] = elem;
		}
	};
	void push(char elems[], int n) {
		for (int i = 0; i < n; i++) {
			if (elems[i] == '!' || elems[i] == '?' || elems[i] == '/' || elems[i] == '.' || elems[i] == ',' || elems[i] == ' ' || elems[i] == '-')
				elems[i] = '_';
		}
		if (N + n <= 64) {
			char arr[64];
			for (int i = 0; i < n; i++) {
				arr[i] = elems[i];
			}
			N += n;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < N; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			if (n > 64)
				N = 64;
			else {
				N = n;
				for (int i = 0; i < N; i++) {
					array[i] = elems[i];
				}
			}
		}
	};
	char peek() {
		if (N < 2)
			return 0;
		else
			return array[1];
	};
	char pop() {
		if (N != 0) {
			N--;
			return array[N];
		}
	};
	char popUpper() {
		if (N != 0 && ((('a' <= array[N-1]) && (array[N-1] >= 'z'))||(('à' <= array[N-1]) && (array[N-1] >= 'ÿ')))) {
			N--;
			return toupper(array[N]);
		}
	};
	char popLower() {
		if (N != 0 && ((('A' <= array[N-1]) && (array[N-1] >= 'Z'))||(('À' <= array[N-1]) && (array[N-1] >= 'ß')))) {
			N--;
			return tolower(array[N]);
		}
	};
	void print() {
		for (int i = 0; i < N; i++) {
			cout << array[i] ;
		}
		cout << endl;
	};
};