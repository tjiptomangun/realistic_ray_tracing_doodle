//Image.h

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <math.h>
#include <string>
#include <fstream>
#include <rgb.h>

using namespace std;

class Image{

public:
	Image();

	// initializes raster to default rgb color
	Image(int width, int height);

	// iniatalizes raster to background
	Image(int width, int height, rgb background);

	// returns false if x or y are out of bounds, else true
	bool set(int x, int y, const rgb & color);

	void gammaCorrect(float gamma);

	// outputs PPM image to out
	void writePPM(ostream & out);

	void readPPM(string filename);

private:
	rgb** raster;
	int nx;	//raster width
	int ny; //raster height
	
};

#endif //_IMAGE_H_
