#include "pessoa.h"

Pessoa::Pessoa(){
	peso=70;
	alt=170;
	imc=22;
	nome="Average person";
}
Pessoa::Pessoa(const char* s,float p, float a){
	peso=p;
	alt=a;
	nome=s;
	imc=0;
}
void Pessoa::set_nome(const char* s){
	nome=s;
}
void Pessoa::set_peso(float p){
	peso=p;
}
void Pessoa::set_alt(float a){
	if ((a>70)&&(a<300))
	{
    alt=a/100;
	}
	else
	{
	alt=a;
	}
}
float Pessoa::calc_imc()
{
	imc=peso/(alt*alt);
	return imc;
}
const char* Pessoa::get_nome(){
	return nome;
}
float Pessoa::get_alt(){
	return alt;
}
float Pessoa::get_peso(){
	return peso;
}
float Pessoa::get_imc(){
	return imc;
}
Pessoa::~Pessoa(){ 
}

