#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "bmplib.h"
#include "drawing.h"

//implement your classes in this file

//adapted from https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
std::vector<Point> plotLine(Point start, Point end)
{
	int x0 = start.x;
	int y0 = start.y;
	int x1 = end.x;
	int y1 = end.y;
	
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;
	
	std::vector<Point> line;
	
	while(true)
	{
		Point p = {x0, y0};
		line.push_back(p);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if(e2 >= dy) {
			error = error + dy;
			x0 = x0 + sx;
		}
		if(e2 <= dx) {
			error = error + dx;
			y0 = y0 + sy;
		}
	}
	return line;
}

ColorImage::ColorImage(uint32_t xdim, uint32_t ydim){
    data.resize(ydim);   
	ColorPixel backgroundWhite = {255, 255, 255};                               //rows and then, columns- row major
    
    for(size_t i = 0; i < ydim; ++i) {                      //use size_t when working with lengths      
        data[i].resize(xdim);
		for (size_t j = 0; j < xdim; ++j){
			data[i][j] = backgroundWhite;  // Set each pixel to white (RGB: 255, 255, 255)

		}
	}
   
}

void ColorImage::setPixel(ColorPixel p, uint32_t x, uint32_t y) {
	if(y < data.size() && x < data[0].size()) 
		data[y][x] = p;
	

}

ColorPixel ColorImage::getPixel(uint32_t x, uint32_t y) {
	return data [y][x];

}
void ColorImage::render(string file) {
	uint8_t*** outputImage = new uint8_t**[data.size()];

	for(int i = 0; i < data.size(); i++) {
		outputImage[i] = new uint8_t*[data[0].size()];
		for(int j = 0; j < data[0].size(); j++) {
			outputImage[i][j] = new uint8_t[3];
			outputImage[i][j][0] = data[i][j].red;
			outputImage[i][j][1] = data[i][j].green;
			outputImage[i][j][2] = data[i][j].blue;
		}
	}

	writeRGBBMP(file.c_str(), outputImage, data.size(), data[0].size());
}


Drawing::Drawing() : 
	image(100, 100),   
    lines()   {}

void Drawing::parse(string filename) {
	ifstream ifile(filename);
	if(ifile.fail()) {
		cout << "cannot open the file. program quit" << endl;
		exit(1);
	} else {
		int xdim, ydim; 
		ifile >> xdim >> ydim;
    	image = ColorImage(xdim, ydim);

		double x1, y1, x2, y2;
    	uint8_t r, g, b;

		while (ifile >> x1 >> y1 >> x2 >> y2 >> r >> g >> b) {
			Line temp;
			temp.start.x = x1;
			temp.start.y = y1;

			temp.end.x = x2;
			temp.end.y = y2;

			temp.c.red = r;
			temp.c.green = g;
			temp.c.blue = b;

			lines.push_back(temp);
    }
	}
}
void Drawing::draw() {
	for(int i = 0; i < lines.size(); i++) {
		vector<Point> linePoints = plotLine(lines[i].start, lines[i].end);
		for(int j = 0; j < linePoints.size(); j++) {
			image.setPixel(lines[i].c, linePoints[j].x, linePoints[j].y);
		}
	}
} 



void Drawing::write(string filename) {
	image.render(filename);  
}
