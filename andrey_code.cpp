#include<iostream>
using namespace std;

class Granny {
private:
	double ladder_height;
public:
	double bring_ladder() {
		return ladder_height;
	}
};

class Lamp {
public:
	double height;
	Lamp(double height) {
		this->height = height;
	}
};

class Electrician {
private:
	double height;
public:	
	bool fix(Lamp& lamp) {
		if (height >= lamp.height) {			
			return true;
		} else {
			return false;
		}
	}
	bool fix(Lamp& lamp, double ladder_height) {
		if (height + ladder_height >= lamp.height) {			
			return true;
		} else {			
			return false;
		}
	}
	Electrician(double height) {
		this->height = height;
	}
};


int main() {
	setlocale(LC_ALL, "RUS");
	Lamp lamp(11.1);
	Granny granny;
	Electrician electrician(1.8);
	if (electrician.fix(lamp)) {
		cout << "Лампочка починена. " << endl;
	} else {
		cout << "Не хватает роста. " << endl;
		cout << "Бабушка приносит лестницу. " << endl;
		double ladder_height = granny.bring_ladder();
		if (electrician.fix(lamp, ladder_height)) {
			cout << "Лампочка починена. " << endl;
		} else {
			cout << "Все еще не хватает роста. " << endl;
		}
	}

	return 0;
}