#ifndef OPENGL_SQUARE_H
#define OPENGL_SQUARE_H

#include "Square.h"

class OpenGLSquare : public Square
{
 public:
   explicit OpenGLSquare( double side )
      : Square( side )
   {}

   void draw( /*some arguments*/ ) const override;
};

#endif