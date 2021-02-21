/*
Name:     		Daniel Cardin
Date: 		    Feb 20, 2021
Assignment #: Project 2
Status: 		  Working 
-------------------------------------------------------------------------

Comments
This program will help users balance a checkbook.  The user will enter a
transaction type, then enter the transaction and results will be displayed
taking into account service charges.
*/

#include <iostream>				// for cin, cout, endl
#include <string>
#include <iomanip>        // for setprecision, etc

using namespace std;

//declaration of funtion prototypes
float getBeginningBalance(string);
char getTransactionType(string);
float getTransactionAmount(string);
void greetUser();
void displayResult(int,int,int,string);

int main()
{
  //Greet the user
  greetUser();

  //initializing variables 
  float beginningBalance = 0.00;
  char transactionType = ' ';
  string verboseTransactionType = " ";
  float transactionAmount = 0.00;
  float serviceCharges = 0.00;
  float currentBalance = 0.00;
  
  //user inputs for variables transactionType and transactionAmount
  beginningBalance = getBeginningBalance("Enter the beginning balance:  ");
  currentBalance = beginningBalance;

  while(transactionType != 'E')
  {
    //Process the user's selection of a transaction type and make sure it's uppercase
    transactionType = toupper(getTransactionType("Select Transaction Type:\nC - Process a Check\nD - Process a deposit \nE - Exit: \n\nEnter tranaction type:  "));

   //Convert the user's selected transactionType into the corresponding English word for it.
   switch(transactionType)
   {
     case 'C': verboseTransactionType = "check";
               break;
     case 'D': verboseTransactionType = "deposit";
               break;
     case 'E': currentBalance = currentBalance - serviceCharges; 
               cout << "Processing end of month  \nFinal Balance:  $" << fixed << setprecision(2) << currentBalance << endl;
               break;
     default: cout << "Invalid Input.  " << endl;
              

   }

    //Determine if the sentinal value has been entered and exit if it has
    if (transactionType == 'E')
      return 0;

    transactionAmount = getTransactionAmount("Enter transaction amount: ");
    serviceCharges = serviceCharges + 0.25;

    //Calculations
    if(transactionType == 'C')
      currentBalance = currentBalance - transactionAmount; 
    else if (transactionType == 'D')
      currentBalance = currentBalance + transactionAmount;
    else cout << "No transaction " << endl;
      
    //Output to the user
    cout  << "Processing check for $" << fixed << setprecision(2) << transactionAmount << endl << endl
          << "Processed..." << endl
          << "Balance: $" << currentBalance << endl 
          << "Service Charge: $0.25 for a " << verboseTransactionType << endl 
          << "Total Service Charges: $" << fixed << setprecision(2) << serviceCharges << endl << endl
          << "----------------------------------------------------------" << endl;
  }

  cin.ignore(); cin.get();
  return 0;
} // end of main ()

void greetUser()
{
  cout << "--------------------------------------------------------------------" << endl 
       << "------------Daniel Cardin's Checkbook Balancing Program-------------" << endl
       << "--------------------------------------------------------------------" << endl; 
}
 
float getBeginningBalance(string prompt)
{
  float value;

  cout << prompt;
  cin >> value;

  return value;
}

char getTransactionType(string prompt)
{
  char value;

  cout << prompt;
  cin >> value;

  return value;
}

float getTransactionAmount(string prompt)
{
  float value;

  cout << prompt;
  cin >> value;

  return value;
}
