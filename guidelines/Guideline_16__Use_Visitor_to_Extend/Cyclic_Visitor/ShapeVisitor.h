#ifndef SHAPE_VISITOR_H
#define SHAPE_VISITOR_H

class Circle;
class Square;

class ShapeVisitor
{
 public:
   virtual ~ShapeVisitor() = default;

   virtual void visit( Circle const& /*, ...*/ ) const = 0;
   virtual void visit( Square const& /*, ...*/ ) const = 0;
   // Possibly more visit() functions, one for each concrete shape
};

#endif