#include "Database.h"


Database::Database(const char* filename){
    sqlite3 *database=NULL;
    const char *zErrMsg = 0;
    sqlite3_stmt *stmt=0;
	int rc=0;
	char *sql = (char *)"";
	open(filename);
}
bool Database::open(const char* filename) 
{
	rc = sqlite3_open(filename, &database);  
    if( rc )
	{
    	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
    	return false;
    }
    else
	{
    	fprintf(stderr, "Opened database successfully\n");
    	return true;
    }
}

void Database::createTable(string nome,int operation){
	if (operation==0){
	const char* data = "creating table";
	std::ostringstream os;
	os<<"CREATE TABLE '"<<nome<<"'( ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, WEIGHT REAL NOT NULL, HEIGHT REAL NOT NULL, IMC REAL NOT NULL, DATE TEXT UNIQUE );";//TESTING THE UNIQUE FEATURE ON DATE
	string statement(os.str());
	rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);    
   if( rc != SQLITE_OK ){    
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		printf("error number: %i check the meaning on sqlite documents.\n",rc);
   		sqlite3_free(zErrMsg);    
   }
   else{       
   		fprintf(stdout, "Table data created successfully\n");    
   }
	}
	else{
   	const char* data = "creating table users";
	std::ostringstream os;
	os<<"CREATE TABLE USERS( NAME PRIMARY KEY TEXT UNIQUE NOT NULL, DATE TEXT );"; //IT IS UNIQUE, BUT NOT ON ALFABETICAL ORDER. CHANGE FOR DATE AND NAME.
	string statement(os.str());
	rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);    
   if( rc != SQLITE_OK ){    
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		printf("error number: %i check the meaning on sqlite documents.\n",rc);
   		sqlite3_free(zErrMsg);    
   }
   else{       
   		fprintf(stdout, "Table users created successfully\n");    
   }   
}
}
void Database::deleteTable(string tableName){
	const char* data = "Deleting Table";
	std::ostringstream os;
	os<<"DROP TABLE main.'"<<tableName<<"';";
	string statement(os.str());
   rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);    
   if( rc != SQLITE_OK ){    
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		printf("error number: %i check the meaning on sqlite documents.\n",rc);
   		sqlite3_free(zErrMsg);    
   }
   else{       
   		fprintf(stdout, "Table deleted successfully\n");    
   }
}
void Database::getTableData(string tableName){
	const char* data = "REATREAVING INFORMATION";
	/* Create SQL statement */
	std::ostringstream os;
	os<<"SELECT * from '"<<tableName<<"';";
	string statement(os.str());
    /* Execute SQL statement */
    rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
    	fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	printf("error number: %i check the meaning on sqlite documents.\n",rc);
    	sqlite3_free(zErrMsg);
    }
	else{
    	fprintf(stdout, "Operation done successfully\n");
    }
}
void Database::addDataRow(int id,string nome,float peso,float alt,float imc){
	const char* data = "Adding data";
	/* Create SQL statement */
	std::ostringstream os;
	os<<"INSERT INTO '"<<nome<<"' ( NAME, WEIGHT, HEIGHT, IMC, DATE) VALUES ( '"<<nome<<"', "<<peso<<", "<<alt<<", "<<imc<<", date('now'));";
	string statement(os.str());
 	/* Execute SQL statement */    
   	rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);    
   	if( rc != SQLITE_OK ){       
   		fprintf(stderr, "SQL error: %s\n", zErrMsg);
   		printf("error number: %i check the meaning on sqlite documents.\n",rc);
   		sqlite3_free(zErrMsg);
   	}
	else{       
   		fprintf(stdout, "Records saved successfully\n");    
   	}   
}

void Database::addUsersData(string nome){
	const char* data = "Adding data";
	/* Create SQL statement */
	std::ostringstream os;
	os<<"INSERT INTO USERS (NAME) VALUES ( '"<<nome<<"', date('now'));";
	string statement(os.str());
 	/* Execute SQL statement */    
   	rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);    
   	if( rc != SQLITE_OK ){       
   		fprintf(stderr, "SQL error: %s\n", zErrMsg);
   		printf("error number: %i check the meaning on sqlite documents.\n",rc);
   		sqlite3_free(zErrMsg);
   	}
	else{       
   		fprintf(stdout, "Records saved successfully\n");    
   	}   
}

void Database::deleteDataRow(string tableName,int id){
	const char* data = "Deleting Data";
	/* Create merged SQL statement */
	std::ostringstream os;
	os<<"DELETE from '"<<tableName<<"' where ID="<<id<<";";
	string statement(os.str());
    /* Execute SQL statement */
    rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
    	fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	printf("error number: %i check the meaning on sqlite documents.\n",rc);
    	sqlite3_free(zErrMsg);
	}
    else{
    	fprintf(stdout, "Operation done successfully\n");
    }
}
void Database::updateDataRow(string tableName){
	const char* data = "Updating Data";
	/* Create merged SQL statement */
	std::ostringstream os;
	os<<"UPDATE '"<<tableName<<"' set SALARY = 25000.00 where ID=1; ";
	string statement(os.str());
    /* Execute SQL statement */
    rc = sqlite3_exec(database, statement.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
    	fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	printf("error number: %i check the meaning on sqlite documents.\n",rc);
    	sqlite3_free(zErrMsg);
    }
    else{
    	fprintf(stdout, "Operation done successfully\n");    
    }
}
void Database::close(){
	sqlite3_close(database);
}
Database::~Database(){ 
}

