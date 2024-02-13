#ifndef OPENGL_CIRCLE_STRATEGY_H
#define OPENGL_CIRCLE_STRATEGY_H

#include "Circle.h"
//#include /* OpenGL graphics library */

class OpenGLCircleStrategy
{
 public:
   explicit OpenGLCircleStrategy( /* Drawing related arguments */ )
   {}

   void operator()( Circle const& circle /*, ...*/ ) const
   {
      // ... Implementing the logic for drawing a circle by means of OpenGL
   }

 private:
   /* Drawing related data members, e.g. colors, textures, ... */
};

#endif