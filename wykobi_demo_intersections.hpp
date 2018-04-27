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


#ifndef INCLUDE_WYKOBI_DEMO_INTERSECTIONS_HPP
#define INCLUDE_WYKOBI_DEMO_INTERSECTIONS_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


template<typename T, typename Graphic>
class segment_intersect : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_segments = 100;

      graphic.clear(clWhite);

      std::vector<wykobi::segment<T,2> > segment_list;

      generate_random_segments<double>
      (
        T(0), T(0), graphic.width() - T(10), graphic.height() - T(10),
        max_segments,
        std::back_inserter(segment_list)
      );

      graphic.draw(segment_list.begin(),segment_list.end());

      graphic.set_color(clRed);

      for (std::size_t i = 0; i < segment_list.size(); ++i)
      {
         for (std::size_t j = i + 1; j < segment_list.size(); ++j)
         {
            T ix = T(0);
            T iy = T(0);

            if (intersect(segment_list[i],segment_list[j],ix,iy))
            {
               graphic.draw_circle(ix,iy,T(3));
            }
         }
      }

      graphic.set_color(clBlack);
   }

   std::string name() { return "Random Segment Intersections"; }
};

template<typename T, typename Graphic>
class circle_intersect : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_circles = 100;

      graphic.clear(clWhite);
      std::vector<wykobi::circle<T> > circle;

      for (std::size_t i = 0; i < max_circles; ++i)
      {
         T radius = wykobi::generate_random_value<T>(50) + T(20);

         circle.push_back(wykobi::make_circle<T>
                                  (
                                    wykobi::generate_random_value<T>(graphic.width()  - (radius * 2.0)) + radius,
                                    wykobi::generate_random_value<T>(graphic.height() - (radius * 2.0)) + radius,
                                    radius
                                  ));
      }

      graphic.draw(circle.begin(),circle.end());
      graphic.set_color(clRed);

      for (std::size_t i = 0; i < circle.size(); ++i)
      {
         for (std::size_t j = i + 1; j < circle.size(); ++j)
         {
            if (
                 intersect(circle[i],circle[j]) &&
                 (wykobi::distance(circle[i].x,circle[i].y,circle[j].x,circle[j].y) >= std::abs(circle[i].radius - circle[j].radius))
               )
            {
               wykobi::point2d<T> i_pnt1;
               wykobi::point2d<T> i_pnt2;

               wykobi::intersection_point(circle[i],circle[j],i_pnt1,i_pnt2);

               graphic.draw_circle(i_pnt1,T(3.0));
               graphic.draw_circle(i_pnt2,T(3.0));
            }
         }
      }

      graphic.set_color(clBlack);
   }

   std::string name() { return "Random Circle Intersections"; }
};

#endif
