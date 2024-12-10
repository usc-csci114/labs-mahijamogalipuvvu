#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <matplot/matplot.h>

using namespace matplot;

int main() {
	
	std::ifstream ifile("atmosphere.txt");
	std::string line;
	std::vector<double> p, h, t;
	//follow the lab instructions to generate task1.png, task2a.png and task2b.png
	
	std::getline(ifile,line);
	std::getline(ifile,line);
	std::getline(ifile,line);
	std::getline(ifile,line);

	std::vector<double> h, p, t; // Height, Pressure, Temperature
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        double pressure, height, temp;
        ss >> pressure >> height >> temp;
        p.push_back(pressure);
        h.push_back(height);
        t.push_back(temp);
    }
    file.close();

    plot(h, p, "-bx");
    xlabel("Height (m)");
    ylabel("Pressure (hPa)");
    title("Pressure vs. Height");
	show()
    save("task2a.png");

    double t_min = *std::min_element(t.begin(), t.end());
    double t_max = *std::max_element(t.begin(), t.end());

    hold(on);
    plot(h, t, "-rx")->use_y2(true);
    y2lim({t_min, t_max});
    y2label("Temperature (°C)");
	show();
    save("task2b.png");
	return 0;
}
