#include <iostream>
#include "bmplib.h"
#include "drawing.h"

using namespace std;

int main(int argc, char* argv[])
{
	ColorImage test(100, 100);
	//use the structs/classes you defined in drawing.h to implement the program in this file
	ColorPixel white = {255, 255, 255};

	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			test.setPixel(white, j, i);
		}
	}
	
	test.render("test.bmp");


	Drawing one;
	one.parse("input.txt");
	one.draw();
	one.write("output.bmp");


}
