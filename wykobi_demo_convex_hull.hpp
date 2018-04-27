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


#ifndef INCLUDE_WYKOBI_DEMO_CONVEX_HULL_HPP
#define INCLUDE_WYKOBI_DEMO_CONVEX_HULL_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


template<typename T, typename Graphic>
class convex_hull_graham_scan : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const static std::size_t max_points = 1000;

      graphic.clear(clWhite);

      wykobi::quadix<T,2> quadix;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(), quadix
      );

      std::vector< wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points(quadix, max_points, std::back_inserter(point));

      graphic.set_color(clBlack);
      graphic.draw(point.begin(),point.end());

      std::vector< wykobi::point2d<T> > convex_hull;
      convex_hull.reserve(max_points);

      wykobi::algorithm::convex_hull_graham_scan< wykobi::point2d<T> >
                         (
                           point.begin(), point.end(),
                           std::back_inserter(convex_hull)
                         );

      wykobi::polygon<T,2> convex_hull_polygon = wykobi::make_polygon<T>(convex_hull);

      graphic.set_color(clRed);
      graphic.set_pen_width(2);
      graphic.draw(convex_hull_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Convex Hull Graham Scan"; }
};

template<typename T, typename Graphic>
class convex_hull_jarvis_march : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const static std::size_t max_points = 1000;

      graphic.clear(clWhite);

      wykobi::quadix<T,2> quadix;

      wykobi::generate_random_object<T>
      (T(0), T(0), graphic.width(), graphic.height(), quadix);

      std::vector< wykobi::point2d<T> > point;
      point.reserve(max_points);

      wykobi::generate_random_points(quadix, max_points, std::back_inserter(point));

      graphic.set_color(clBlack);
      graphic.draw(point.begin(),point.end());

      std::vector< wykobi::point2d<T> > convex_hull;
      convex_hull.reserve(max_points);

      wykobi::algorithm::convex_hull_jarvis_march< wykobi::point2d<T> >
                         (point.begin(), point.end(), std::back_inserter(convex_hull));

      wykobi::polygon<T,2> convex_hull_polygon = wykobi::make_polygon<T>(convex_hull);

      graphic.set_color(clRed);
      graphic.set_pen_width(2);
      graphic.draw(convex_hull_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Convex Hull Jarvis March"; }
};

template<typename T, typename Graphic>
class convex_hull_melkman : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const static std::size_t max_points = 1000;
      wykobi::polygon<T,2> polygon;
      generate_polygon_type2<T>(graphic.width(), graphic.height(), polygon);

      polygon = wykobi::rotate
                        (
                          wykobi::generate_random_value<T>(T(90)),
                          polygon,
                          wykobi::make_point(graphic.width() / T(2), graphic.height() / T(2))
                        );

      graphic.clear(clWhite);
      graphic.set_color(clBlack);

      graphic.draw(polygon);

      std::vector< wykobi::point2d<T> > convex_hull;
      convex_hull.reserve(max_points);

      wykobi::algorithm::convex_hull_melkman< wykobi::point2d<T> >
                         (polygon.begin(), polygon.end(), std::back_inserter(convex_hull));

      wykobi::polygon<T,2> convex_hull_polygon = wykobi::make_polygon<T>(convex_hull);

      graphic.set_color(clRed);
      graphic.set_pen_width(2);
      graphic.draw(convex_hull_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Convex Hull Melkman"; }
};

#endif
