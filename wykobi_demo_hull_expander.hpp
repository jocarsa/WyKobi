/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.5                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2017 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational geometry library and its components are    *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the Wykobi computational geometry library and its   *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/


#ifndef INCLUDE_WYKOBI_DEMO_HULL_EXPNADER_HPP
#define INCLUDE_WYKOBI_DEMO_HULL_EXPNADER_HPP


#include <algorithm>
#include <deque>
#include <string>
#include <cmath>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"


template<typename T>
class hull_expand
{
public:

   hull_expand(const T& expansion_length,
               const wykobi::polygon<T,2>   input_polygon,
                     wykobi::polygon<T,2>& output_polygon)
   {
      wykobi::segment<T,2> edge = wykobi::edge(input_polygon, 0);

      T inverter = T(std::abs(expansion_length));

      if (point_in_polygon(wykobi::segment_mid_point(edge) + wykobi::normalize(perpendicular(edge[1] - edge[0])),input_polygon))
      {
         inverter = T(-expansion_length);
      }

      for (unsigned int i = 0; i < input_polygon.size(); ++i)
      {
         wykobi::segment<T,2> edge = wykobi::edge(input_polygon,i);
         wykobi::vector2d<T>     v = wykobi::normalize(wykobi::perpendicular(edge[1] - edge[0])) * inverter;

         output_polygon.push_back(edge[0] + v);
         output_polygon.push_back(edge[1] + v);
      }
   }
};

template<typename T, typename Graphic>
class hull_expander : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const T expander_length = 1.0;

      graphic.clear(clWhite);
      graphic.set_pen_width(1);

      wykobi::triangle<T,2> triangle = wykobi::create_equilateral_triangle(T(graphic.center_x()),T(graphic.center_y()),T(450));

      /*wykobi::generate_random_object(T(graphic.center_x() - 100),  T(graphic.center_y() - 100),
                                       T(graphic.center_x() + 100),  T(graphic.center_y() + 100), triangle);*/

      triangle[2].x += 70;

      wykobi::polygon<T,2> polygon_1 = wykobi::make_polygon(triangle);
      wykobi::polygon<T,2> polygon_2;

      graphic.set_color(Graphic::clRed);
      graphic.draw(polygon_1);

      polygon_2.clear();

      hull_expand<T>(expander_length,polygon_1,polygon_2);

      for (unsigned int i = 1; i < 15; ++i)
      {
         if ((i % 2) == 0)
         {
            polygon_2.clear();
            hull_expand<T>(expander_length,polygon_1,polygon_2);
         }
         else
         {
            polygon_1.clear();
            hull_expand<T>(expander_length,polygon_2,polygon_1);
         }
      }

      graphic.set_color(Graphic::clBlue);
      graphic.draw(polygon_1);

      graphic.set_color(Graphic::clBlue);
      graphic.draw(polygon_2);
   }

   std::string name() { return "Corner Smoother"; }
};


#endif
