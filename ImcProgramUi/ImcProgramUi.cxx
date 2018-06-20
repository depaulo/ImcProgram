// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "ImcProgramUi.h"

Fl_Menu_Item MainWindow::menu_[] = {
 {"FILE", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 57},
 {"MANAGE USERS TABLE", 0,  (Fl_Callback*)Menu_cb, (void*)(MANAGE), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"SAVE DATA", 0,  (Fl_Callback*)Menu_cb, (void*)(SAVE), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"QUIT", 0,  (Fl_Callback*)Menu_cb, (void*)(QUIT), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"HELP", 0,  (Fl_Callback*)Menu_cb, (void*)(HELP), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

void MainWindow::hide() {
  mainwindow->hide();
}

void MainWindow::show() {
  mainwindow->show();
}

Fl_Double_Window* MainWindow::make() {
  { mainwindow = new Fl_Double_Window(755, 550, "Imc Program");
    mainwindow->tooltip("Program for you to check your body Imc.");
    mainwindow->box(FL_UP_BOX);
    mainwindow->labelsize(150);
    mainwindow->callback((Fl_Callback*)WinQuit_cb, (void*)(this));
    mainwindow->align(Fl_Align(FL_ALIGN_TOP_RIGHT));
    { Name = new Fl_Input(230, 136, 130, 24, "Name:");
    } // Fl_Input* Name
    { Weight = new Fl_Value_Input(120, 202, 125, 28, "Weight:");
    } // Fl_Value_Input* Weight
    { Height = new Fl_Value_Input(325, 202, 120, 28, "Height:");
    } // Fl_Value_Input* Height
    { Display = new Fl_Text_Display(45, 270, 580, 145);
      buff = new Fl_Text_Buffer;
      Display->buffer(buff);
    } // Fl_Text_Display* Display
    { Enter = new Fl_Return_Button(580, 484, 145, 55, "Next");
      Enter->selection_color((Fl_Color)36);
      Enter->labeltype(FL_SHADOW_LABEL);
      Enter->labelsize(30);
      Enter->callback((Fl_Callback*)Button_cb, (void*)("next"));
    } // Fl_Return_Button* Enter
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 752, 21);
      o->down_box(FL_DOWN_BOX);
      o->selection_color((Fl_Color)180);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    mainwindow->end();
    mainwindow->resizable(mainwindow);
  } // Fl_Double_Window* mainwindow
  mainwindow->show();
  return mainwindow;
}

void WindowTables::hide() {
  tableswindow->hide();
}

void WindowTables::show() {
  tableswindow->show();
}

void WindowTables::label(const char* label) {
  tableswindow->label(label);
}

Fl_Double_Window* WindowTables::make() {
  { tableswindow = new Fl_Double_Window(755, 410);
    tableswindow->user_data((void*)(this));
    { CreateTable = new Fl_Button(35, 290, 150, 30, "CREATE NEW TABLE");
      CreateTable->callback((Fl_Callback*)Buttons_cb, (void*)(CREATE_TABLE));
    } // Fl_Button* CreateTable
    { DeleteTable = new Fl_Button(35, 345, 150, 30, "DELETE TABLE");
      DeleteTable->callback((Fl_Callback*)Buttons_cb, (void*)(DELETE_TABLE));
    } // Fl_Button* DeleteTable
    { OpenTable = new Fl_Button(35, 235, 150, 30, "OPEN TABLE");
      OpenTable->callback((Fl_Callback*)Buttons_cb, (void*)(OPEN_TABLE));
    } // Fl_Button* OpenTable
    { Ok = new Fl_Return_Button(565, 275, 150, 50, "OK");
      Ok->callback((Fl_Callback*)Ok_cb, (void*)(OK1));
    } // Fl_Return_Button* Ok
    { Number = new Fl_Value_Input(295, 280, 185, 25);
      Number->hide();
    } // Fl_Value_Input* Number
    { Text = new Fl_Input(280, 261, 185, 24);
    } // Fl_Input* Text
    { Display = new Fl_Text_Display(35, 15, 695, 205);
      buff = new Fl_Text_Buffer;
      Display->buffer(buff);
    } // Fl_Text_Display* Display
    tableswindow->end();
  } // Fl_Double_Window* tableswindow
  tableswindow->show();
  return tableswindow;
}

void WindowData::hide() {
  datawindow->hide();
}

void WindowData::show() {
  datawindow->show();
}

void WindowData::label(const char* label) {
  datawindow->label(label);
}

Fl_Double_Window* WindowData::make() {
  { datawindow = new Fl_Double_Window(755, 410);
    datawindow->user_data((void*)(this));
    { SaveData = new Fl_Button(35, 265, 150, 30, "SAVE DATA");
      SaveData->callback((Fl_Callback*)Buttons_cb, (void*)(SAVE_DATA));
    } // Fl_Button* SaveData
    { DeleteData = new Fl_Button(35, 320, 150, 30, "DELETE DATA");
      DeleteData->callback((Fl_Callback*)Buttons_cb, (void*)(DELETE_DATA));
    } // Fl_Button* DeleteData
    { Ok = new Fl_Return_Button(565, 275, 150, 50, "OK");
      Ok->callback((Fl_Callback*)Ok_cb, (void*)(OK2));
    } // Fl_Return_Button* Ok
    { Number = new Fl_Value_Input(295, 305, 185, 25);
    } // Fl_Value_Input* Number
    { Display = new Fl_Text_Display(35, 15, 695, 205);
      buff = new Fl_Text_Buffer;
      Display->buffer(buff);
    } // Fl_Text_Display* Display
    datawindow->end();
  } // Fl_Double_Window* datawindow
  datawindow->show();
  return datawindow;
}