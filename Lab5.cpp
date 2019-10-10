#include <iostream>     
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void student_heading();
float compute_gross_pay(char, float, int);
float compute_taxes(float, float, float);
float compute_federal_tax(float);
float compute_state_tax(float);
float compute_city_tax(float stateTax);
float compute_net_pay(float, float);
void print_pay_check(float, float, float, string, string, int, string, string, string, int);

int main()
{
	string name, ded, id, address, city, zip, rate, time;
	string lastname1, firstname1, street1, type1, city1, state1;
	char deductions1, job1;
	int id1, zip1, rate1, address1;

	ifstream inData;
	inData.open("infile.txt");
	inData >> name >> ded >> id >> address >> city >> zip >> rate >> time;
	inData >> lastname1 >> firstname1 >> deductions1 >> id1 >> address1 >> street1 >> type1 >> city1 >> state1 >> zip1 >> job1, rate1;

	float gross_pay1 = compute_gross_pay(job1, rate1, deductions1);
	float fed_tax1 = compute_federal_tax(gross_pay1);
	float state_tax1 = compute_state_tax(fed_tax1);
	float city_tax1 = compute_city_tax(state_tax1);
	float all_taxes1 = compute_taxes(state_tax1, city_tax1, fed_tax1);
	float net_pay1 = compute_net_pay(all_taxes1, gross_pay1);
	student_heading();
	print_pay_check(gross_pay1, net_pay1, all_taxes1, firstname1, lastname1, address1, street1, city1, state1, zip1);
}

void student_heading()
{
	cout << "*******************" << endl;
	cout << "Quishe' Branch" << endl;
	cout << "@02736538" << endl;
	cout << "SYCS-135 Computer Science I" << endl;
	cout << "Assignment  7" << endl;
	cout << "October 27, 2015" << endl;
	cout << "******************" << endl;
}

float compute_gross_pay(char parttime_fulltime, float pay, int deductions)
{
	float gross_pay;
	if (parttime_fulltime == 'P')
    		gross_pay = (deductions * 10.50) + (pay * 40);
	else if (parttime_fulltime == 'F')
  	  gross_pay = pay * 40;
	return gross_pay;
}

float compute_taxes(float state, float city, float federal)
{
	float total_tax;
	total_tax = state + city + federal;
	return total_tax;
}

float compute_federal_tax(float grosspay)
{
	float federal_tax;
	if (grosspay <= 200)
		federal_tax = .15 * grosspay;
	else if ((grosspay > 200) && (grosspay <= 500))
    		federal_tax = .25 * grosspay;
	else if (grosspay > 500)
    		federal_tax = .35 * grosspay;
	return federal_tax;
}

float compute_state_tax(float fedTax)
{
	float state_tax;
	if (fedTax < 80)
		state_tax = 0;
	else
		state_tax = fedTax * .10;
	return state_tax;
}

float compute_city_tax(float stateTax)
{
	float city_tax;
	if (stateTax <= 50)
		city_tax = 0;
	else
		city_tax = stateTax * .08;
	return city_tax;
}

float compute_net_pay(float totalTax, float grosspay)
{
	float net_pay;
	net_pay = grosspay - totalTax;
	return net_pay;
}

void print_pay_check(float grosspay, float netpay, float totalTax, string first, string last, int address, string street, string city, string st, int zip)
{
	cout << "*************************************************************************" << endl;
	cout << "ABC Flowers" << endl;
	cout << "123 Georgia Ave" << setw(40) << "10/27/2015" << endl;
	cout << "Washington, DC, 20059" << endl;
	cout << " " << endl;
	cout << "Payable to: " << setw(20) << last << first << setw(60) << "Pay this amount: " << netpay << endl;
	cout << setw(20) << address << street << endl;
	cout << setw(20) << city << st << zip << endl;
	cout << " " << endl;
	cout << "Gross Pay: " << grosspay << endl;
	cout << "Total Taxes: " << totalTax << endl;
	cout << " " << endl;
}
