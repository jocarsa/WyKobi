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


#pragma once


#include <vector>

#include "wykobi.hpp"
#include "wykobi_graphics_net.hpp"
#include "wykobi_demo_bezier_int.hpp"
#include "wykobi_demo_circletangents.hpp"
#include "wykobi_demo_clipping.hpp"
#include "wykobi_demo_closest.hpp"
#include "wykobi_demo_convex_hull.hpp"
#include "wykobi_demo_hull_expander.hpp"
#include "wykobi_demo_intersections.hpp"
#include "wykobi_demo_minball.hpp"
#include "wykobi_demo_polytri.hpp"
#include "wykobi_demo_randomize.hpp"
#include "wykobi_demo_splines.hpp"
#include "wykobi_demo_torri.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


typedef wykobi::wykobi_graphics_net<double> Graphic;
std::vector< task_interface<double,Graphic>* > function_list;


namespace wykobi_demo_dot_net
{

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   public ref class WykobiGUIForm : public System::Windows::Forms::Form
   {
   public:

      WykobiGUIForm(void)
      {
         InitializeComponent();
         initialize_functions<double,Graphic>();
      }

   protected:

      ~WykobiGUIForm()
      {
         if (components)
         {
            delete components;
         }

         for(std::size_t i = 0; i < function_list.size(); ++i)
         {
            delete function_list[i];
         }
      }

   protected:

   private: System::Windows::Forms::Panel^        control_panel_;
   private: System::Windows::Forms::Panel^        paint_panel_;
   private: System::Windows::Forms::Button^       execute_button_;
   private: System::Windows::Forms::StatusStrip^  statusStrip1;
   private: System::Windows::Forms::ToolStripStatusLabel^  current_exec_;
   private: System::Windows::Forms::Label^        task_label_;
   private: System::Windows::Forms::ComboBox^     comboBox1;
   private: System::Windows::Forms::CheckBox^     repeat_checkbox_;
   private: System::Windows::Forms::Timer^        timer_;
   private: System::ComponentModel::IContainer^   components;

   private:

#pragma region Windows Form Designer generated code

      void InitializeComponent(void)
      {
         this->components = (gcnew System::ComponentModel::Container());
         this->control_panel_ = (gcnew System::Windows::Forms::Panel());
         this->repeat_checkbox_ = (gcnew System::Windows::Forms::CheckBox());
         this->task_label_ = (gcnew System::Windows::Forms::Label());
         this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
         this->execute_button_ = (gcnew System::Windows::Forms::Button());
         this->paint_panel_ = (gcnew System::Windows::Forms::Panel());
         this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
         this->current_exec_ = (gcnew System::Windows::Forms::ToolStripStatusLabel());
         this->timer_ = (gcnew System::Windows::Forms::Timer(this->components));
         this->control_panel_->SuspendLayout();
         this->statusStrip1->SuspendLayout();
         this->SuspendLayout();
         //
         // control_panel_
         //
         this->control_panel_->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
         this->control_panel_->Controls->Add(this->repeat_checkbox_);
         this->control_panel_->Controls->Add(this->task_label_);
         this->control_panel_->Controls->Add(this->comboBox1);
         this->control_panel_->Controls->Add(this->execute_button_);
         this->control_panel_->Location = System::Drawing::Point(0, 658);
         this->control_panel_->MinimumSize = System::Drawing::Size(480, 30);
         this->control_panel_->Name = L"control_panel_";
         this->control_panel_->Size = System::Drawing::Size(742, 33);
         this->control_panel_->TabIndex = 6;
         //
         // repeat_checkbox_
         //
         this->repeat_checkbox_->AutoSize = true;
         this->repeat_checkbox_->Location = System::Drawing::Point(361, 7);
         this->repeat_checkbox_->Name = L"repeat_checkbox_";
         this->repeat_checkbox_->Size = System::Drawing::Size(111, 17);
         this->repeat_checkbox_->TabIndex = 4;
         this->repeat_checkbox_->Text = L"Continous Repeat";
         this->repeat_checkbox_->UseVisualStyleBackColor = true;
         this->repeat_checkbox_->CheckedChanged += gcnew System::EventHandler(this, &WykobiGUIForm::repeat_checkbox__CheckedChanged);
         //
         // task_label_
         //
         this->task_label_->AutoSize = true;
         this->task_label_->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->task_label_->Location = System::Drawing::Point(3, 8);
         this->task_label_->Name = L"task_label_";
         this->task_label_->Size = System::Drawing::Size(34, 15);
         this->task_label_->TabIndex = 3;
         this->task_label_->Text = L"Task";
         //
         // comboBox1
         //
         this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->comboBox1->FormattingEnabled = true;
         this->comboBox1->Location = System::Drawing::Point(43, 5);
         this->comboBox1->Name = L"comboBox1";
         this->comboBox1->Size = System::Drawing::Size(231, 21);
         this->comboBox1->TabIndex = 2;
         this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &WykobiGUIForm::comboBox1_SelectedIndexChanged);
         //
         // execute_button_
         //
         this->execute_button_->Location = System::Drawing::Point(280, 3);
         this->execute_button_->Name = L"execute_button_";
         this->execute_button_->Size = System::Drawing::Size(75, 23);
         this->execute_button_->TabIndex = 1;
         this->execute_button_->Text = L"Execute";
         this->execute_button_->UseVisualStyleBackColor = true;
         this->execute_button_->Click += gcnew System::EventHandler(this, &WykobiGUIForm::execute_button__Click);
         //
         // paint_panel_
         //
         this->paint_panel_->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
         this->paint_panel_->Location = System::Drawing::Point(0, 0);
         this->paint_panel_->MinimumSize = System::Drawing::Size(300, 30);
         this->paint_panel_->Name = L"paint_panel_";
         this->paint_panel_->Size = System::Drawing::Size(742, 652);
         this->paint_panel_->TabIndex = 5;
         this->paint_panel_->Resize += gcnew System::EventHandler(this, &WykobiGUIForm::paint_panel__Resize);
         this->paint_panel_->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WykobiGUIForm::paint_panel__Paint);
         //
         // statusStrip1
         //
         this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->current_exec_});
         this->statusStrip1->Location = System::Drawing::Point(0, 694);
         this->statusStrip1->Name = L"statusStrip1";
         this->statusStrip1->Size = System::Drawing::Size(742, 22);
         this->statusStrip1->TabIndex = 7;
         this->statusStrip1->Text = L"statusStrip1";
         //
         // current_exec_
         //
         this->current_exec_->Name = L"current_exec_";
         this->current_exec_->Size = System::Drawing::Size(0, 17);
         //
         // timer_
         //
         this->timer_->Interval = 1;
         this->timer_->Tick += gcnew System::EventHandler(this, &WykobiGUIForm::timer__Tick);
         //
         // WykobiGUIForm
         //
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(742, 716);
         this->Controls->Add(this->statusStrip1);
         this->Controls->Add(this->control_panel_);
         this->Controls->Add(this->paint_panel_);
         this->MinimumSize = System::Drawing::Size(310, 100);
         this->Name = L"WykobiGUIForm";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Wykobi .NET Graphical Demo (www.wykobi.com)";
         this->control_panel_->ResumeLayout(false);
         this->control_panel_->PerformLayout();
         this->statusStrip1->ResumeLayout(false);
         this->statusStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

   private:

      template<typename T,typename Graphic>
      void initialize_functions()
      {
         function_list.clear();

         function_list.push_back(new convex_hull_graham_scan              <T,Graphic>());
         function_list.push_back(new convex_hull_jarvis_march             <T,Graphic>());
         function_list.push_back(new convex_hull_melkman                  <T,Graphic>());
         function_list.push_back(new segment_intersect                    <T,Graphic>());
         function_list.push_back(new circle_intersect                     <T,Graphic>());
         function_list.push_back(new minimum_bounding_ball                <T,Graphic>());
         function_list.push_back(new random_points_AABB                   <T,Graphic>());
         function_list.push_back(new random_points_triangle               <T,Graphic>());
         function_list.push_back(new random_points_quadix                 <T,Graphic>());
         function_list.push_back(new random_points_circle                 <T,Graphic>());
         function_list.push_back(new random_cubic_bezier                  <T,Graphic>());
         function_list.push_back(new random_quadratic_bezier              <T,Graphic>());
         function_list.push_back(new rectangle_clipper                    <T,Graphic>());
         function_list.push_back(new triangle_clipper                     <T,Graphic>());
         function_list.push_back(new quadix_clipper                       <T,Graphic>());
         function_list.push_back(new circle_clipper                       <T,Graphic>());
         function_list.push_back(new rectangle_to_rectangle_clipper       <T,Graphic>());
         function_list.push_back(new polygon_rectangle_clipper            <T,Graphic>());
         function_list.push_back(new polygon_triangle_clipper             <T,Graphic>());
         function_list.push_back(new polygon_quadix_clipper               <T,Graphic>());
         function_list.push_back(new polygon_polygon_clipper              <T,Graphic>());
         function_list.push_back(new quadratic_bezier_intersect           <T,Graphic>());
         function_list.push_back(new cubic_bezier_intersect               <T,Graphic>());
         function_list.push_back(new polygon_triangulation                <T,Graphic>());
         function_list.push_back(new torricelli_point                     <T,Graphic>());
         function_list.push_back(new trilateration                        <T,Graphic>());
         function_list.push_back(new closest_point_on_segment             <T,Graphic>());
         function_list.push_back(new closest_point_on_triangle            <T,Graphic>());
         function_list.push_back(new closest_point_on_rectangle           <T,Graphic>());
         function_list.push_back(new closest_point_on_circle              <T,Graphic>());
         function_list.push_back(new closest_point_on_quadix              <T,Graphic>());
         function_list.push_back(new closest_point_on_polygon             <T,Graphic>());
         function_list.push_back(new closest_point_on_quadratic_bezier    <T,Graphic>());
         function_list.push_back(new closest_point_on_cubic_bezier        <T,Graphic>());
         function_list.push_back(new closest_point_between_circles        <T,Graphic>());
         function_list.push_back(new closest_points_between_segment_circle<T,Graphic>());
         function_list.push_back(new random_orietnted_ellipses            <T,Graphic>());
         function_list.push_back(new circle_inner_tangents                <T,Graphic>());
         function_list.push_back(new circle_outer_tangents                <T,Graphic>());
         function_list.push_back(new circum_inscribed_circles             <T,Graphic>());
         function_list.push_back(new excentral_circle_triangle            <T,Graphic>());
         function_list.push_back(new circle_tangent_lines                 <T,Graphic>());

         for(std::size_t i = 0; i < function_list.size(); ++i)
         {
            comboBox1->Items->Add(gcnew System::String(function_list[i]->name().c_str()));
         }

         comboBox1->SelectedIndex = 0;

         randomize();
      }

   private:

      template<typename T,typename Graphic>
      void execute_task()
      {
         if (function_list.empty()) return;

         System::Drawing::Graphics^ graphics = paint_panel_->CreateGraphics();

         graphics->SmoothingMode = Drawing::Drawing2D::SmoothingMode::AntiAlias;

         Graphic gc(graphics,paint_panel_->Width,paint_panel_->Height);

         gc.clear();

         task_interface<T,Graphic>& task = *function_list[comboBox1->SelectedIndex];

         current_exec_->Text = gcnew System::String(task.name().c_str());

         this->Update();

         task(gc);
      }

   private:
      System::Void execute_button__Click(System::Object^  /*sender*/, System::EventArgs^  /*e*/)
      {
         execute_task<double,Graphic>();
      }

    private:
       System::Void paint_panel__Paint(System::Object^  /*sender*/, System::Windows::Forms::PaintEventArgs^  /*e*/)
       {
         execute_task<double,Graphic>();
       }


    private:
       System::Void paint_panel__Resize(System::Object^  /*sender*/, System::EventArgs^  /*e*/)
       {
         execute_task<double,Graphic>();
       }

    private:
       System::Void repeat_checkbox__CheckedChanged(System::Object^  /*sender*/, System::EventArgs^  /*e*/)
       {
          timer_->Enabled = repeat_checkbox_->Checked;
       }

    private:
       System::Void timer__Tick(System::Object^  /*sender*/, System::EventArgs^  /*e*/)
       {
         this->Update();
         execute_task<double,Graphic>();
       }

    private:
       System::Void comboBox1_SelectedIndexChanged(System::Object^  /*sender*/, System::EventArgs^  /*e*/)
       {
         execute_task<double,Graphic>();
       }

   };
}
