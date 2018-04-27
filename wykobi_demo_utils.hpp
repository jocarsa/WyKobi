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


#ifndef INCLUDE_WYKOBI_DEMO_UTILS_HPP
#define INCLUDE_WYKOBI_DEMO_UTILS_HPP


#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"


void randomize()
{
   srand((unsigned)time(NULL));
}

template<typename T>
void generate_polygon_type1(const T& width, const T& height, wykobi::polygon<T,2>& polygon)
{
   wykobi::circle<T> circle = wykobi::make_circle<T>
                              (
                                width / T(2), height / T(2),
                                wykobi::min<T>(T(1) * width, T(1) * height) * T(0.5) - T(20)
                              );

   polygon = wykobi::make_polygon<T>(circle,180);

   for (std::size_t i = 0; i < polygon.size(); ++i)
   {
      if ((i % 3) == 0)
      {
         polygon[i] = wykobi::project_point
                      (
                        polygon[i],
                        wykobi::make_point<T>(width / T(2), height / T(2)), circle.radius / T(2)
                      );
      }
   }
}

template<typename T>
void generate_polygon_type2(const T& width, const T& height, wykobi::polygon<T,2>& polygon)
{
   wykobi::circle<T> circle =  wykobi::make_circle<T>
                               (
                                 width  * T(0.5), height * T(0.5),
                                 wykobi::min<T>(width,height) * T(0.5) - T(20)
                               );

   polygon = wykobi::make_polygon<T>(circle,100);

   wykobi::point2d<T> center_point = wykobi::make_point<T>(circle);

   for (std::size_t i = 0; i < polygon.size(); ++i)
   {
      wykobi::vector2d<T> v = normalize(polygon[i] - center_point) * wykobi::generate_random_value<T>(circle.radius * T(0.75));

      polygon[i] = polygon[i] - v;
   }
}

template<typename T, typename OutputIterator>
void generate_random_segments(const T& x1, const T& y1,
                              const T& x2, const T& y2,
                              const std::size_t& segment_count,
                              OutputIterator out)
{
   for (std::size_t i = 0; i < segment_count; i++, ++out)
   {
      wykobi::segment<T,2> tmp_segment;

      generate_random_object(x1,y1,x2,y2,tmp_segment);

      out = tmp_segment;
   }
}

#endif
