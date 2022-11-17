
class Employee {
private:
	int age;
	int id;
	float salary;
public:
	Employee() {
		age = 0;
		id = 0;
		salary = 0;
	}
	void setAge(int x) {
		age = x;
	}
	void setId(int x) {
		id = x;
	}
	void setSalary(float x) {
		salary = x;
	}
	int getAge();
	int getId();
	float getSalary();
};

int Employee::getAge() {
	return age;
}
int Employee::getId() {
	return id;
}
float Employee::getSalary() {
	return salary;
}
