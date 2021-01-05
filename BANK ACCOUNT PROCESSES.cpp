#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <time.h>
using namespace std; 
stack <string>S;
queue <string>Q;

class Customers {
private:
string name;
string surname;
string ID;
	
public:	
    void setname(string n) {
     name = n;
    }
    void setsurname(string s) {
      surname = s;
    }
    void setID(string id) {
      ID = id;
    }
    string getname() {
      return name;
    }
     string   getsurname() {
      return surname;
    }
    string getID() {
      return ID;
    }
};

	
void customers_process()
{
	string name,surname,ID;
	Customers c;
	if(Q.empty()){
		
	cout << "Enter your name:";
	cin >> name ;
	cout << "Enter your surname:";
	cin >> surname;
	cout << "Enter your ID:";
	cin >> ID;
	
	c.setname(name);
	c.setsurname(surname);
	c.setID(ID);
	
	Q.push(c.getname());
	Q.push(c.getsurname());
	Q.push(c.getID());
	}
}

void initialize_QS(){
while (!S.empty()){
	S.pop();}
	
	while(!Q.empty()){
		Q.pop();}
		
	cout << "Process Cancelled";
}

void zero_process()
{
	cout << "Customer Name: "<<Q.front() << endl;    //name ,surname , ID
	Q.pop();                        
    cout << "Customer Surname: " << Q.front() << endl;
    Q.pop();
    cout << "Customer ID: "  <<Q.front() << endl;
    Q.pop();
	cout << "Account Movements\n";
	
	while (!S.empty()){
cout << S.top() << endl;     
	S.pop();	}
}

void first_process()
{	
	string amount;
	cout<< "Enter amount of withdrawal\n";
	cout << "->";
	cin >> amount;
	
	time_t now = time(0);
	char* dt=ctime(&now);   //casting
	string time =dt;
	
	S.push( "The customer withdraws "+amount+" dollars from account--"+time);
}

void second_process(){
		string deposit;
	cout<< "Enter amount of deposit\n";
	cout << "->";
	cin >> deposit;
	
		time_t now = time(0);
	char* dt=ctime(&now);   
	string time =dt;

	S.push(" The customer deposits "+deposit+" dollars to account--"+time );
}


void third_process(){
	string lended_money;	
	
	cout << "Enter the amount of money to receive credit \n";
	cout << "->";
	cin >> lended_money;
	
	time_t now = time(0);
	char* dt=ctime(&now);   
	string time =dt;
	
		S.push("The customer lends "+ lended_money+"--"+time );
}

void Menu(int PeopleInOrder){
int i=0;
bool next=true;
	for(i=0;i<PeopleInOrder;i++)
	{
		next =true;
		while(next==true){
		cout << "Which process you want to do ?\n";
	cout << "1:Withdraw Money \n";
	cout << "2:Deposit Money\n";
	cout << "3:Lend Money at Interest\n";
	cout << "4:Finish the Process & Take Your Bill\n";//continues next turn
	cout << "0:Cancel Your Process\n"; //continues next turn without bill

	int operation=0;
	cout << "->";
    cin >> operation;

switch (operation){
case 1: 
customers_process();
first_process();
break;

case 2:
	customers_process();
second_process();	
break;

case 3:
	customers_process();
third_process();	
break;

case 4:
	if(!S.empty()){
	zero_process();
	}
cout<<"THANK YOU FOR CHOOSING US\n\n";
next = false;
break;

case 0:
cout<<"THANK YOU FOR CHOOSING US\n\n";
initialize_QS();        
next=false;
break;
}
	}   }
}
int main() {
	system("Color 1A");
	cout <<"WELCOME TO SEKOBANK \n\n";

int PeopleInOrder;
cout << "How many people in order :\n";
cout << "->";
cin >> PeopleInOrder;

Menu(PeopleInOrder);
}
