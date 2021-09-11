#include "block.h"
#include <cmath>
#include <iostream>

// return the height of the block
int Block::height() const {
	return data[0].size();
}

// return the width of the block
int Block::width() const {
	return data.size();
}

//Render the given block onto img
void Block::render(PNG &im, int x) const {
  /* your code here */
 
 for ( int a = x; a < x + width(); a++) {
      for ( int b = 0; b < im.height(); b++) {
          *(im.getPixel(a,b)) = data[a-x][b];

      }
    }
}

//Creates a block that is width X img.height pixels in size
void Block::build(PNG &im, int x, int width) {
  /* your code here */
  data.resize(width,vector<HSLAPixel>(im.height()));
	for ( int a = x; a < x + width; a++) {
    	for ( int b = 0; b < im.height(); b++) {
          data[a-x][b] = *(im.getPixel(a,b));

    	}
    	
  	}
}
