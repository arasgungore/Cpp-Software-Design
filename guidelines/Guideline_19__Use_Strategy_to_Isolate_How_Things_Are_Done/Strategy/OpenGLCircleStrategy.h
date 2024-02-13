#ifndef OPENGL_CIRCLE_STRATEGY_H
#define OPENGL_CIRCLE_STRATEGY_H

#include "Circle.h"
#include "DrawStrategy.h"
//#include /* OpenGL graphics library */

class OpenGLCircleStrategy : public DrawStrategy<Circle>
{
 public:
   explicit OpenGLCircleStrategy( /* Drawing related arguments */ )
   {}

   void draw( Circle const& circle /*, ...*/ ) const override
   {
      // ... Implementing the logic for drawing a circle by means of OpenGL
   }

 private:
   /* Drawing related data members, e.g. colors, textures, ... */
};

#endif