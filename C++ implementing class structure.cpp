//Serkan Koçoðlu 17070006004 ,Best Regards..
#include <iostream>
#include <string>
using namespace std;
#define N 3
class employee {
	public:
		employee() {
			name = "empty";
		}
		
		employee(string n, double s) {
			name = n;
			salary = s;
		}
		
		double getSalary(){
			return salary;
		}
		
		void setName(string name){
			name=name;
		}
		
		void setSalary(double s){
			salary = s;
		}
		
	private:
		string name;
		double salary{0};
};

int main()
{
	employee e1, e2;
	employee e3{"myname", 5000};
	
	e1.setSalary(4000);
	e2.setSalary(3000);
	e3.setName("seko");
		
		
	employee employees[N] = {e1, e2, e3};
	int counter = 1;  //Current employee no


	for(auto e : employees)
	{
		cout << "Employee-" << counter << ": " << e.getSalary() << "\n";
		counter++;
	}


	//Find the maximum salary in the employees array:
	int RichyRich=0;	
	for (auto e : employees){
		if(e.getSalary()>RichyRich)
	RichyRich=e.getSalary();
	}
	
	cout <<"Biggest Salary is :" << RichyRich ;

	
	return 0;
}
