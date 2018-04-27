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


#ifndef INCLUDE_WYKOBI_DEMO_RANDOMIZE_HPP
#define INCLUDE_WYKOBI_DEMO_RANDOMIZE_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_demo_types.hpp"


template<typename T, typename Graphic>
class random_points_AABB : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_points = 1000;

      graphic.clear(clWhite);

      wykobi::rectangle<T> rectangle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(),
        rectangle
      );

      graphic.set_pen_width(3);
      graphic.draw(rectangle);
      graphic.set_pen_width(1);

      std::vector<wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points(rectangle, max_points, std::back_inserter(point));

      graphic.set_color(clBlack);

      for (std::size_t i = 0; i < point.size(); ++i)
      {
         if (wykobi::point_in_rectangle(point[i],rectangle))
            graphic.draw(point[i]);
         else
            graphic.draw_circle(point[i],T(10));
      }
   }

   std::string name() { return "Random Points Within AABB"; }
};

template<typename T, typename Graphic>
class random_points_triangle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_points = 1000;

      graphic.clear(clWhite);

      wykobi::triangle<T,2> triangle;

      wykobi::generate_random_object<T>
              (T(0), T(0),graphic.width(), graphic.height(), triangle);

      graphic.set_pen_width(3);
      graphic.draw(triangle);
      graphic.set_pen_width(1);

      std::vector<wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points
              (triangle, max_points, std::back_inserter(point));

      graphic.set_color(clBlack);

      for (std::size_t i = 0; i < point.size(); ++i)
      {
         if (wykobi::point_in_triangle(point[i],triangle))
            graphic.draw(point[i]);
         else
            graphic.draw_circle(point[i],T(10));
      }
   }

   std::string name() { return "Random Points Within Triangle"; }
};

template<typename T, typename Graphic>
class random_points_quadix : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_points = 1000;

      graphic.clear(clWhite);

      wykobi::quadix<T,2> quadix;

      wykobi::generate_random_object<T>
              (T(0), T(0), graphic.width(), graphic.height(), quadix);

      graphic.set_pen_width(3);
      graphic.draw(quadix);
      graphic.set_pen_width(1);

      std::vector<wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points
              (quadix, max_points, std::back_inserter(point));

      graphic.set_color(clBlack);

      for (std::size_t i = 0; i < point.size(); ++i)
      {
         if (wykobi::point_in_quadix(point[i],quadix))
            graphic.draw(point[i]);
         else
            graphic.draw_circle(point[i],T(10));
      }
   }

   std::string name() { return "Random Points Within Quadix"; }
};

template<typename T, typename Graphic>
class random_points_circle : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_points = 1000;

      graphic.clear(clWhite);
      graphic.set_color(clBlack);

      wykobi::circle<T> circle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(), circle
      );

      graphic.set_pen_width(3);
      graphic.draw(circle);
      graphic.set_pen_width(1);

      std::vector<wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points(circle, max_points, std::back_inserter(point));

      for (std::size_t i = 0; i < point.size(); ++i)
      {
         if (wykobi::point_in_circle(point[i],circle))
            graphic.draw(point[i]);
         else
            graphic.draw_circle(point[i],T(10));
      }
   }

   std::string name() { return "Random Points Within Circle"; }
};


template<typename T, typename Graphic>
class random_orietnted_ellipses : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      for (unsigned int i = 0; i < 100; ++i)
      {
         graphic.set_color(i % 15);

         oriented_ellipse<T>(wykobi::generate_random_value<T>(graphic.width()),
                             wykobi::generate_random_value<T>(graphic.height()),
                             wykobi::max<T>(20,wykobi::generate_random_value<T>(200)),
                             wykobi::max<T>( 5,wykobi::generate_random_value<T>( 50)),
                             wykobi::generate_random_value<T>(360),graphic);

      }
   }

   std::string name() { return "Random Oriented Ellipses"; }
};


template<typename T, typename Graphic>
void oriented_ellipse (const T& cx, const T& cy,  const T& a_length, const T& b_length, const T& rotation, const Graphic& graphic)
{
   /*
      Credits: Dave Eberly (Geometric Tools)
   */
   if (
        wykobi::is_equal(a_length, T(0)) ||
        wykobi::is_equal(b_length, T(0))
      )
      return;

   T ax =  T(b_length * wykobi::cos(rotation * wykobi::PIDiv180));
   T ay =  T(b_length * wykobi::sin(rotation * wykobi::PIDiv180));
   T bx = -T(a_length * wykobi::sin(rotation * wykobi::PIDiv180));
   T by =  T(a_length * wykobi::cos(rotation * wykobi::PIDiv180));

   if (wykobi::less_than_or_equal(ax, T(0)) && (ay > T(0)))
   {
      T t =  ax;
      ax  = -bx;
      bx  =   t;
      t   =  ay;
      ay  = -by;
      by  =   t;
   }
   else if ((ax < T(0)) && wykobi::less_than_or_equal(ay,T(0)))
   {
      ax = -ax;
      ay = -ay;
      bx = -bx;
      by = -by;
   }
   else if (wykobi::greater_than_or_equal(ax, T(0)) && (ay < T(0)))
   {
      T t = ax;
      ax  = bx;
      bx  = -t;
      t   = ay;
      ay  = by;
      by  = -t;
   }

   T a2x   = ax * ax;
   T a2y   = ay * ay;
   T b2x   = bx * bx;
   T b2y   = by * by;
   T axay  = ax * ay;
   T bxby  = bx * by;
   T la2   = a2x + a2y;
   T la4   = la2 * la2;
   T lb2   = b2x + b2y;
   T lb4   = lb2 * lb2;
   T a     = a2x * lb4 + b2x * la4;
   T b     = axay * lb4 + bxby * la4;
   T c     = a2y * lb4 + b2y * la4;
   T d     = la4 * lb4;
   T dx    = T(0);
   T dy    = T(0);
   T x     = T(0);
   T y     = T(0);
   T sigma = T(0);
   T p1x   = T(0);
   T m1y   = T(0);
   T p1y   = T(0);

   if (wykobi::less_than_or_equal(ay,ax))
   {
      x  = -ax;
      y  = -ay;
      dx = -(b * ax + c * ay);
      dy = a * ax + b * ay;

      while (wykobi::less_than_or_equal(dx,T(0)))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         y++;

         sigma = a * x * x + 2 * b * x * y + c * y * y - d;

         if (sigma < T(0))
         {
            dx -= b;
            dy += a;
            x--;
         }

         dx += c;
         dy -= b;
      }

      while (wykobi::less_than_or_equal(dx,dy))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         y++;

         p1x = x + 1;
         sigma = a * p1x * p1x + 2 * b * p1x * y + c * y * y - d;

         if (wykobi::greater_than_or_equal(sigma,T(0)))
         {
            dx += b;
            dy -= a;
            x = p1x;
         }

         dx += c;
         dy -= b;
      }

      while (wykobi::greater_than_or_equal(dy,T(0)))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         x++;

         sigma = a * x * x + 2 * b * x * y + c * y * y - d;

         if (sigma < T(0))
         {
            dx += c;
            dy -= b;
            y++;
         }

         dx += b;
         dy -= a;
      }

      while (wykobi::greater_than_or_equal(dy,-dx))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         x++;
         m1y = y - 1;

         sigma = a * x * x + 2 * b * x * m1y + c * m1y * m1y - d;

         if (wykobi::greater_than_or_equal(sigma,T(0)))
         {
            dx -= c;
            dy += b;
            y = m1y;
         }

         dx += b;
         dy -= a;
      }

      while (wykobi::greater_than_or_equal(y,ay))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         y--;

         sigma = a * x * x + 2 * b * x * y + c * y * y - d;

         if (sigma < T(0))
         {
            dx += b;
            dy -= a;
            x++;
         }

         dx -= c;
         dy += b;
      }
   }
   else
   {
      x = -ax;
      y = -ay;
      dx = -(b * ax + c * ay);
      dy = a * ax + b * ay;

      while (wykobi::greater_than_or_equal(-dx,dy))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         x--;
         p1y = y + 1;

         sigma = a * x * x + 2 * b * x * p1y + c * p1y * p1y - d;

         if (wykobi::greater_than_or_equal(sigma,T(0)))
         {
            dx += c;
            dy -= b;
            y = p1y;
         }

         dx -= b;
         dy += a;
      }

      while (wykobi::less_than_or_equal(dx,T(0)))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         y++;

         sigma = a * x * x + 2 * b * x * y + c * y * y - d;

         if (sigma < T(0))
         {
            dx -= b;
            dy += a;
            x--;
         }

         dx += c;
         dy -= b;
      }

      while (wykobi::less_than_or_equal(dx,dy))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         y++;
         p1x = x+1;

         sigma = a * p1x * p1x + 2 * b * p1x * y + c * y * y - d;

         if (wykobi::greater_than_or_equal(sigma,T(0)))
         {
            dx += b;
            dy -= a;
            x = p1x;
         }

         dx += c;
         dy -= b;
      }

      while (wykobi::greater_than_or_equal(dy,T(0)))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         x++;

         sigma = a * x * x + 2 * b * x * y + c * y * y - d;

         if (sigma < T(0))
         {
            dx += c;
            dy -= b;
            y++;
         }

         dx += b;
         dy -= a;
      }

      while (wykobi::less_than_or_equal(x,ax))
      {
         graphic.draw_pixel(wykobi::make_point<T>(cx + x,cy + y));
         graphic.draw_pixel(wykobi::make_point<T>(cx - x,cy - y));

         x++;
         m1y = y - 1;

         sigma = a * x * x + 2 * b * x * m1y + c * m1y * m1y - d;

         if (wykobi::greater_than_or_equal(sigma,T(0)))
         {
            dx -= c;
            dy += b;
            y = m1y;
         }

         dx += b;
         dy -= a;
      }
   }
}

#endif
