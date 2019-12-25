#pragma once
#include <string>
#include <fstream>

using namespace std;
class Phone
{
public:
	Phone();
	Phone(string _model, string _myNumber, string _lastNumber, double _balance);
	~Phone();
	void serialize();
	void deserialize();
	void serialize(const string& filename);
	void deserialize(const string& filename);
	void info() const;
	friend std::ostream& operator<< (std::ostream &out, const Phone &phone);
	void call(string number, double minutes);
	string getModel() const;
	void setModel(string _model);
	string getMyNumber() const;
	void setMyNumber(string _myNumber);
	string getLastNumber() const;
	void setLastNumber(string _lastNumber);
	double getBalance() const;
	void setBalance(double _balance);
private:
	string model;
	string myNumber;
	string lastNumber;
	double balance;
};

