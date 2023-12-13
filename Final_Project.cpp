#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_SIZE = 50;

unsigned short int BookID[MAX_SIZE];
unsigned long int BookISBN[MAX_SIZE];
string BookTitle[MAX_SIZE];
string BookAuthor[MAX_SIZE];
double BookPrice[MAX_SIZE];

int displayMenu() {
    int choice;
    bool validInput = false;
    do {
        cout << "Menu\n";
        cout << "1. Write data to text file\n";
        cout << "2. Read data from text file\n";
        cout << "3. Display data in column form\n";
        cout << "4. Enter data into the parallel arrays\n";
        cout << "5. Update data in the parallel arrays\n";
        cout << "6. Sort the parallel arrays by book title in alphabetical order\n";
        cout << "7. Sort the parallel arrays by book author in alphabetical order\n";
        cout << "8. Sort the parallel arrays by book cost in descending order\n";
        cout << "9. Quit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            validInput = true;
        }
    } while (!validInput);
    return choice;
}

void writeDataToFile() {
    string filename;
    cout << "Enter the name of the file to output: ";
    cin >> filename;
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Error opening file.\n";
        return;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        outfile << BookID[i] << " " << BookISBN[i] << " " << BookTitle[i] << "; " << BookAuthor[i] << "; " << BookPrice[i] << endl;
    }
    outfile.close();
    cout << "Data written to file.\n";
}

void readDataFromFile() {
    string filename;
    cout << "Enter the name of the file to input: ";
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file.\n";
        return;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        infile >> BookID[i] >> BookISBN[i];
        getline(infile, BookTitle[i], ';');
        getline(infile, BookAuthor[i], ';');
        infile >> BookPrice[i];
        infile.ignore();
    }
    infile.close();
    cout << "Data read from file.\n";
}

void displayData() {
    cout << "BookID\tBookISBN\tBookTitle\tBookAuthor\tBookPrice\n";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << BookID[i] << "\t" << BookISBN[i] << "\t" << BookTitle[i] << "; " << BookAuthor[i] << "; " << BookPrice[i] << endl;
    }
}

void enterData() {
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << "Enter data for book #" << i + 1 << endl;
        cout << "BookID: ";
        cin >> BookID[i];
        cout << "BookISBN: ";
        cin >> BookISBN[i];
        cout << "BookTitle: ";
        cin.ignore();
        getline(cin, BookTitle[i], ';');
        cout << "BookAuthor: ";
        getline(cin, BookAuthor[i], ';');
        cout << "BookPrice: ";
        cin >> BookPrice[i];
    }
}

void updateData() {
    int index;
    cout << "Enter the index of the element you want to update: ";
    cin >> index;
    cout << "Enter the new data for book #" << index + 1 << endl;
    cout << "BookID: ";
    cin >> BookID[index];
    cout << "BookISBN: ";
    cin >> BookISBN[index];
    cout << "BookTitle: ";
    cin.ignore();
    getline(cin, BookTitle[index], ';');
    cout << "BookAuthor: ";
    getline(cin, BookAuthor[index], ';');
    cout << "BookPrice: ";
    cin >> BookPrice[index];
}

bool compareTitle(string a, string b) {
    return a < b;
}

bool compareAuthor(string a, string b) {
    return a < b;
}

bool comparePrice(double a, double b) {
    return a > b;
}

void sortByTitle() {
    sort(BookTitle, BookTitle + MAX_SIZE, compareTitle);
}

void sortByAuthor();