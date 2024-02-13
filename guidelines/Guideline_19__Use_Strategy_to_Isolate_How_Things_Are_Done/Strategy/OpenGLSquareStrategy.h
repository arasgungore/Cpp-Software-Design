#ifndef OPENGL_SQUARE_STRATEGY_H
#define OPENGL_SQUARE_STRATEGY_H

#include "Square.h"
#include "DrawStrategy.h"
//#include /* OpenGL graphics library */

class OpenGLSquareStrategy : public DrawStrategy<Square>
{
 public:
   explicit OpenGLSquareStrategy( /* Drawing related arguments */ )
   {}

   void draw( Square const& square /*, ...*/ ) const override
   {
      // ... Implementing the logic for drawing a square by means of OpenGL
   }

 private:
   /* Drawing related data members, e.g. colors, textures, ... */
};

#endif