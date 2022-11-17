
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
using namespace std;


int main() {
	Car car;
	car.setPrice(10);
	car.setAge(5);
	car.setRaceCarStatus(true);
	
	Vehicle vehicle;
	vehicle.setPrice(20);
	vehicle.setAge(10);

	Truck truck;
	truck.setPrice(1500);
	truck.setAge(20);
	truck.setDieselTypeStatus(true);

	cout << "Vehicle Price: " << vehicle.getPrice() << "  Vehicle Age: " << vehicle.getAge() << endl;
	
	cout << "Car Price: " << car.getPrice() << "  Car Age: " << car.getAge() << "   Race Car Status: " << car.getRaceCarStatus() << endl;

	cout << "Truck Price: " << truck.getPrice() << "  Truck Age: " << truck.getAge() << "   Truck Diesel Status: " << truck.getDieselTypeStatus() << endl;

	return 0;
}
