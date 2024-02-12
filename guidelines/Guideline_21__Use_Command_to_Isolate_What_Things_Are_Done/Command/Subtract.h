#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "CalculatorCommand.h"

class Subtract : public CalculatorCommand
{
 public:
   explicit Subtract( int operand ) : operand_(operand) {}

   int execute( int i ) const override
   {
      return i - operand_;
   }
   int undo( int i ) const override
   {
      return i + operand_;
   }

 private:
   int operand_{};
};

#endif