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


#ifndef INCLUDE_WYKOBI_DEMO_CLIPPING_HPP
#define INCLUDE_WYKOBI_DEMO_CLIPPING_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


namespace local
{
   const std::size_t max_segments = 50;
}

template<typename T, typename Graphic>
class rectangle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      std::vector<wykobi::segment<T,2> > segment_list;

      generate_random_segments<double>
      (
        T(0), T(0), graphic.width() - T(10), graphic.height() - T(10),
        local::max_segments,
        std::back_inserter(segment_list)
      );

      graphic.draw(segment_list.begin(),segment_list.end());

      wykobi::rectangle<T> rectangle;
      wykobi::generate_random_object<T>(T(0), T(0), graphic.width(), graphic.height(), rectangle);

      graphic.set_pen_width(3);
      graphic.draw(rectangle);
      graphic.set_pen_width(1);

      std::vector<wykobi::segment<T,2>> clipped_segment_list;

      for (std::size_t i = 0; i < local::max_segments; ++i)
      {
         wykobi::segment<T,2> clipped_segment;

         if (wykobi::clip(segment_list[i],rectangle,clipped_segment))
         {
            clipped_segment_list.push_back(clipped_segment);

            graphic.set_color(clLimeGreen);
            graphic.set_pen_width(2);
            graphic.draw(clipped_segment);
            graphic.set_color(clRed);
            graphic.set_pen_width(1);
            graphic.draw_circle(clipped_segment[0],3);
            graphic.draw_circle(clipped_segment[1],3);
            graphic.set_color(clBlack);
         }
      }
   }

   std::string name() { return "Segment Rectangle Clipping"; }
};


template<typename T, typename Graphic>
class triangle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      std::vector<wykobi::segment<T,2> > segment_list;

      generate_random_segments<double>
      (
        T(0), T(0), graphic.width() - T(10), graphic.height() - T(10),
        local::max_segments,
        std::back_inserter(segment_list)
      );

      graphic.draw(segment_list.begin(),segment_list.end());

      wykobi::triangle<T,2> triangle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        triangle
      );

      graphic.set_pen_width(3);
      graphic.draw(triangle);
      graphic.set_pen_width(1);

      for (std::size_t i = 0; i < local::max_segments; ++i)
      {
         wykobi::segment<T,2> clipped_segment;

         if (wykobi::clip(segment_list[i],triangle,clipped_segment))
         {
            graphic.set_color(clLimeGreen);
            graphic.draw(clipped_segment);
            graphic.set_color(clRed);
            graphic.draw_circle(clipped_segment[0],3);
            graphic.draw_circle(clipped_segment[1],3);
            graphic.set_color(clBlack);
         }
      }
   }

   std::string name() { return "Segment Triangle Clipping"; }
};


template<typename T, typename Graphic>
class quadix_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      std::vector<wykobi::segment<T,2> > segment;

      generate_random_segments<double>
      (
        T(0), T(0), graphic.width() - T(10), graphic.height() - T(10),
        local::max_segments,
        std::back_inserter(segment)
      );

      graphic.draw(segment.begin(),segment.end());

      wykobi::quadix<T,2> quadix;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(),
        quadix
      );

      graphic.set_pen_width(3);
      graphic.draw(quadix);
      graphic.set_pen_width(1);

      for (std::size_t i = 0; i < local::max_segments; ++i)
      {
         wykobi::segment<T,2> clipped_segment;

         if (wykobi::clip(segment[i],quadix,clipped_segment))
         {
            graphic.set_color(clLimeGreen);
            graphic.draw(clipped_segment);
            graphic.set_color(clRed);
            graphic.draw_circle(clipped_segment[0],3);
            graphic.draw_circle(clipped_segment[1],3);
            graphic.set_color(clBlack);
         }
      }
   }

   std::string name() { return "Segment Quadix Clipping"; }
};


template<typename T, typename Graphic>
class circle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);
      graphic.set_color(clBlack);

      std::vector<wykobi::segment<T,2> > segment_list;

      generate_random_segments<double>
      (
        T(0), T(0), graphic.width() - T(10), graphic.height() - T(10),
        local::max_segments,
        std::back_inserter(segment_list)
      );

      graphic.draw(segment_list.begin(),segment_list.end());

      wykobi::circle<T> circle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(),
        circle
      );

      graphic.set_pen_width(3);
      graphic.draw(circle);
      graphic.set_pen_width(1);

      for (std::size_t i = 0; i < local::max_segments; ++i)
      {
         wykobi::segment<T,2> clipped_segment;

         if (wykobi::clip(segment_list[i],circle,clipped_segment))
         {
            graphic.set_color(clLimeGreen);
            graphic.draw(clipped_segment);
            graphic.set_color(clRed);
            graphic.draw_circle(clipped_segment[0],3.0);
            graphic.draw_circle(clipped_segment[1],3.0);
            graphic.set_color(clBlack);
         }
      }
   }

   std::string name() { return "Segment Circle Clipping"; }
};


template<typename T, typename Graphic>
class rectangle_to_rectangle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const unsigned int max_rectangles = 20;

      graphic.clear(clWhite);
      graphic.set_color(clBlack);

      wykobi::rectangle<T> clip_rectangle;

      wykobi::generate_random_object<T>
      (
        T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
        clip_rectangle
      );

      std::vector<wykobi::rectangle<T> > rect_list;

      for (std::size_t i = 0; i < max_rectangles; ++i)
      {
         wykobi::rectangle<T> tmp_rect;

         wykobi::generate_random_object<T>
         (
           T(5), T(5), graphic.width() - T(5), graphic.height() - T(5),
           tmp_rect
         );

         rect_list.push_back(tmp_rect);
      }

      graphic.draw(rect_list.begin(),rect_list.end());
      graphic.set_pen_width(3);
      graphic.draw(clip_rectangle);

      wykobi::rectangle<T> clipped_rectangle;

      for (std::size_t i = 0; i < rect_list.size(); ++i)
      {
         if (wykobi::clip(rect_list[i],clip_rectangle,clipped_rectangle))
         {
            graphic.set_color(clLimeGreen);
            graphic.draw(clipped_rectangle);

            graphic.set_color(clRed);
            graphic.set_pen_width(1);

            graphic.draw_circle(clipped_rectangle[0],3.0);
            graphic.draw_circle(clipped_rectangle[1],3.0);

            graphic.draw_circle(wykobi::make_point(clipped_rectangle[0].x,clipped_rectangle[1].y),3.0);
            graphic.draw_circle(wykobi::make_point(clipped_rectangle[1].x,clipped_rectangle[0].y),3.0);
         }
      }
   }

   std::string name() { return "Rectangle To Rectangle Clipping"; }
};

template<typename T, typename Graphic>
class polygon_rectangle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      wykobi::rectangle<T> clip_boundry;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1),graphic.height() - T(1),
        clip_boundry
      );

      wykobi::polygon<T,2> polygon;

      generate_polygon_type2<T>(graphic.width(),graphic.height(),polygon);

      polygon = wykobi::rotate<T>
                (
                  wykobi::generate_random_value<T>(T(360)),
                  polygon,
                  wykobi::make_point<T>(graphic.width() / T(2),graphic.height() / T(2))
                );

      wykobi::polygon<T,2> clipped_polygon;

      wykobi::algorithm::sutherland_hodgman_polygon_clipper< wykobi::point2d<T> >
                         (clip_boundry, polygon, clipped_polygon);

      graphic.clear(clWhite);
      graphic.set_color(clLimeGreen);
      graphic.set_pen_width(3);
      graphic.draw(clip_boundry);
      graphic.set_pen_width(1);
      graphic.set_color(clBlack);
      graphic.draw(polygon);
      graphic.set_color(clRed);
      graphic.set_pen_width(3);
      graphic.draw(clipped_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Polygon Rectangle Clipping"; }
};


template<typename T, typename Graphic>
class polygon_triangle_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      wykobi::triangle<T,2> clip_boundry;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width() - T(1), graphic.height() - T(1),
        clip_boundry
      );

      wykobi::polygon<T,2> polygon;

      generate_polygon_type2<T>(graphic.width(),graphic.height(),polygon);

      polygon = wykobi::rotate<T>
                (
                  wykobi::generate_random_value<T>(T(360)),
                  polygon,
                  wykobi::make_point<T>(graphic.width() / T(2),graphic.height() / T(2))
                );

      wykobi::polygon<T,2> clipped_polygon;

      wykobi::algorithm::sutherland_hodgman_polygon_clipper< wykobi::point2d<T> >
                         (clip_boundry, polygon, clipped_polygon);

      graphic.clear(clWhite);
      graphic.set_color(clLimeGreen);
      graphic.set_pen_width(3);
      graphic.draw(clip_boundry);
      graphic.set_pen_width(1);
      graphic.set_color(clBlack);
      graphic.draw(polygon);
      graphic.set_color(clRed);
      graphic.set_pen_width(3);
      graphic.draw(clipped_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Polygon Triangle Clipping"; }
};


template<typename T, typename Graphic>
class polygon_quadix_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      wykobi::quadix<T,2> clip_boundry;

      wykobi::generate_random_object<T>
      (
        T(50), T(50), graphic.width() - T(50), graphic.height() - T(50),
        clip_boundry
      );

      wykobi::polygon<T,2> polygon;

      generate_polygon_type2<T>(graphic.width(), graphic.height(), polygon);

      polygon = wykobi::rotate<T>
                        (
                          wykobi::generate_random_value<T>(T(360.0)),
                          polygon,
                          wykobi::make_point<T>(graphic.width() / T(2),graphic.height() / T(2))
                        );

      wykobi::polygon<T,2> clipped_polygon;

      wykobi::algorithm::sutherland_hodgman_polygon_clipper< wykobi::point2d<T> >
                         (clip_boundry, polygon, clipped_polygon);

      graphic.clear(clWhite);
      graphic.set_color(clLimeGreen);
      graphic.set_pen_width(3);
      graphic.draw(clip_boundry);
      graphic.set_pen_width(1);
      graphic.set_color(clBlack);
      graphic.draw(polygon);
      graphic.set_color(clRed);
      graphic.set_pen_width(3);
      graphic.draw(clipped_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Polygon Quadix Clipping"; }
};


template<typename T, typename Graphic>
class polygon_polygon_clipper : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      wykobi::circle<T> circle;

      wykobi::generate_random_object<T>
      (
        T(0), T(0), graphic.width(), graphic.height(),
        circle
      );

      wykobi::polygon<T,2> clip_boundry = wykobi::make_polygon<T>(circle,12);

      wykobi::polygon<T,2> polygon;
      generate_polygon_type2<T>(graphic.width(),graphic.height(),polygon);

      polygon = wykobi::rotate<T>
                        (
                          wykobi::generate_random_value<T>(T(360)),
                          polygon,
                          wykobi::make_point<T>(graphic.width() / T(2),graphic.height() / T(2))
                        );

      wykobi::polygon<T,2> clipped_polygon;

      wykobi::algorithm::sutherland_hodgman_polygon_clipper< wykobi::point2d<T> >
                         (clip_boundry, polygon, clipped_polygon);

      graphic.clear(clWhite);
      graphic.set_color(clLimeGreen);
      graphic.set_pen_width(2);
      graphic.draw(clip_boundry);
      graphic.set_pen_width(1);
      graphic.set_color(clBlack);
      graphic.draw(polygon);
      graphic.set_color(clRed);
      graphic.set_pen_width(2);
      graphic.draw(clipped_polygon);
      graphic.set_pen_width(1);
   }

   std::string name() { return "Polygon Polygon Clipping"; }
};

#endif
