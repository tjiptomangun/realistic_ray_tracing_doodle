// image.cc
#include <image.h>
#include <iostream>
using namespace std;

Image::Image() {
}

Image::Image(int width, int height){
	nx = width;
	ny = height;

	// allocate memory for raster
	raster = new rgb*[nx];

	for (int i = 0; i < nx; i++)
		raster[i] = new rgb[ny];
}

Image::Image(int width, int height, rgb background) {
	nx = width;
	ny = height;

	// allocate memory for raster
	raster = new rgb*[nx];

	for (int i = 0; i < nx; i++) {
		raster[i] = new rgb[ny];
		// assign background to each element
		for (int j = 0; i < ny; j++)
			raster[i][j] = background;
	}
}

bool Image::set(int x, int y, const rgb& color) {
	// check for out of bound error
	if (0 > x || x > nx) return false;
	if (0 > y || y > ny) return false;

	raster[x][y] = color;

	return true;
}

void Image::gammaCorrect(float gamma){
	rgb temp;
	float power = 1.0/gamma;
	for (int i = 0; i < nx; i ++)
		for (int j = 0; j < ny; j++){
			temp = raster[i][j];
			raster[i][j] = rgb(pow(temp.r(), power, pow(temp.g(), power,
				rgb(pow(temp.b(), power));
		}
}
