/*
Name:     		Daniel Cardin
Date: 		    Feb 8, 2021
Assignment #: Project 1
Status: 		  Complete
-------------------------------------------------------------------------

Comments
This program will read in two integers and then display their sum,
product, average, quotient and remainder
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

//declaration of funtion prototypes
int getData(string);
int findSum(int,int);
int findProduct(int,int);
int findAverage(int,int);
int findQuotient(int,int);
int findRemainder(int,int);
void displayResult(int,int,int,string);

int main()
{
  //initializing values a and b as well as the vaious answers
  int a;
  int b;
  int sum;
  int product;
  int average;
  int quotient;
  int remainder;

  //user inputs for variables a and b
  a = getData("Enter the value for a: ");
  b = getData("Enter the value for b: ");

  //calculations
  sum = findSum(a,b);
  product = findProduct(a,b);
  average = findAverage(a,b);
  quotient = findQuotient(a,b);
  remainder = findRemainder(a,b);

  //display the result of calculation "48 + 2ab + 4b
  displayResult(a, b, sum, "The sum of ");
  displayResult(a, b, product, "The product of ");
  displayResult(a, b, average, "The average of ");
  displayResult(a, b, quotient, "The quotient of ");
  displayResult(a, b, remainder, "The remainder after ");

  cin.ignore(); cin.get();
  return 0;
} // end of main ()

//This will display the result
void displayResult(int a,int b,int answer,string message)
{
cout << message << a << " and " << b << " is " << answer << endl;

}
//Calculates the sum of the parameters
int findSum(int a, int b)
{
  return a + b; 
}//end of findSum())

//Calculates the product of the parameters
int findProduct(int a, int b)
{
  return a * b; 
}//end of findProduct())

//Calculates the average of the parameters
int findAverage(int a, int b)
{
  return a + b /2; 
}//end of findAverage))

//Calculates the quotient of the parameters
int findQuotient(int a, int b)
{
  return a/b; 
}//end of findQuotient))

//Calculates the remainder of the parameters
int findRemainder(int a, int b)
{
  return a %  b; 
}//end of findRemainder

int getData(string prompt)
{
  int value;

  cout << prompt;
  cin >> value;

  return value;
}
