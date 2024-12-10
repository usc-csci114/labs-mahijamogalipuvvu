#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

double mean(vector<double> x) {
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    return sum / x.size();
}

int main() {

    ifstream file("gpa_sat.csv");

    vector<double> x(100); 
    vector<double> y(100); 


    string line;
    getline(file, line);

    while (getline(file, line)) {
        replace(line.begin(), line.end(), ',', ' '); 
        
        stringstream ss(line);
        string sat, gpa;

        ss >> sat >> gpa;

        y.push_back(stod(sat));
        x.push_back(stod(gpa));
    }
    file.close();

    double xMean = mean(x);
    double yMean = mean(y);

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += pow(x[i] - xMean, 2);
    }
    double beta = numerator / denominator;

    double alpha = yMean - (beta * xMean);

    vector<double> predicted; 
    double resSS = 0.0;
    double totSS = 0.0;

    for (int i = 0; i < x.size(); i++) {
        double predictedValue = alpha + (beta * x[i]);
        predicted.push_back(predictedValue);

        resSS += pow((y[i] - predictedValue), 2);
        totSS += pow((y[i] - yMean), 2);
    }

    double r_squared = 1 - (resSS / totSS);

    cout << "Model: SAT score = " << alpha << " + " << beta << "*GPA" << endl;
    cout << "R-squared value: " << r_squared << endl;

    return 0;
}
