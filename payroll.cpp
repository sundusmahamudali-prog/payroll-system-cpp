// Payroll program
// Demonstrates encapsulation and calculates gross pay, PAYE, USC, PRSI, and net pay.
// Outputs a formatted payslip for each employee.


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Payroll class stores employee payroll data and performs all payroll calculations.

class Payroll
{

public:
float Get_gross_pay (float hours ,float rate,char status);
float Get_PAYE(float gross ,float tax_credit,char PAYE_status);
float Get_USC(float gross_pay);
float Get_PRSI(float gross);
float Get_Netpay();
void Set_name(string n);
void Print_payslip(int emp_no, int week);
void payslip_method(string FName, string SName, float gross,float paye, float prsi ,float usc );

// Private data members used for payroll calculations and employee info

private:
float dm_PAYE;
int dm_Week_no;
char dm_PAYE_status;
float dm_hours;
float dm_SRCOP;
float dm_rate;
float dm_USC;
float dm_gross;
float dm_PRSI;
float dm_net_pay;
float dm_tax_credit;
int dm_emp_no;
string dm_name;
};
// Method to calculate weekly gross pay using input hours and rate
float Payroll::Get_gross_pay(float hours, float rate, char status) {
    // Use the 'rate' passed from main, not the uninitialized 'dm_rate'
    if (rate < 13.50) {
        dm_rate = 13.50;
    } else {
        dm_rate = rate;
    }

    dm_hours = hours;
    dm_gross = dm_hours * dm_rate;
    return dm_gross;
}
// Method applies PAYE rules and calculates tax based on PAYE status (S or C)
float Payroll::Get_PAYE(float gross, float tax_credit, char PAYE_status) {
    dm_gross = gross;

    // Set SRCOP based on status
    if (PAYE_status == 'S' || PAYE_status == 's') {
        dm_SRCOP = 846.15;
    } else {
        dm_SRCOP = 1019.23;
    }

    // Calculate Tax before credits
    if (dm_gross <= dm_SRCOP) {
        dm_PAYE = dm_gross * 0.20;
    } else {
        dm_PAYE = (dm_SRCOP * 0.20) + ((dm_gross - dm_SRCOP) * 0.40);
    }

    // Use the tax_credit passed from the user input in main()
    dm_PAYE -= tax_credit;

    if (dm_PAYE < 0) dm_PAYE = 0;
    return dm_PAYE;
}

float Payroll::Get_USC(float gross_pay)
{
dm_USC = 0;
if(gross_pay<= 231){

dm_USC = gross_pay*0.005;

}
else if (gross_pay > 231 && gross_pay <= 495.38){
dm_USC = (gross_pay - 231) * 0.02 +1.155;
}
else if (gross_pay > 495.38 && gross_pay <= 1347.00){
dm_USC = ((gross_pay - 495.38) * 0.03)+1.155+5.287;
}
else{
dm_USC = (gross_pay - 1347) * 0.08 + 1.155 + 5.287 + 25.54;
}
return dm_USC;
}
// PRSI is a flat 4% deduction from gross income.

float Payroll:: Get_PRSI(float gross){
dm_gross = gross;
dm_PRSI = dm_gross*0.04;
return dm_PRSI;
}
float Payroll::Get_Netpay()
{
// Net pay = gross pay minus all deductions (PAYE, USC, PRSI).

dm_net_pay = dm_gross-(dm_PAYE + dm_USC+dm_PRSI);
return dm_net_pay;
}
// Stores the employee's name for printing on the payslip.

void Payroll::Set_name(string n){
dm_name = n;
}
// Outputs a formatted payslip showing all calculated payroll values
void Payroll::Print_payslip(int emp_no, int week)
{
dm_emp_no = emp_no;
dm_Week_no = week;
cout<<"----------------------------------------"<<endl;
cout<<"|"<<setw(33)<<"Rathmines IT Services"<<setw(4)<<"     |"<<endl;
cout<<"|Week No:"<<setw(29)<<dm_Week_no<<" |"<<endl;
cout<<"| Employee No:"<<setw(25)<<dm_emp_no<<"|"<<endl;
cout<<"| Name:"<<setw(32)<<dm_name<<"|"<<endl;
cout<<"|---------------------------------------" <<endl;

cout<<fixed<<setprecision(2);
cout<<"|Gross Pay:"<<setw(26)<<dm_gross<<"  |"<<endl;
cout<<"| PAYE:"<<setw(26)<<dm_PAYE<<"      |"<<endl;
cout<<"| USC:"<<setw(26)<<dm_USC<<"       |"<<endl;
cout<<"| PRSI:"<<setw(26)<<dm_PRSI<<"      |"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"| Net Pay:"<<setw(26)<<dm_net_pay<<"   |"<<endl;


cout<<" ---------------------------------------"<<endl;
}
void Payroll::payslip_method(string FName, string SName, float gross, float Paye, float prsi, float usc)
{
    // Assigning passed values to data members to fix the 0.00 calculation error
    dm_gross = gross;
    dm_PAYE = Paye;
    dm_USC = usc;
    dm_PRSI = prsi;
    dm_net_pay = dm_gross - (dm_PAYE + dm_USC + dm_PRSI);

    cout << "\n\n  ======================================== " << endl;
    cout << " |         RATHMINES IT SERVICES          |" << endl;
    cout << " |               PAY SLIP                 |" << endl;
    cout << "  ======================================== " << endl;
    cout << " | Name: " << left << setw(24) << FName + " " + SName << "        |" << endl;
    cout << " |----------------------------------------|" << endl;
    cout << fixed << setprecision(2);
    cout << " | Gross Pay: " << right << setw(23) << dm_gross << " |" << endl;
    cout << " | PAYE:      " << right << setw(23) << dm_PAYE << " |" << endl;
    cout << " | USC:       " << right << setw(23) << dm_USC << " |" << endl;
    cout << " | PRSI:      " << right << setw(23) << dm_PRSI << " |" << endl;
    cout << " |----------------------------------------|" << endl;
    cout << " | NET PAY:   " << right << setw(23) << dm_net_pay << " |" << endl;
    cout << "  ======================================== \n" << endl;
}
int main1()
{
// Creating two Payroll objects (instances of the class)
/*Payroll Emp_101;
Emp_101.Set_name("Kim Bloggs");
Emp_101.Get_USC(Emp_101.Get_gross_pay());
Emp_101.Get_PAYE('S');
Emp_101.Get_PRSI();
Emp_101.Get_Netpay();
Emp_101.Print_payslip(101,48);



cout<<endl;


Payroll Emp_102;
Emp_102.Set_name("joe Bloggs");
Emp_102.Get_USC(Emp_102.Get_gross_pay());
Emp_102.Get_PAYE('c');
Emp_102.Get_PRSI();
Emp_102.Get_Netpay();
Emp_102.Print_payslip(102,48);
*/

return 0;
}
