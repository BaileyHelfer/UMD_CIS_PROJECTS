#include "Vehicle.h"

class Car : public Vehicle {
private:
	bool raceCarStatus;
public:
	Car() {
		raceCarStatus = false;
	}
	void setRaceCarStatus(bool x) {
		raceCarStatus = x;
	}
	bool getRaceCarStatus() { return raceCarStatus; }

};
