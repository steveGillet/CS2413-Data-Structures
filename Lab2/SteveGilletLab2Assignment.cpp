//Steve Gillet Lab Assignment #2

#include <iostream>
#include <string>
using namespace std;

class student{
    private:
    int admno;
    string sname;
    float eng, math, science, total;
    float ctotal(){
        return eng + math + science;
    }
    public:
    void takeData(){
        cout << "Please enter the admno: ";
        cin >> admno;
        cout << "Please enter the sname: ";
        cin >> sname;
        cout << "Please enter the eng: ";
        cin >> eng;
        cout << "Please enter the science: ";
        cin >> science;
        cout << "Please enter the math: ";
        cin >> math;
        total = ctotal();
    }
    void showData(){
        cout << "admno: " << admno << endl;
        cout << "sname: " << sname << endl;
        cout << "eng: " << eng << endl;
        cout << "science: " << science << endl;
        cout << "math: " << math << endl;
        cout << "total: " << total << endl;
    }
};

class BOOK{
    private:
    int BOOK_NO;
    string BOOKTITLE;
    float PRICE, totalCost;
    void TOTAL_COST(int N){
        totalCost = N * PRICE;
    }
    public:
    void INPUT(){
        cout << "Please enter the book number: ";
        cin >> BOOK_NO;
        cout << "Please enter the title of the book: ";
        cin >> BOOKTITLE;
        cout << "Please enter the price of the book: ";
        cin >> PRICE;
    }
    void PURCHASE(){
        cout << "Please enter the quantity of this book you would like to purchase: ";
        int N;
        cin >> N;
        TOTAL_COST(N);
        cout << "The total cost is: " << totalCost << endl;
    }

    
};
class Distance{
    public:
    int feet;
    float inches;
    void set(int f, float i){
        feet = f;
        inches = i;
    }
    void disp(){
        cout << "Feet: " << feet << endl;
        cout << "Inches: " << inches << endl;
    }
    Distance add(Distance otherDistance)
    {
        Distance sum;
        sum.feet = feet + otherDistance.feet;
        sum.inches = inches + otherDistance.inches;
        return sum;
    }
};

int main(){
    student student1;
    student1.takeData();
    student1.showData();
    BOOK book1;
    book1.INPUT();
    book1.PURCHASE();
    int feet;
    float inches;
    Distance distance1, distance2, sumDistance12;
    cout << "Enter the first distance feet: ";
    cin >> feet;
    cout << "Enter the first distance inches: ";
    cin >> inches;
    distance1.set(feet, inches);
    cout << "Enter the second distance feet: ";
    cin >> feet;
    cout << "Enter the second distance inches: ";
    cin >> inches;
    distance2.set(feet, inches);
    sumDistance12 = distance1.add(distance2);
    cout << "The first distance is: " << endl;
    distance1.disp();
    cout << "The second distance is: " << endl;
    distance2.disp();
    cout << "The sum is: " << endl;
    sumDistance12.disp();
    return 0;
}