#include <iostream>
#include<iomanip>
#include<string>
#include "payroll.cpp"

using namespace std;
//base class
class new_employee
{
    public:
//CONSTRUCTOR: This function initializes the new_employee object and prompts for input.
new_employee();
//declaring methods
string get_first_name();
string get_surname();
float get_hours();
float get_rate();

   //ACCESS SPECIFIERS: Using 'protected' allows derived classes to access these
// members while keeping them hidden from the rest of the program.
    protected:
string dm_first_name;
string dm_surname;
float dm_hours;
float dm_rate;
};
// INHERITANCE: perm_employee is a derived class that inherits from the base class new_employee.
class perm_employee:public new_employee

{
public:

    perm_employee();//default constructor
    char get_status();
    float get_tax_credit();

protected:
    char dm_status ;
    float dm_tax_credit;
};

new_employee::new_employee()
{

    cout<<"___________________________"<<endl;

    cout <<"New Employee Record Data "<<endl;
    cout<<"___________________________"<<endl;
    cout<<"Enter First Name :";
    cin>>dm_first_name;
    cout<<"Enter  SurName :";
    cin>>dm_surname;
    cout<<"Enter hours :";
    cin>>dm_hours;
    cout<<"Enter Hourly Rate : ";
    cin>>dm_rate;

}
string new_employee::get_first_name()
{
    return dm_first_name;
}
string new_employee::get_surname()
{

    return dm_surname;
}
//SCOPE: Linking the get_hours function to the new_employee class
float new_employee::get_hours()
{
    return dm_hours;
}
float new_employee::get_rate()
{
    return dm_rate;
}
perm_employee::perm_employee()
{

    cout <<"perm_employee Data"<<endl;
    cout <<" Enter Paye Status S or C : ";
    cin>> dm_status;
    cout <<"Enter TAX Credit : ";
    cin>> dm_tax_credit;
}
char perm_employee::get_status()
{
    return dm_status;
}
float perm_employee::get_tax_credit()
{
    return dm_tax_credit;

}
//ARRAYS: Global arrays used to store data for multiple employees
string firstname[4];
string surname [4];
float hours[4];
float rate [4];
char status[4];
float tax_credit[4];
float gross[4];
float PAYE[4];
float PRSI[4];
float USC[4];
 main ()
{
//OBJECT: Creating an instance of the perm_employee class named Tom_Hanks.
    perm_employee Tom_Hanks;
    float hours1=Tom_Hanks.get_hours();
    float rate1= Tom_Hanks.get_rate();
    string firstname1= Tom_Hanks.get_first_name();
    string surname1= Tom_Hanks.get_surname();
    char status1 = Tom_Hanks.get_status();
    float tax_credit1= Tom_Hanks.get_tax_credit();

    cout<<setw(5)<<"|_____________________________|"<<endl;
cout<<"|"<<setw(5)<<"***Employee Record Data***"<<setw(5)<<"|"<<endl;
    cout<<"|_____________________________|"<<endl;
    cout <<"|"<<"First name"<<setw(10)<<firstname1<<setw(10)<<" |"<<endl;
    cout <<"|"<<"last name"<<setw(10)<<surname1<<setw(10)<<"      |"<<endl;
    cout <<"|"<<"weekly hours"<<setw(10)<<hours1<<setw(10)<<"   |"<<endl;
    cout <<"|"<<"weekly Rate "<<setw(10)<<rate1<<setw(10)<<"    |"<<endl;
    cout <<"|"<<"Tax Status"<<setw(10)<<status1<<setw(10)<<"    |"<<endl;
    cout <<"|"<<"Tax credit"<<setw(10)<<tax_credit1<<setw(10)<<"|"<<endl;


     perm_employee Employee1;
     hours[0]=Employee1.get_hours();
     rate [0]=Employee1.get_rate();
    firstname[0]=Employee1.get_first_name();
    surname[0]=Employee1.get_surname();
    tax_credit[0]=Employee1.get_tax_credit();
    status[0]=Employee1.get_status();

      perm_employee Employee2;
     hours[1]=Employee2.get_hours();
     rate [1]=Employee2.get_rate();
    firstname[1]=Employee2.get_first_name();
    surname[1]=Employee2.get_surname();
    tax_credit[1]=Employee2.get_tax_credit();
    status[1]=Employee2.get_status();

    perm_employee Employee3;
     hours[2]=Employee3.get_hours();
     rate [2]=Employee3.get_rate();
    firstname[2]=Employee3.get_first_name();
    surname[2]=Employee3.get_surname();
    tax_credit[2]=Employee3.get_tax_credit();
    status[2]=Employee3.get_status();


    perm_employee Employee4;
     hours[3]=Employee4.get_hours();
     rate [3]=Employee4.get_rate();
    firstname[3]=Employee4.get_first_name();
    surname[3]=Employee4.get_surname();
    tax_credit[3]=Employee4.get_tax_credit();
    status[3]=Employee4.get_status();
    float total_hours= hours[0]+hours[1] + hours[2] + hours[3];
    float average_hours=total_hours/4;

// Table Header for the Summary Report
cout << " ________________________________________________________________" << endl;
cout << "| Firstname | Surname    | Hours | Rate  | STATUS | Tax Credit |" << endl;
cout << "|-----------|------------|-------|-------|--------|------------|" << endl;

int i = 0;
while (i < 4)
{
    // Using left/right and setw to create a professional table layout
    cout << "| " << left << setw(10) << firstname[i]
         << "| " << setw(11) << surname[i]
         << "| " << setw(6) << hours[i]
         << "| " << setw(6) << rate[i]
         << "| " << setw(7) << status[i]
         << "| " << setw(11) << tax_credit[i] << "|" << endl;
    i++;
}
cout << "|___________|____________|_______|_______|________|____________|" << endl;
cout << "| Average Hours Worked: " << left << setw(38) << fixed << setprecision(2) << average_hours << " |" << endl;
cout << "|______________________________________________________________|" << endl;

// Generate Payslips
class Payroll employeeA;
gross[0]=employeeA.Get_gross_pay(hours[0], rate[0], status[0]);
PAYE[0]=employeeA.Get_PAYE(gross[0], tax_credit[0], status[0]);
PRSI[0]=employeeA.Get_PRSI(gross[0]);
USC[0]=employeeA.Get_USC(gross[0]);
employeeA.payslip_method(firstname[0], surname[0], gross[0], PAYE[0], PRSI[0], USC[0]);

class Payroll employeeB;
gross[1]=employeeB.Get_gross_pay(hours[1], rate[1], status[1]);
PAYE[1]=employeeB.Get_PAYE(gross[1], tax_credit[1], status[1]);
PRSI[1]=employeeB.Get_PRSI(gross[1]);
USC[1]=employeeB.Get_USC(gross[1]);
employeeB.payslip_method(firstname[1], surname[1], gross[1], PAYE[1], PRSI[1], USC[1]);

class Payroll employeeC;
gross[2]=employeeC.Get_gross_pay(hours[2], rate[2], status[2]);
PAYE[2]=employeeC.Get_PAYE(gross[2], tax_credit[2], status[2]);
PRSI[2]=employeeC.Get_PRSI(gross[2]);
USC[2]=employeeC.Get_USC(gross[2]);
employeeC.payslip_method(firstname[2], surname[2], gross[2], PAYE[2], PRSI[2], USC[2]);

class Payroll employeeD;
gross[3]=employeeD.Get_gross_pay(hours[3], rate[3], status[3]);
PAYE[3]=employeeD.Get_PAYE(gross[3], tax_credit[3], status[3]);
PRSI[3]=employeeD.Get_PRSI(gross[3]);
USC[3]=employeeD.Get_USC(gross[3]);
employeeD.payslip_method(firstname[3], surname[3], gross[3], PAYE[3], PRSI[3], USC[3]);

return 0;

}
