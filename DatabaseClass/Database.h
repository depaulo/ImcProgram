#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <sqlite3.h>
using std::string;

static int callback(void *data, int argc, char **argv, char **azColName);

class Database 
{
public:
	Database(const char* filename);
    bool open(const char* filename);
    void getDatabaseData();
	void createTable(string nome,int operation);
	void deleteTable(string tableName);
	void getTableData(string tableName);
	void addDataRow(int id,string nome,float peso,float alt,float imc);
	void addUsersData(string nome);
	void deleteDataRow(string tableName,int id);
    void updateDataRow(string tableName);
    void close();
    ~Database();
private:
    sqlite3 *database;
    char *zErrMsg;
    sqlite3_stmt * stmt;
	int rc;
	char *sql;
	const char* data;
};
#endif
/*
Descritivo database functions to implementate (Primeiras funçoes).
-Quando clicar em manage users, mostrar o conteudo da table users
-Quando clicar em crear database, criar a tabela com o nome do user e adicionar o nome na tabale users.
-Apos clicar no okay dentro do manage, pegar o numero do usuario que quer abrir  e abrir na tabala data
-Quando clicar no save data, tentar salvar e depois abrir a tabela com o nome do pessoa, caso não tenha, abrir o manage e avisar que nao existe o usuario solicitado.
*/