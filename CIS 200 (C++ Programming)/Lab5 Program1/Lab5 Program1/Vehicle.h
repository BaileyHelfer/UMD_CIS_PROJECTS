#ifndef Vehicle_HEADER
#define Vehicle_HEADER

class Vehicle {
private:
	int age;
	float price;
public:
	Vehicle() {
		age = 0;
		price = 0;
	}
	void setAge(int a) {
		age = a;
	}
	void setPrice(float p) {
		price = p;
	}
	int getAge() { return age; }
	float getPrice() { return price; }
};

#endif