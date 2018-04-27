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


#ifndef INCLUDE_WYKOBI_DEMO_CIRCLETANGENTS_HPP
#define INCLUDE_WYKOBI_DEMO_CIRCLETANGENTS_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


template<typename T, typename Graphic>
class circle_inner_tangents : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      wykobi::circle<T> circle0;
      wykobi::circle<T> circle1;

      do
      {
         wykobi::generate_random_object<T>
         (
           T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
           circle0
         );

         wykobi::generate_random_object<T>
         (
            T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
            circle1
         );

      }
      while (wykobi::distance(circle0,circle1) <=  T(0));

      graphic.set_color(clBlack);
      graphic.set_pen_width(3);

      graphic.draw(circle0);
      graphic.draw(circle1);

      graphic.draw_crosshair(wykobi::make_point(circle0),5);
      graphic.draw_crosshair(wykobi::make_point(circle1),5);

      std::vector<wykobi::segment<T,2> > tangent_segments;

      wykobi::circle_internal_tangent_segments(circle0,circle1,tangent_segments);

      graphic.set_color(clRed);
      graphic.set_pen_width(1);

      for (std::size_t i = 0; i < tangent_segments.size(); ++i)
      {
         graphic.draw(tangent_segments[i]);
         graphic.draw(wykobi::make_circle(tangent_segments[i][0],4.0));
         graphic.draw(wykobi::make_circle(tangent_segments[i][1],4.0));
      }
   }

   std::string name() { return "Circle Circle Inner Tangents"; }
};

template<typename T, typename Graphic>
class circle_outer_tangents : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      wykobi::circle<T> circle0;
      wykobi::circle<T> circle1;

      do
      {
         wykobi::generate_random_object<T>
         (
           T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
           circle0
         );

         wykobi::generate_random_object<T>
         (
            T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
            circle1
         );

      }
      while (wykobi::distance(circle0,circle1) <=  T(0));

      graphic.set_color(clBlack);
      graphic.set_pen_width(3);

      graphic.draw(circle0);
      graphic.draw(circle1);

      graphic.draw_crosshair(wykobi::make_point(circle0),5);
      graphic.draw_crosshair(wykobi::make_point(circle1),5);

      std::vector<wykobi::segment<T,2> > tangent_segments;

      wykobi::circle_outer_tangent_segments(circle0,circle1,tangent_segments);

      graphic.set_color(clRed);
      graphic.set_pen_width(1);

      for (std::size_t i = 0; i < tangent_segments.size(); ++i)
      {
         graphic.draw(tangent_segments[i]);
         graphic.draw(wykobi::make_circle(tangent_segments[i][0],4.0));
         graphic.draw(wykobi::make_circle(tangent_segments[i][1],4.0));
      }
   }

   std::string name() { return "Circle Circle Outer Tangents"; }
};


template<typename T, typename Graphic>
class circum_inscribed_circles : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      if ((graphic.width()) < 200 || (graphic.height() < 200))
         return;

      wykobi::triangle<T,2> triangle;

      do
      {
         wykobi::generate_random_object<T>
                 (T(100), T(100), graphic.width() - T(100), graphic.height() - T(100),triangle);
      }
      while (wykobi::is_skinny_triangle(triangle));

      const wykobi::circle    <T> circumcircle     = wykobi::circumcircle    (triangle);
      const wykobi::circle    <T> inscribed_circle = wykobi::inscribed_circle(triangle);
      const wykobi::triangle<T,2> intouch_triangle = create_intouch_triangle (triangle);

      graphic.set_pen_width(2);

      graphic.set_color(clBlack);
      graphic.draw(triangle);

      graphic.set_pen_width(3);

      graphic.set_color(clRed);
      graphic.draw(circumcircle);
      graphic.draw(wykobi::make_circle(triangle[0],3.0));
      graphic.draw(wykobi::make_circle(triangle[1],3.0));
      graphic.draw(wykobi::make_circle(triangle[2],3.0));

      graphic.set_color(clBlue);
      graphic.draw(inscribed_circle);
      graphic.draw(intouch_triangle);

      graphic.draw(
         wykobi::make_circle(
            wykobi::closest_point_on_circle_from_segment(inscribed_circle,edge(triangle,0)),3.0));

      graphic.draw(
         wykobi::make_circle(
            wykobi::closest_point_on_circle_from_segment(inscribed_circle,edge(triangle,1)),3.0));

      graphic.draw(
         wykobi::make_circle(
            wykobi::closest_point_on_circle_from_segment(inscribed_circle,edge(triangle,2)),3.0));
   }

   std::string name() { return "Triangle Circumcircle And Inscribed Circle"; }
};


template<typename T, typename Graphic>
class excentral_circle_triangle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      if ((graphic.width()) < 200 || (graphic.height() < 200))
         return;

      wykobi::triangle<T,2>  triangle;
      wykobi::circle<T>     excircle1;
      wykobi::circle<T>     excircle2;
      wykobi::circle<T>     excircle3;

      wykobi::rectangle<T> window = wykobi::make_rectangle(0.0, 0.0, 1.0 * graphic.width(), 1.0 * graphic.height());

      do
      {
         wykobi::generate_random_object<T>
                 (T(0), T(0), graphic.width(), graphic.height(),triangle);

         excircle1 = wykobi::excircle(triangle,0);
         excircle2 = wykobi::excircle(triangle,1);
         excircle3 = wykobi::excircle(triangle,2);
      }
      while (
              wykobi::is_skinny_triangle(triangle)               ||
              !wykobi::circle_within_rectangle(excircle1,window) ||
              !wykobi::circle_within_rectangle(excircle2,window) ||
              !wykobi::circle_within_rectangle(excircle3,window)
            );

      wykobi::triangle<T,2> excentral_triangle = wykobi::create_excentral_triangle(triangle);

      graphic.set_pen_width(3);

      graphic.set_color(clRed);
      graphic.draw(excircle1);
      graphic.draw(excircle2);
      graphic.draw(excircle3);

      graphic.set_color(clBlue);
      graphic.draw(excentral_triangle);

      for (std::size_t i = 1; i <= 4; ++i)
      {
         graphic.draw(wykobi::make_circle(triangle[0], i * 1.0));
         graphic.draw(wykobi::make_circle(triangle[1], i * 1.0));
         graphic.draw(wykobi::make_circle(triangle[2], i * 1.0));
      }

      graphic.set_color(clRed);

      for (std::size_t i = 1; i <= 4; ++i)
      {
         graphic.draw(wykobi::make_circle(excentral_triangle[0], i * 1.0));
         graphic.draw(wykobi::make_circle(excentral_triangle[1], i * 1.0));
         graphic.draw(wykobi::make_circle(excentral_triangle[2], i * 1.0));
      }

      graphic.set_pen_width(2);

      graphic.set_color(clBlack);
      graphic.draw(triangle);
   }

   std::string name() { return "Excentral Circles And Triangle"; }
};


template<typename T, typename Graphic>
class circle_tangent_lines : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      wykobi::rectangle<T> window = wykobi::make_rectangle(0.0, 0.0, 1.0 * graphic.width(), 1.0 * graphic.height());

      wykobi::point2d<T> external_point;
      wykobi::circle<T>  circle;

      do
      {
         external_point = wykobi::generate_random_point<T>(1.0 * graphic.width(), 1.0 * graphic.height());

         wykobi::generate_random_object<T>
                 (T(0), T(0), graphic.width(), graphic.height(), circle);
      }
      while (
              !wykobi::circle_within_rectangle(circle,window) ||
               wykobi::point_in_circle(external_point,circle)
            );

      wykobi::point2d<T> tangent_point1;
      wykobi::point2d<T> tangent_point2;

      wykobi::circle_tangent_points(circle, external_point, tangent_point1, tangent_point2);

      graphic.set_pen_width(3);

      graphic.set_color(clBlack);
      graphic.draw(circle);

      graphic.set_pen_width(1);

      graphic.set_color(clRed);

      graphic.draw(wykobi::make_segment(external_point, tangent_point1));
      graphic.draw(wykobi::make_segment(external_point, tangent_point2));

      graphic.draw(wykobi::make_circle(tangent_point1, 3.5));
      graphic.draw(wykobi::make_circle(tangent_point2, 3.5));

      graphic.draw_crosshair(wykobi::make_point(circle), 5.0);

      graphic.set_dash_mode();
      graphic.draw(wykobi::make_segment(wykobi::make_point(circle), tangent_point1));
      graphic.draw(wykobi::make_segment(wykobi::make_point(circle), tangent_point2));
      graphic.set_nodash_mode();

      graphic.set_pen_width(3);
      graphic.set_color(clBlue);

      for (std::size_t i = 1; i <= 4; ++i)
      {
         graphic.draw(wykobi::make_circle(external_point, 1.0 * i));
      }
   }

   std::string name() { return "Point To Circle Tangent Lines"; }
};

#endif
