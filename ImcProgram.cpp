/*
Lembrar de sempre que refizer o fluid, apagar os asteriscos no header imcProgramUi.h
*/
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> //to use the exit code
#include "ImcProgramUi/ImcProgramUi.cxx"
#include "DatabaseClass/Database.cxx"
#include "PessoaClass/pessoa.cxx"
using std::string;

	Pessoa user; //creating user, need to add pessoa class.
	Database db("Database.sqlite"); //creating and opening the database.
	MainWindow window; 
	WindowTables tables; 
	WindowData data;
	string buffer="tables";

int main(int argc, char **argv)
{
	Fl::visual(FL_DOUBLE|FL_INDEX);
	string senha;
	senha=fl_password("Please type your password");//olhar nos exemplos ask.cpp
	if (senha==""){
		int hotspot = fl_message_hotspot();
		fl_message_hotspot(1);
		fl_message_hotspot(hotspot);
		fl_message("For now you are safe, I didnt set an password yet, enjoy the program.");
		}
	window.make();
	db.createTable("users",1);
	return (Fl::run()); 
	}

static int callback(void *datas, int argc, char **argv, char **azColName){
		if (buffer=="tables"){
			int i;
			tables.buff->append((const char*)datas);
		for(i=0; i<argc; i++){
			tables.buff->append("\n");
			tables.buff->append(azColName[i]);
			tables.buff->append(" \t\t: ");
			tables.buff->append(argv[i]);
		}
		tables.buff->append("\n\n");
	return 0;
	}
	else{
		int i;
		data.buff->append((const char*)datas);
		for(i=0; i<argc; i++){
			data.buff->append("\n");
			data.buff->append(azColName[i]);
			data.buff->append(" \t\t= ");
			data.buff->append(argv[i]);
		}
		data.buff->append("\n\n");
	return 0;
	}
}

void WinQuit_cb(Fl_Double_Window*,void* userdata) {
		int hotspot = fl_message_hotspot();
		fl_message_hotspot(1);
		fl_message_title("Quitting?");
		int rep = fl_choice("Are you sure you want to quit?","Cancel","Quit","Save");
		fl_message_hotspot(hotspot);
	if (rep==1){
		db.close();
		exit(0);
		}
	if (rep==2)
		fl_message("hmmm, didnt make this option yet, sorry )))).");
	}


void Menu_cb(Fl_Menu_*,menunames UserData) {
   switch(UserData)
  {
  	case MANAGE:
		tables.make();
		tables.label("List of tables");
		db.getTableData("users");
  	break;
	case SAVE:
		buffer="data";	
		data.make();
		db.getTableData(user.get_nome());
		data.label("User data");
		buffer="tables";
	break;
  	case QUIT:{
		fl_message_title("Quit?");
		int rep = fl_choice("Are you sure you want to quit?","Cancel","Yes, I want to quit","no, I don't want to quit");
		if (rep==1){
			db.close();
			exit(1);
	  }
	}
  	break;
  	case HELP:
	  fl_message("Well\nYou should enter your name, \nyour weight in kilos and your height (in meters or centimeters)\nand the program will tell you your bmi (body mass index).");
  	break;
  	default:
  		window.buff->text("There is no this menu yet, sorry. \nCheck again after.");
	break;
  }
}


void Buttons_cb(Fl_Button*,databasecontrols UserData){
  switch(UserData)
  {
	case OPEN_TABLE:
		db.getTableData(tables.Text->value());
		window.buff->append("TABLE OPENED");
	break;
  	case CREATE_TABLE:
		db.createTable(tables.Text->value(),0);
		db.addUsersData(tables.Text->value());
		window.buff->text("TABLE CREATED");
  	break;
	case DELETE_TABLE:
		db.deleteTable(tables.Text->value());
		window.buff->text("TABLE DELETED");
  	break;
  	case SAVE_DATA:
		db.addDataRow(data.Number->value(),user.get_nome(),user.get_peso(),user.get_alt(),user.get_imc());
		window.buff->text("DATA SAVED");
		buffer="data";
		db.getTableData(user.get_nome());
		buffer="tables";
	break;
	case DELETE_DATA:
		db.deleteDataRow(tables.Text->value(),tables.Number->value());
		window.buff->text("DATA DELETED");
  	break;
  	default:
	break;
  }
}


void Ok_cb(Fl_Return_Button*,databasecontrols UserData){
	switch(UserData){
	case OK1:
		tables.hide();
		data.make();
		buffer="data";
		db.getTableData(tables.Text->value());
		data.label("User data");
		buffer="tables";
  	break;
	case OK2:
  		data.hide();
  	break;
  	default:
	break;
	 }
}


void Button_cb(Fl_Return_Button*,void* userdata) {
		char imcChar[12];
		float pesoideal[2];
		char pesoidealtext[13];
		float imcNumber;
	if ((window.Height->value()<0.7)||((window.Height->value()>3)&&(window.Height->value()<70))||(window.Height->value()>300)){
   		window.buff->text("Your height was typed in a wrong way, type again ");
   	 return;
    }
		user.set_nome(window.Name->value());
		user.set_alt((float)window.Height->value());
		user.set_peso((float)window.Weight->value());
		imcNumber=user.calc_imc();
		pesoideal[0]=(float)18.6*(user.get_alt()*user.get_alt());
		pesoideal[1]=(float)24.9*(user.get_alt()*user.get_alt());
		_snprintf_s (imcChar,12,"%2.2f",imcNumber);
		_snprintf_s (pesoidealtext,13,"%2.1f, %2.1f",pesoideal[0],pesoideal[1]);
        if (imcNumber<18.6) {
               window.buff->text("Hello ");
			   window.buff->append(user.get_nome());
               window.buff->append(" Your IMC is ");
               window.buff->append(imcChar);
               window.buff->append(" Well, you are below the normal weight.\nYou should eat more, being below weight isnt health too.");
               window.buff->append("\nYour normal weight is between ");
               window.buff->append(pesoidealtext);
               }
           else if ((imcNumber>=18.6) && (imcNumber<=24.9)){
               window.buff->text("Hello ");
			   window.buff->append(user.get_nome());
               window.buff->append(" Your IMC is ");
               window.buff->append(imcChar);
               window.buff->append(" You are at the normal weight.\nCongratulaions!!!!! ");
               window.buff->append("\nYour normal weight is between ");
               window.buff->append(pesoidealtext);
                }
           else if ((imcNumber>=25) && (imcNumber<=29.9)){
               window.buff->text("Hello ");
			   window.buff->append(user.get_nome());
               window.buff->append(" Your IMC is ");
               window.buff->append(imcChar);
               window.buff->append(" You are above the normal weight.\n You should consider making a diet");
               window.buff->append("\nYour normal weight is between ");
               window.buff->append(pesoidealtext);
                }
           else {
               window.buff->text("Hello ");
			   window.buff->append(user.get_nome());
               window.buff->append(" Your IMC is ");
               window.buff->append(imcChar);
               window.buff->append(" DANGER, DANGER\nYou are really over weighted.\nYou should consider changing your life style and starting a diet.");
               window.buff->append("\nYour normal weight is between ");
               window.buff->append(pesoidealtext);
                }
}
