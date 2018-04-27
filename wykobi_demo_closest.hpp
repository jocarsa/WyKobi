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


#ifndef INCLUDE_WYKOBI_DEMO_CLOSEST_HPP
#define INCLUDE_WYKOBI_DEMO_CLOSEST_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"


template<typename T, typename Graphic>
class closest_point_on_segment : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::segment<T,2> segment;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        segment
      );

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.set_color(clBlack);
      graphic.draw(segment);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point = wykobi::closest_point_on_segment_from_point(segment,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();
            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));
            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Segment"; }
};


template<typename T, typename Graphic>
class closest_point_on_triangle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::triangle<T,2> triangle;

      do
      {
         wykobi::generate_random_object<T>
         (
           T(10), T(10), graphic.width() - T(10), graphic.height() - T(10),
           triangle
         );
      }
      while (wykobi::is_skinny_triangle(triangle));

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );


      graphic.set_color(clBlack);
      graphic.draw(triangle);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point = wykobi::closest_point_on_triangle_from_point(triangle,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();
            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));
            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Triangle"; }
};

template<typename T, typename Graphic>
class closest_point_on_rectangle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::rectangle<T> rectangle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        rectangle
      );

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5),graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.draw(rectangle);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point =
                              wykobi::closest_point_on_rectangle_from_point(rectangle,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Rectangle"; }
};

template<typename T, typename Graphic>
class closest_point_on_quadix : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::quadix<T,2> quadix;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        quadix
      );

      std::vector< wykobi::point2d<T> > point_list;

      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.set_color(clBlack);
      graphic.draw(quadix);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point = wykobi::closest_point_on_quadix_from_point(quadix,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Quadix"; }
};

template<typename T, typename Graphic>
class closest_point_on_circle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::circle<T> circle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        circle
      );

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.draw(circle);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point = wykobi::closest_point_on_circle_from_point(circle,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Circle"; }
};

template<typename T, typename Graphic>
class closest_point_on_polygon : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 80;

      graphic.clear(clWhite);

      wykobi::polygon<T,2> polygon;

      generate_polygon_type2<T>(graphic.width(), graphic.height(), polygon);

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(2 * max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.set_color(clBlack);
      graphic.draw(polygon);

      for (std::size_t i = 0; i < point_list.size(); ++i)
      {
         wykobi::point2d<T> closest_point =
                               wykobi::closest_point_on_polygon_from_point(polygon, point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Polygon"; }
};


template<typename T, typename Graphic>
class closest_point_on_quadratic_bezier : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::quadratic_bezier<T,2> bezier;
      bezier[0] = wykobi::generate_random_point<T>(graphic.width() - T(5), graphic.height() - 5.0);
      bezier[1] = wykobi::generate_random_point<T>(graphic.width() - T(5), graphic.height() - 5.0);
      bezier[2] = wykobi::generate_random_point<T>(graphic.width() - T(5), graphic.height() - 5.0);

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5),graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.draw(bezier,100);

      for (std::size_t i = 0; i < max_points; ++i)
      {
         wykobi::point2d<T> closest_point =
                               wykobi::closest_point_on_bezier_from_point(bezier,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Quadratic Bezier"; }
};

template<typename T, typename Graphic>
class closest_point_on_cubic_bezier : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_points = 40;

      graphic.clear(clWhite);

      wykobi::cubic_bezier<T,2> bezier;
      bezier[0] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
      bezier[1] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
      bezier[2] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
      bezier[3] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::generate_random_points
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        max_points,
        std::back_inserter(point_list)
      );

      graphic.draw(bezier,100);

      for (std::size_t i = 0; i < max_points; ++i)
      {
         wykobi::point2d<T> closest_point =
                               wykobi::closest_point_on_bezier_from_point(bezier,point_list[i]);

         if (wykobi::distance(closest_point,point_list[i]) > T(1))
         {
            graphic.set_color(clBlack);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point,point_list[i]));

            graphic.set_nodash_mode();
         }

         graphic.set_color(clBlue);
         graphic.draw_circle(point_list[i],3);

         graphic.set_color(clRed);
         graphic.draw_circle(closest_point,2);
      }
   }

   std::string name() { return "Closest Point On Cubic Bezier"; }
};

template<typename T, typename Graphic>
class closest_point_between_circles : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      wykobi::circle<T> circle1;
      wykobi::circle<T> circle2;

      wykobi::generate_random_object<T>
      (T(0), T(0), graphic.width() - T(1), graphic.height() - T(1), circle1);

      wykobi::generate_random_object<T>
      (T(0), T(0), graphic.width() - T(1), graphic.height() - T(1), circle2);

      graphic.set_color(clBlack);
      graphic.draw(circle1);
      graphic.draw(circle2);

      if (wykobi::distance(circle1,circle2) > T(0))
      {
         wykobi::point2d<T> closest_point1 = wykobi::closest_point_on_circle_from_point(circle1,wykobi::make_point(circle2));
         wykobi::point2d<T> closest_point2 = wykobi::closest_point_on_circle_from_point(circle2,wykobi::make_point(circle1));

         graphic.set_color(clRed);
         graphic.set_dash_mode();

         graphic.draw(wykobi::make_segment(closest_point1,closest_point2));

         graphic.set_nodash_mode();

         graphic.draw_circle(closest_point1,4);
         graphic.draw_circle(closest_point2,4);
      }
      else
      {
         graphic.set_color(clRed);
         graphic.draw_circle(wykobi::make_point(circle1),4);
         graphic.draw_circle(wykobi::make_point(circle2),4);
      }
   }

   std::string name() { return "Closest Point Between Circles"; }
};

template<typename T, typename Graphic>
class closest_points_between_segment_circle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_segments = 10;

      graphic.clear(clWhite);

      std::vector<wykobi::segment<T,2> > segment_list;
      segment_list.reserve(max_segments);

      generate_random_segments<double>
      (
        T(0), T(0), T(graphic.width() - 10), T(graphic.height() - 10),
        max_segments,
        std::back_inserter(segment_list)
      );

      wykobi::circle<T> circle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        circle
      );

      graphic.set_color(clBlack);
      graphic.draw(circle);

      for (std::size_t i = 0; i < segment_list.size(); ++i)
      {
         if (!wykobi::intersect(segment_list[i],circle))
         {
            wykobi::point2d<T> closest_point_on_segment =
                                 wykobi::closest_point_on_segment_from_point(segment_list[i], wykobi::make_point(circle));

            wykobi::point2d<T> closest_point_on_circle  =
                                 wykobi::closest_point_on_circle_from_point(circle, closest_point_on_segment);

            graphic.set_color(clBlue);

            graphic.draw(segment_list[i]);

            graphic.set_color(clRed);
            graphic.set_dash_mode();

            graphic.draw(wykobi::make_segment(closest_point_on_segment,closest_point_on_circle));

            graphic.set_nodash_mode();

            graphic.draw_circle(closest_point_on_segment,4);
            graphic.draw_circle(closest_point_on_circle,4);
         }
         else
         {
            graphic.set_color(clBlue);
            graphic.draw(segment_list[i]);

            graphic.set_color(clLimeGreen);
            graphic.draw_circle(segment_list[i][0],3);
            graphic.draw_circle(segment_list[i][1],3);
         }
      }
   }

   std::string name() { return "Closest Point Between Segment And Circle"; }
};

#endif
