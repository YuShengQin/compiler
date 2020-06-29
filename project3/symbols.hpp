#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum type{
  intType,
  realType,
  boolType,
  charType,
  strType,
  arrayType,
  voidType,
};

enum idFlag {
  constValueFlag,
  constVariableFlag,
  variableFlag,
  functionFlag
};

class idInfo;

class idValue {
	public:
	  int ival = 0;
	  double dval = 0;
	  bool bval = false;
	  char cval = '\0';
	  string sval = "";
	  vector<idInfo> aval;
};

class idInfo {
	public:
	  int index = 0;
	  string id = "";
	  int type = intType;
 	  int flag = variableFlag;
	  idValue value;
	  bool init = false;
};

class SymbolTable {
  private:
    vector<string> symbols;
    map<string, idInfo> table_map;
    int index;
  public:
    SymbolTable();
    int insert(string id, int type, int flag, idValue value, bool init);
    idInfo *lookup(string id);
    void dump();
	int size();
    bool isExist(string id);
	void setFuncType(int type);
    void addFuncArg(string id, idInfo info);
	int getIndex(string id);
};

class SymbolTableList {
  private:
    vector<SymbolTable> list;
    int top;
  public:
    SymbolTableList();
    void push();
    bool pop();
    int insert(string id, idInfo info);
    int insert(string id, int type, int size);
    idInfo *lookup(string id);
    void dump();
    void setFuncType(int type);
    void addFuncArg(string id, idInfo info);
	int getIndex(string id);
	bool isGlobal();
};

/* utilities */

bool isConst(idInfo info);
idInfo *intConst(int val);
idInfo *floatConst(double val);
idInfo *boolConst(bool val);
idInfo *strConst(string *val);
idInfo* charConst(char val);
int getValue(idInfo info);
