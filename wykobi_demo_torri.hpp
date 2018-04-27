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


#ifndef INCLUDE_WYKOBI_DEMO_TORRI_HPP
#define INCLUDE_WYKOBI_DEMO_TORRI_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


template<typename T, typename Graphic>
class torricelli_point : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      wykobi::triangle<T,2> triangle;

      wykobi::generate_random_object<T>
              (
                T(10), T(10), graphic.width() - T(10), graphic.height() - T(10),
                triangle
              );

      wykobi::point2d<T> torricelli_point = wykobi::torricelli_point(triangle);

      graphic.set_color(clBlack);
      graphic.set_pen_width(2);
      graphic.draw(triangle);

      graphic.set_color(clBlue);
      graphic.set_pen_width(1);
      graphic.draw(wykobi::make_segment(triangle[0],torricelli_point));
      graphic.draw(wykobi::make_segment(triangle[1],torricelli_point));
      graphic.draw(wykobi::make_segment(triangle[2],torricelli_point));

      graphic.set_color(clRed);
      graphic.set_pen_width(1);
      graphic.draw(wykobi::make_circle<T>(torricelli_point,5));
      graphic.draw(wykobi::make_circle<T>(torricelli_point,2));

      graphic.set_color(clBlue);
      graphic.set_pen_width(1);
      graphic.draw(wykobi::make_circle<T>(triangle[0],5));
      graphic.draw(wykobi::make_circle<T>(triangle[1],5));
      graphic.draw(wykobi::make_circle<T>(triangle[2],5));
   }

   std::string name() { return "Torricelli Point"; }
};

template<typename T, typename Graphic>
class trilateration : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      if ((graphic.width()) < 200 || (graphic.height() < 200))
         return;

      wykobi::triangle<T,2> triangle;
      wykobi::circle<T>    c0;
      wykobi::circle<T>    c1;
      wykobi::circle<T>    c2;
      wykobi::rectangle<T> window_rect = wykobi::make_rectangle<T>(T(100), T(100), graphic.width() - T(100), graphic.height() - T(100));

      do
      {
         do
         {
            wykobi::generate_random_object<T>
                    (T(100), T(100), graphic.width() - T(100), graphic.height() - T(100),triangle);
         }
         while (wykobi::is_skinny_triangle(triangle));

         wykobi::point2d<T> p = wykobi::generate_random_point(triangle);

         c0 = wykobi::make_circle(triangle[0],wykobi::distance(triangle[0],p));
         c1 = wykobi::make_circle(triangle[1],wykobi::distance(triangle[1],p));
         c2 = wykobi::make_circle(triangle[2],wykobi::distance(triangle[2],p));
      }
      while (
              !wykobi::circle_within_rectangle(c0,window_rect) ||
              !wykobi::circle_within_rectangle(c1,window_rect) ||
              !wykobi::circle_within_rectangle(c2,window_rect)
            );

      wykobi::point2d<T> trilaterated_point = wykobi::trilateration(c0,c1,c2);

      graphic.set_color(clBlue);
      graphic.set_pen_width(2);
      graphic.set_dash_mode();
      graphic.draw(c0);
      graphic.draw(c1);
      graphic.draw(c2);
      graphic.set_pen_width(3);
      graphic.set_nodash_mode();
      graphic.draw(wykobi::make_circle(triangle[0],3.0));
      graphic.draw(wykobi::make_circle(triangle[1],3.0));
      graphic.draw(wykobi::make_circle(triangle[2],3.0));

      graphic.set_color(clRed);
      graphic.set_pen_width(2);
      graphic.draw_crosshair(trilaterated_point,5);
      graphic.set_pen_width(3);
      graphic.draw(wykobi::make_circle(trilaterated_point,4.0));
   }

   std::string name() { return "Trilateration"; }
};

#endif
