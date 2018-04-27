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


#ifndef INCLUDE_WYKOBI_DEMO_BEZIER_INT_HPP
#define INCLUDE_WYKOBI_DEMO_BEZIER_INT_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_demo_types.hpp"


template<typename T, typename Graphic>
class quadratic_bezier_intersect : public task_interface<T,Graphic>
{
public:

   virtual void operator()(const Graphic& graphic)
   {
      const std::size_t bezier_count = 20;

      std::vector< wykobi::quadratic_bezier<T,2> > bezier_list;
      std::vector< wykobi::segment<T,2> > segment_list;

      graphic.clear(clWhite);

      for (std::size_t i = 0; i < bezier_count; ++i)
      {
         wykobi::quadratic_bezier<T,2> bezier;
         bezier[0] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[1] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[2] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier_list.push_back(bezier);
      }

      for (std::size_t i = 0; i < bezier_count; ++i)
      {
         wykobi::segment<T,2> segment;
         wykobi::generate_random_object<T>(0.0,0.0,graphic.width(), graphic.height(),segment);
         segment_list.push_back(segment);
      }

      for (std::size_t i = 0; i < bezier_list.size(); ++i)
      {
         graphic.set_color(i % 15);
         graphic.draw(bezier_list[i],1500);
      }

      for (std::size_t i = 0; i < segment_list.size(); ++i)
      {
         graphic.set_color(clBlue);
         graphic.set_pen_width(2);
         graphic.draw(segment_list[i]);
         graphic.set_pen_width(1);
      }

      std::vector< wykobi::point2d<T> > ipoint_list;

      for (std::size_t i = 0; i < bezier_list.size(); ++i)
      {
         for (std::size_t j = 0; j < segment_list.size(); ++j)
         {
            wykobi::intersection_point(segment_list[j],bezier_list[i],std::back_inserter(ipoint_list));
         }
      }

      graphic.set_color(clRed);

      for (std::size_t i = 0; i < ipoint_list.size(); ++i)
      {
         graphic.draw(wykobi::make_circle<T>(ipoint_list[i],5));
      }
   }

   std::string name() { return "Quadratic Splines To Segment Intersects"; }
};


template<typename T, typename Graphic>
class cubic_bezier_intersect : public task_interface<T,Graphic>
{
public:

   virtual void operator()(const Graphic& graphic)
   {
      const std::size_t bezier_count = 20;

      std::vector< wykobi::cubic_bezier<T,2> > bezier_list;
      std::vector< wykobi::segment<T,2> > segment_list;

      graphic.clear(clWhite);

      for (std::size_t i = 0; i < bezier_count; ++i)
      {
         wykobi::cubic_bezier<T,2> bezier;
         bezier[0] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[1] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[2] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[3] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier_list.push_back(bezier);
      }

      for (std::size_t i = 0; i < bezier_count; ++i)
      {
         wykobi::segment<T,2> segment;
         wykobi::generate_random_object<T>(0.0,0.0,graphic.width(), graphic.height(),segment);
         segment_list.push_back(segment);
      }

      for (std::size_t i = 0; i < bezier_list.size(); ++i)
      {
         graphic.set_color(i % 15);
         graphic.draw(bezier_list[i],1500);
      }

      for (std::size_t i = 0; i < segment_list.size(); ++i)
      {
         graphic.set_color(clBlue);
         graphic.set_pen_width(2);
         graphic.draw(segment_list[i]);
         graphic.set_pen_width(1);
      }

      std::vector< wykobi::point2d<T> > ipoint_list;

      for (std::size_t i = 0; i < bezier_list.size(); ++i)
      {
         for (std::size_t j = 0; j < segment_list.size(); ++j)
         {
            wykobi::intersection_point(segment_list[j],bezier_list[i],std::back_inserter(ipoint_list));
         }
      }

      graphic.set_color(clRed);

      for (std::size_t i = 0; i < ipoint_list.size(); ++i)
      {
         graphic.draw(wykobi::make_circle<T>(ipoint_list[i],5));
      }
   }

   std::string name() { return "Cubic Splines To Segment Intersect"; }
};

#endif
