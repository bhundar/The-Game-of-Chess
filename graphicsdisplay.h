#ifndef GRDISPLAY_H
#define GRDISPLAY_H
#include <iostream>
#include <vector>
#include "info.h"
#include "tile.h"
#include "window.h"

class Tile;

class GraphicsDisplay { //subclass for abstarct class Observer
  Xwindow *xw = nullptr; // pointer to class Xwindow
  const int gridSize;
public:
  GraphicsDisplay(int n); //Constructor
  char pcToChar(Colour c, PieceType p);
	void notify(int row, int col, Colour c, PieceType p);

  ~GraphicsDisplay(); //Destructor
};

#endif

