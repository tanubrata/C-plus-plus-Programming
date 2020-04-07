/******************************************************************************

Name: Tanubrata Dey
Course: Csci136
Instructor: Minh Nguyen
Task: Lab 8F
This file turns the given image into pixelated image by creating a non-overlapping window contain same image
*******************************************************************************/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}
//this is the helper function that helps copying each pixel of input as a small 2x2 square in output
/*void copy2x2(int img[MAX_H][MAX_W], int out[2*MAX_H][2*MAX_W], int row, int col) {
    for (int i=2*row; i<2*row+2; i++) {
        for (int j=2*col; j<2*col+2; j++) {
            out[i][j] = img[row][col];
        }
    }
    
}
*/
//Part F: This is the helper function that helps averaging the 2x2 square
void pixelate2x2(int img[MAX_H][MAX_W], int out[MAX_H][MAX_W], int row, int col) {
    int avg = 0;
    for (int i=row; i<row+2; i++) {//finish for loop
        for (int j=col; j<col+2; j++) {//since we only deal with 2x2 square, thats why we only need to go from row(col) to row+2
            avg = avg + img[i][j];
        }
    }
    avg = avg/4;
    
    for (int i=row; i<row+2; i++) {//finish for loop
        for (int j=col; j<col+2; j++) {
            out[i][j] = avg;
        }
    }
}

int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

////Since its a 2D array (matrix), we use nested loop 
/*
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
		    if ((row >= h/4 && row <= 3*h/4) && (col == w/4 || col == 3*w/4)) {//the right half of the image invert
		        out[row][col] = 255;//convert every pixel to 255 i.e white
		    }
		    else if ((col >= w/4 && col <=3*w/4) && (row == h/4 || row == 3*h/4)) {
		        out[row][col] = 255;
		    }
			else {//the rest keep it same
			    out[row][col] = img[row][col];
			}
		}
	}
*/
//PART F
    for(int row = 0; row < h; row+2) {
		for(int col = 0; col < w; col+2) {
		    pixelate2x2(img, out, row, col);
		}
    }
	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
