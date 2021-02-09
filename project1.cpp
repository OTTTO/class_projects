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
int getProd()
int findResult(int,int);
void displayResult(int,int,int);

int main()
{
  //initializing values a and b
  int a;
  int b;
  int answer;

  //user inputs for variables a and b
  a = getData("Enter the value for a: ");
  b = getData("Enter the value for b: ");

  //calculation for the equation 48 + 2ab + 4b
  answer = findResult(a,b);

  //display the result of calculation "48 + 2ab + 4b
  displayResult(a, b, answer);

  cin.ignore(); cin.get();
  return 0;
} // end of main ()

//This will display the result
void displayResult(int a,int b,int answer)
{
  cout << "The answer to 48 + 2ab + 4b, with a being " << a << " and b being " << b << " is " << answer << endl;

}
//calculates 48 + 2ab + 4b using two variables given (a and b)
int findResult(int a, int b)
{
  return 48 + 2 * a + 4 * b;
}//end of findResult())

  int getData(string prompt)
{
  int value;

  cout << prompt;
  cin >> value;

  return value;
}
