/*
Name:     		Daniel Cardin
Date: 		    Feb 20, 2021
Assignment #: Project 2
Status: 		  Complete 
-------------------------------------------------------------------------

Comments
This program will help users balance a checkbook.  The user will enter a
transaction type, then enter the transaction and results will be displayed
When the user exits, the balance (including service charges) will be shown
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
  beginningBalance = getBeginningBalance("Enter the beginning balance:  $");
  currentBalance = beginningBalance;

  while(transactionType != 'E')
  {
    //Process the user's selection of a transaction type and make sure it's uppercase
    transactionType = toupper(getTransactionType("Select Transaction Type:\nC - Process a Check\nD - Process a deposit \nE - Exit: \n\nEnter transaction type:  "));

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

   }//end of switch statement

    //Determine if the sentinal value has been entered and exit if it has
    if (transactionType == 'E')
      return 0; //end of if
    
    //get the amopunt of the transaction from user
    transactionAmount = getTransactionAmount("Enter transaction amount:  $");
    
    //add a service charge, but only if the transaction type is a check (deposits are free)
    if(transactionType == 'C')
      serviceCharges = serviceCharges + 0.25; //end of if

    //Calculations
    if(transactionType == 'C')
      currentBalance = currentBalance - transactionAmount; 
    else if (transactionType == 'D')
      currentBalance = currentBalance + transactionAmount;
    else cout << "No transaction " << endl; //end of if/else
      
    //Output to the user
    cout  << "Processing " << verboseTransactionType << " for $" << fixed << setprecision(2) << transactionAmount << endl << endl
          << "Processed..." << endl
          << "Balance: $" << currentBalance << endl; 

    //Display the service charge if there was one (i.e. if it was a check)
    if(transactionType == 'C')
    cout  << "Service Charge: $0.25 for a " << verboseTransactionType << endl;

    //Display the total service charges so far
    cout << "Total Service Charges: $" << fixed << setprecision(2) << serviceCharges << endl << endl
          << "----------------------------------------------------------" << endl;
  }//end of while loop

  cin.get();
  return 0;
} // end of main ()

void greetUser()
{
  cout << "--------------------------------------------------------------------" << endl 
       << "------------Daniel Cardin's Checkbook Balancing Program-------------" << endl
       << "--------------------------------------------------------------------" << endl; 
 }//end greetUser()
 
float getBeginningBalance(string prompt)
{
  float value;

  cout << prompt;
  cin >> value;
  cout << endl << endl;
  cout << "----------------------------------------------------------" << endl;
  return value;
}//end getBeginningBalance()

char getTransactionType(string prompt)
{
  char value;

  cout << prompt;
  cin >> value;

  return value;
}//end getTransactionType()

float getTransactionAmount(string prompt)
{
  float value;

  cout << prompt;
  cin >> value;

  return value;
}//end getTransactionAmount()
