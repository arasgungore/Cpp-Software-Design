#ifndef DRAW_ALL_SHAPES_H
#define DRAW_ALL_SHAPES_H

#include <memory>
#include <vector>
class Shape;

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const& shapes );

#endif