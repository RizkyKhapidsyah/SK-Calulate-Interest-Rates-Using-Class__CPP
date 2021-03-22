#include <iostream>
#include <iomanip>
#include <iostream>
#include <conio.h>

using namespace std;

class utility : public std::numpunct<char> {
protected:
    virtual char do_thousands_sep() const {
        return ',';
    }

    virtual std::string do_grouping() const {
        return "\03";
    }
};

class Mortage {
private:
    double amount;
    double rates;
    int years;

public:
    void inputFunction();
    void outputFunction();
};

void Mortage::inputFunction() {

    cout << "\n Enter the amount of the loan: ";
    cin >> amount;

    if (amount > 100000) {
        cout << "\n Error: Amount Exceeds $100,000.00";
        return;
    }

    cout << "\n Enter the annual interest rate (example 3 = 3%):";
    cin >> rates;

    if (rates > 22) {
        cout << "\n Error: Rates Exceeds 22%";
        return;
    }

    cout << "\n Enter the Duration of the Loan in years:";
    cin >> years;

    if (years > 6) {
        cout << "\n Error: Years Exceeds 6";
        return;
    }
}

void Mortage::outputFunction() {

    double emi = 0;
    double paybackamt = 0;
    double interest = (amount * rates * years) / 100;

    paybackamt = amount + interest;
    emi = paybackamt / (years * 12);

    std::locale comma_locale(std::locale(), new utility());
    std::cout.imbue(comma_locale);

    cout << "\n\n";
    cout << left << "\tLoan Amount:            ";
    cout << right << setw(40) << setprecision(2) << fixed << amount << '\n';
    cout << left << "\tInterest Rate:          ";
    cout << right << setw(39) << setprecision(2) << fixed << rates << "%" << '\n';
    cout << left << "\tDuration(years):        ";
    cout << right << setw(40) << years << '\n';
    cout << left << "\tMonthly Payment:        ";
    cout << right << setw(40) << setprecision(2) << fixed << emi << '\n';
    cout << left << "\tTotal Payback Amount:   ";
    cout << right << setw(40) << setprecision(2) << fixed << paybackamt << '\n';
    cout << left << "\tTotal Interest Paid-in: ";
    cout << right << setw(40) << setprecision(2) << fixed << interest << '\n';
}

int main() {
    Mortage obj;

    char choice = 'Y';

    while (choice == 'Y') {
        obj.inputFunction();
        obj.outputFunction();

        cout << "\n Enter 'Y' to continue : ";
        cin >> choice;
    }

    _getch();
    return 0;
}