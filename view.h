#ifndef _VIEW_H
#define _VIEW_H

#include <string>

class View{
 public:
  virtual ~View() = default;
  //virtual void :update(const std::string& msg) = 0;
  virtual void notify(int row, int col, Colour colour, PieceType p) = 0;
  virtual void updateView() = 0;
};

#endif _VIEW_H