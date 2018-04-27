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


#ifndef INCLUDE_WYKOBI_DEMO_RANDOM_SPLINES_HPP
#define INCLUDE_WYKOBI_DEMO_RANDOM_SPLINES_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_demo_types.hpp"


namespace local
{
   const std::size_t bezier_count = 20;
}

template<typename T, typename Graphic>
class random_cubic_bezier : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      for (std::size_t i = 0; i < local::bezier_count; ++i)
      {
         wykobi::cubic_bezier<T,2> bezier;

         bezier[0] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[1] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[2] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[3] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());

         graphic.set_color(i % 15);
         graphic.draw(bezier,1500);
      }
   }

   std::string name() { return "Random Cubic Splines"; }
};

template<typename T, typename Graphic>
class random_quadratic_bezier : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      for (std::size_t i = 0; i < local::bezier_count; ++i)
      {
         wykobi::quadratic_bezier<T,2> bezier;

         bezier[0] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[1] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());
         bezier[2] = wykobi::generate_random_point<T>(graphic.width(), graphic.height());

         graphic.set_color(i % 15);
         graphic.draw(bezier,1500);
      }
   }

   std::string name() { return "Random Quadratic Splines"; }
};

#endif
