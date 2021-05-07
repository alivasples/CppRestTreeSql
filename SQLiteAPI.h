#ifndef SQLITE_API_H
#define SQLITE_API_H

#include "sqlite3.h"

/** Defining our API class for SQLite */
class SQLiteAPI{
	private: 
		// PRIVATE ATTRIBUTES
		string DBName;
		string TREE_TABLE;
		sqlite3 *db;

	public:
		// PUBLIC METHODS
		/** Default Constructor */
		SQLiteAPI(){ 
			DBName = "ExamDataBase.db"; 
			TREE_TABLE = "TreeTable";
			open();
		}
		
		/** Open or create the database */
		bool open(){
			int res = sqlite3_open(DBName.c_str(), &db);
			if(res){
				cout << "Database could not be opened;\n";
				sqlite3_close(db);
				return false;
			}
			else{
				char *error = 0;
				// SQL to create our tree table
				string sql = "CREATE TABLE IF NOT EXISTS " + TREE_TABLE +"("
					"`timestamp` DATETIME, "
					"`inorder` TEXT, "
					"`preorder` TEXT, "
					"`postorder` TEXT)";
				// Executing the SQL statement
				res = sqlite3_exec(db, sql.c_str(), NULL, 0, &error);
				if (res != SQLITE_OK)
				{
					cout << "Table couldn't be created\n";
					sqlite3_free(error);
					return false;
				}
	      	}
			return true;
		}

		/** Closing our database */
		void close(){
			sqlite3_close(db);
		}

		/** Insert a tree item into our table */
		bool insertInTree(string inOrder, string preOrder, string postOrder){
			char *error = 0;
			// SQL to execute the insertion
			string sql = "INSERT INTO " + TREE_TABLE + " VALUES (DATETIME(STRFTIME('%s','now'), 'unixepoch'), '"
				+ inOrder + "', '" + preOrder + "', '" + postOrder + "');";
			// Executing the SQL statement
			int res = sqlite3_exec(db, sql.c_str(), NULL, 0, &error);
			if (res != SQLITE_OK)
			{
				cout << "Element couldn't be inserted\n";
				sqlite3_free(error);
				return false;
			}
			return true;
		}

};

#endif // SQLITE_API_H