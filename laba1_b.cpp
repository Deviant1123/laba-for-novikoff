#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Car {
public:
	Car(const std::string& model) : model_(model) {}
	virtual ~Car() {}
	virtual std::string getBrand() const = 0;
	std::string getModel() const {
		return model_;
	}
private:
	const std::string model_;
};

class Mercedes : public Car {
public:
	Mercedes(const std::string& model) : Car(model) {}
	virtual ~Mercedes() {
		std::cout << "Mercedes " << getModel() << std::endl;
	}
	std::string getBrand() const {
		return "Mercedes";
	}
};

class Audi : public Car {
public:
	Audi(const std::string& model) : Car(model) {}
	virtual ~Audi() {
		std::cout << "Audi " << getModel() << std::endl;
	}
	std::string getBrand() const {
		return "Audi";
	}
};

class BMW : public Car {
public:
	BMW(const std::string& model) : Car(model) {}
	virtual ~BMW() {
		std::cout << "BMW " << getModel() << std::endl;
	}
	std::string getBrand() const {
		return "BMW";
	}
};

int main() {
	std::vector<Car*> cars;
	std::ifstream file("cars.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	std::string brand, model;
	while (file >> brand >> model) {
		if (brand == "Mercedes") {
			cars.push_back(new Mercedes(model));
		}
		else if (brand == "Audi") {
			cars.push_back(new Audi(model));
		}
		else if (brand == "BMW") {
			cars.push_back(new BMW(model));
		}
	}
	file.close();
	for (Car* car:cars) {
		car->getBrand();
		delete car;
	}
	return 0;
}