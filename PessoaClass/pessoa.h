#ifndef __PESSOA_H__
#define __PESSOA_H__

class Pessoa
{
private:
	float peso,alt,imc;
	const char* nome;
public:
	Pessoa();
	Pessoa(const char* s,float p, float a);
	void set_nome(const char* s);
	void set_peso(float p);
	void set_alt(float a);
	const char* get_nome();
	float get_alt();
	float get_peso();
	float get_imc();
	float calc_imc();
	~Pessoa();
};
#endif
