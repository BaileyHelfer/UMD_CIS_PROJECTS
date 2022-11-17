#include "Vehicle.h"

class Truck : public Vehicle {
private:
	bool dieselTypeStatus;
public:
	Truck() {
		dieselTypeStatus = false;
	}
	void setDieselTypeStatus(bool x) {
		dieselTypeStatus = x;
	}
	bool getDieselTypeStatus() { return dieselTypeStatus; }
};
