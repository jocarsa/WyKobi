/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.4                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2017 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational library and its components are supplied    *)
(* under the terms of the General Wykobi License agreement.            *)
(* The contents of the Wykobi computational library and its components *)
(* may not be copied or disclosed except in accordance with the terms  *)
(* of that agreement.                                                  *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/


#include "stdafx.h"
#include "WykobiGUIForm.h"

using namespace wykobi_demo_dot_net;

[STAThreadAttribute]
int main(array<System::String ^> ^/*args*/)
{
   // Enabling Windows XP visual effects before any controls are created
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   // Create the main window and run it
   Application::Run(gcnew WykobiGUIForm());
   return 0;
}
