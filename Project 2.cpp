/*
 *	Project 2
 *	Banking
 *  Date: 29/May/2020
 *  Author: Travis Garlick
 */

#include <string>
#include <iomanip>	//for setfill
#include <iostream>	//for cout/cin
using namespace std;

//declare variables
double initialInvestment = 0.0;
double deposit			 = 0.0;
double interestRate		 = 0.0;
int years				 = 0;
double balance			 = 0.0;

//function for calculating end year balance and total interest
double calculate(double newInvestment, double newDeposit, double newInterest, int newYears) {
	balance = newInvestment;    //running balance total
	double totalInterest = 0;   //yearly earned interest
	//loop over user input number of years
	for (int i = 0; i < (newYears); ++i) {
		totalInterest = 0;	    //resets totalInterest after each year
		//loop 12 months for each year
		for (int j = 0; j < 12; ++j) {
			double interest = (balance + newDeposit) *
				((newInterest / 100.0) / 12.0);       //interest calculation
			totalInterest = totalInterest + interest; //running interest total
			balance = balance + newDeposit + interest;//new montlhy balance
		}
	}
	return totalInterest;
}

//function for getting new values from user
void requestInput() {
	//menu title
	cout << setfill('*') << setw(33) << endl;
	cout << "*" << endl;//creates line of asterisks
	cout << "********* Data Input ************" << endl;

	//request inputs
	cout << "Initial Investment Amount: " << endl;
	cout << "(numbers and decimals only. No $ symbol)" << endl;
	cin >> initialInvestment;
	if (cin.fail()) {//this is supposed to detect incorrect input
		throw runtime_error("Invalid input.");
	}
	cout << "Monthly Deposit: " << endl;
	cout << "(numbers and decimals only. No $ symbol)" << endl;
	cin >> deposit;
	if (cin.fail()) {
		throw runtime_error("Invalid input.");
	}
	cout << "Annual Interest: " << endl;
	cout << "(numbers and decimals only. No % symbol)" << endl;
	cin >> interestRate;
	if (cin.fail()) {
		throw runtime_error("Invalid input.");
	}
	cout << "Number of years: " << endl;
	cin >> years;
	if (cin.fail()) {
		throw runtime_error("Invalid input.");
	}
	system("pause");//I'm told this is supposed to prompt user to continue
}

//function for displaying balances
void displayBalance(double newInvestment, double newDeposit, double newInterest, int newYears) {
	//menu title
	cout << setfill('=') << setw(56) << endl;
	cout << "=" << endl;//creates line
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	cout << setfill('-') << setw(56) << endl;
	cout << "-" << endl;//creates line

	//loop over number of years
	for (int i = 1; i <= newYears; ++i) {
		//display for each year
		cout << i;
		//calculate and print balance
		calculate(newInvestment, newDeposit, newInterest, i);
		std::cout << std::fixed;			//sets output to two decimal places
		std::cout << std::setprecision(2);	//for displaying cents
		cout << setfill(' ') << setw(22) << balance;
		//calculate and print interest
		cout << setfill(' ') << setw(32) << calculate(newInvestment, newDeposit, newInterest, i);
		cout << endl << endl;
	}
}

int main()
{
	//user string variable
	string userStr = "yes";

	//loop as long as user continues
	while (userStr == "yes" || userStr == "YES" || userStr == "y" || userStr == "Y") {
		try {//error handling
			//call input function
			requestInput();

			//display balance without deposits
			cout << "Balance and Interest Without Additional Monthly Deposits"
				<< endl;
			//call displayBalance with no deposits
			displayBalance(initialInvestment, 0.0, interestRate, years);
			system("pause");//I'm told this is supposed to prompt user to continue

			//display balance with deposits
			cout << " Balance and Interest With Additional Monthly Deposits"
				<< endl;
			//call displayBalance with all variables
			displayBalance(initialInvestment, deposit, interestRate, years);
		}
		catch (runtime_error& excpt) {
			// Prints the error message passed by throw statement
			cout << excpt.what() << endl;
			cout << "Cannot compute investment." << endl;
		}
		catch (...) {
			cout << "An error occured." << endl;
		}

		//ask if user wants to continue
		cout << "Would you like to see another investement?" << endl;
		cin >> userStr;
	}
}