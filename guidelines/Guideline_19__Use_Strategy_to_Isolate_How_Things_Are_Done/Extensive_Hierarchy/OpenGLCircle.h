#ifndef OPENGL_CIRCLE_H
#define OPENGL_CIRCLE_H

#include "Circle.h"

class OpenGLCircle : public Circle
{
 public:
   explicit OpenGLCircle( double radius )
      : Circle( radius )
   {}

   void draw( /*some arguments*/ ) const override;
};

#endif