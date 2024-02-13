#ifndef OPENGL_SQUARE_STRATEGY_H
#define OPENGL_SQUARE_STRATEGY_H

#include "Square.h"
//#include /* OpenGL graphics library */

class OpenGLSquareStrategy
{
 public:
   explicit OpenGLSquareStrategy( /* Drawing related arguments */ )
   {}

   void operator()( Square const& square /*, ...*/ ) const
   {
      // ... Implementing the logic for drawing a square by means of OpenGL
   }

 private:
   /* Drawing related data members, e.g. colors, textures, ... */
};

#endif