%{
	#define Trace(t)        if(isP==1)printf(t); if(isP==1) printf("\n")
	#include <iostream>
	#include <fstream>
	#include <stack>
	#include "lex.yy.cpp"
	#include "symbols.hpp"
	int isP = 0;
	bool havemain =false;
	void yyerror(const char *msg);
	void genCondOp(int op);
	SymbolTableList symbols;
	vector<vector<idInfo>> function;
	ofstream output;
	string filename;
	enum condition{
		IFLT,
		IFGT,
		IFLE,
		IFGE,
		IFEQ,
		IFNE
	};
	struct Label {
		int count;
		int loop_flag;
		Label(int num) {
			count = num;
			loop_flag = -1;
		}
	};
	
	class LabelControl{
		private:
			int labelcount;
		public:
			stack<Label> LabelStack;
			LabelControl() {
				labelcount = 0;
			}
			void pushLabelN(int n) {
				LabelStack.push(Label(labelcount));
				labelcount += n;	
			}
			void LabelN(int n) {
				LabelStack.top().count += n;
				labelcount +=n;
			}
			void popLabel() {
				LabelStack.pop();
			}
			int takeLabel(int n) {
				return LabelStack.top().count + n;
			}
			int getLabel() {
				return labelcount++;
			}
			int getFlag() {
				return LabelStack.top().loop_flag;
			}
	};
	LabelControl lc;
%}

/* yylval */
%union {
	int ival;
	double dval;
	char cval;
	bool bval;
	string *sval;
	class idInfo *info;
	int type;
}

/* tokens */
%token BOOLEAN BREAK CHAR CASE CLASS CONTINUE DEF DO ELSE EXIT FLOAT FOR IF INT NUL OBJECT PRINT PRINTLN REPEAT RETURN READ STRING TO TYPE VAL VAR WHILE
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token <sval> ID STR
%token <ival> NUM
%token <dval> DOUBLE 
%token <cval> _CHAR
%token <bval> FALSE TRUE

%type <info> constant_exp procedure_statement expression bool_expression int_expreesion
%type <type> var_type method_type

%left OR_OP
%left AND_OP
%left '!'
%left '<' LE_OP EQ_OP GE_OP '>' NE_OP
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%

/* 2.2.1 program */
program
: OBJECT ID '{' {
					output << "class " << filename << endl << "{" << endl;
				}
declaration_list method_list '}'	{
					Trace("program");
					//symbols.dump();
					symbols.pop();
					if(!havemain) yyerror("without main");
					output << "}" <<endl;
					}
| OBJECT ID '{' {
				output << "class " << filename << endl << "{" << endl;
				}
method_list '}' {
				Trace("program");
				//symbols.dump();
				symbols.pop();
				if(!havemain) yyerror("without main");
				output << "}" <<endl;	
				}
;

var_type
: INT	{
		$$ = intType;
		}
| CHAR	{
		$$ = charType;
		}
| STRING	{
			$$ = strType;
			}
| BOOLEAN	{
			$$ = boolType;
			}
| FLOAT	{
		$$ = realType;
		}
;

declaration
: value
| variable
;

/* 2.1.1 constants */
value
: VAL ID '=' expression	{
						Trace("constant declaration without type");
						if(!isConst(*$4)) yyerror("expression not constant");
						$4->flag = constVariableFlag;
						$4->init = true;
						if (symbols.insert(*$2,*$4)==-1) yyerror("constant redefinition");
						}
| VAL ID ':' var_type '=' expression	{
										Trace("constant declaration with type");
										if(!isConst(*$6)) yyerror("expression not constant");
										if($4!=$6->type)	yyerror("assign type not match");
										$6->flag = constVariableFlag;
										$6->init = true;
										if (symbols.insert(*$2,*$6)==-1) yyerror("constant redefinition");
										
										}
;

/* 2.1.2 variables*/
variable
: VAR ID	{
			Trace("variable declaration");
			idInfo *info = new idInfo();
			info->flag = variableFlag;
			info->type = intType;
			info->init = false;
			if (symbols.insert(*$2, *info) == -1) yyerror("variable redefinition");
			int idx = symbols.getIndex(*$2);
			if(idx == -1) 
				output << "\tfield static int " << *$2 << endl;			
			}
| VAR ID ':' var_type	{
						Trace("variable declaration with type");
						idInfo *info = new idInfo();
						info->flag = variableFlag;
						info->type = $4;
						info->init = false;
						if (symbols.insert(*$2, *info) == -1) yyerror("variable redefinition");
						
						if($4 == intType || $4 == boolType){
							int idx = symbols.getIndex(*$2);
							if(idx == -1)
								output << "\tfield static int " << *$2 << endl;
						} 
						}
| VAR ID '=' expression	{
						Trace("variable declaration with value");
						if (!isConst(*$4)) yyerror("expression not constant");
						$4->flag = variableFlag;
						$4->init =true;
						if (symbols.insert(*$2,*$4)== -1) yyerror("variable redefinition");						
						int idx = symbols.getIndex(*$2);
						int val = getValue(*$4);
						if(idx == -1)
							output << "\tfield static int " << *$2 << " = " << val << endl;
						else
							output << "\t\tistore " << idx <<endl;
						}
| VAR ID ':' var_type '=' expression	{
										Trace("variable declaration with type and value");										
										if (!isConst(*$6)) yyerror("expression not constant");
										if ($4!=$6->type)	yyerror("assign type not match");
										$6->flag= variableFlag;
										$6->init = true;
										if (symbols.insert(*$2,*$6)== -1) yyerror("variable redefinition");
										
										if ($4 == intType || $4 == boolType){
										int idx = symbols.getIndex(*$2);
										int val = getValue(*$6);
										if(idx == -1)
											output << "\tfield static int " << *$2 << " = " << val << endl;
										else
											output << "\t\tistore " << idx << endl;
										}
										}
| VAR ID ':' var_type '['int_expreesion ']'	{
											Trace("array variable declaration");
											if(!isConst(*$6)) yyerror("size not constant");
											if($6->type!=intType)	yyerror("size not int");
											if($6->value.ival < 1)	yyerror("size < 1");
											if(symbols.insert(*$2,$4,$6->value.ival)==-1) yyerror("variable redefinition");
}
;

constant_exp
: STR	{
		$$ = strConst($1);
		}
| NUM	{
		$$ = intConst($1);
		}
| DOUBLE	{
		$$ = floatConst($1);
		}
| TRUE	{
		$$ = boolConst($1);
		}
| FALSE	{
		$$ = boolConst($1);
		}
| ID '[' int_expreesion ']'	{
					idInfo *info = symbols.lookup(*$1);
                    if (info == NULL) yyerror("undeclared ID");
                    if (info->type != arrayType) yyerror("not array type");
                    if ($3->type != intType) yyerror("invalid index");
                    if ($3->value.ival >= info->value.aval.size()) yyerror("index out of range");
                    $$ = new idInfo(info->value.aval[$3->value.ival]);
					}
;


/* zero or more variable and constant declarations */
declaration_list
: declaration
| declaration_list declaration
;

/* one or more method declarations */
method_list
: method
| method_list method
;

/* 2.2.2 methods */
method
: DEF ID	{
			idInfo *info = new idInfo();
			info->flag = functionFlag;
			info->init = false;
			if(symbols.insert(*$2,*info) == -1) yyerror("function redefinition");
			symbols.push();
			}
 '(' formal_argument_list ')' method_type	{
												if(*$2=="main"){
													havemain=true;
													output << "\tmethod public static void main(java.lang.String[])" << endl;
													output << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
												}else{
													idInfo *info = symbols.lookup(*$2);
													output << "\tmethod public static ";
													output << ((info->type == voidType)?"void " : "int ");
													output << info->id << "(";
													for(int i = 0; i<info->value.aval.size();i++) {
														if(i!=0) output << ", ";
														output<<"int";
													}
													output << ")" <<endl;
													output << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl << "\t{" << endl;
												}
											}
 compound_statement	{
					Trace("method");
					//symbols.dump();
					symbols.pop();
					output << "\t\treturn" << endl <<"\t}" <<endl;
					}
;

method_type
: ':' var_type	{symbols.setFuncType($2);}
|	{symbols.setFuncType(voidType);}
;

formal_argument_list
: formal_argument ',' formal_argument_list
| formal_argument
;

formal_argument
: ID ':' var_type	{
					idInfo *info = new idInfo();
                    info->flag = variableFlag;
                    info->type = $3;
                    info->init = false;
                    if (symbols.insert(*$1, *info) == -1) yyerror("variable redefinition");
                    symbols.addFuncArg(*$1, *info);
					}
|
;

statement 
: simple
| compound_statement 
| selection_statement 
| iteration_statement 
;

/* 2.3.1 simple */
simple
: ID '=' expression	{
					Trace("variable assignment");
					idInfo *info = symbols.lookup(*$1);
					if (info == NULL) yyerror("undeclared ID");
					if (info->flag == constVariableFlag) yyerror("can't assign value to constant");
					if (info->flag == functionFlag) yyerror("can't assign value to function");
					if (info->type != $3->type) yyerror("assign type not match");
					if(info->type==intType ||info->type==boolType){
						int idx = symbols.getIndex(*$1);
						if(idx == -1) 
							output << "\tputstatic int " << filename << "." << *$1 << endl;
						else
							output << "\t\tistore " << idx <<endl;
					}
					}
| ID '['int_expreesion']' '=' expression	{
										Trace("array assignment");
										idInfo *info = symbols.lookup(*$1);
										if (info == NULL) yyerror("undeclared ID");
										if (info->flag != variableFlag) yyerror("not variable");
										if (info->type != arrayType) yyerror("not array");
										if ($3->type != intType) yyerror("index not int");
										if ($3->value.ival >= info->value.aval.size() || $3->value.ival<0) yyerror("index out of range");
										if (info->value.aval[0].type != $6->type)	yyerror("assign type not match");
										}
|{output << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;}
PRINT  expression 	{
					Trace("print");
					if ($3->type ==strType) 
						output << "\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)" << endl;
					else
						output << "\t\tinvokevirtual void java.io.PrintStream.print(int)" << endl;
					}
|{output << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;}
PRINTLN  expression 	{
						Trace("println");
						if($3->type == strType)
							output << "\tinvokevirtual void java.io.PrintStream.print(java.lang.String)" << endl;
						else
							output << "\t\tinvokevirtual void java.io.PrintStream.print(int)" << endl;
						}
| READ ID	{
			Trace("read ID");
			idInfo *info = symbols.lookup(*$2);
			if(info == NULL) yyerror("undeclared ID");
			}
| RETURN expression {
					Trace("retrun");
					output << "\t\tireturn" << endl;
					}
| RETURN {	output << "\t\treturn" << endl;}
;

expression
: int_expreesion
| bool_expression
| '(' expression ')'	{
						Trace("(expression)");
						$$ = $2;
						}
						
| constant_exp	{
				if(!symbols.isGlobal()){
				if($1->type == strType)
					output << "\t\tldc \"" << $1->value.sval << "\"" << endl;
				else if($1->type ==intType || $1->type == boolType)
					output << "\t\tsipush " << getValue(*$1) << endl;
				}
				}
| ID 	{
		idInfo *info = symbols.lookup(*$1);
		if (info == NULL) yyerror("undeclared ID");
		$$ = info;
		
		if(!symbols.isGlobal() && isConst(*info)) {
			if(info->type==strType)
				output << "\t\tldc \"" << info->value.sval << "\"" << endl;
			else if(info->type ==intType || info->type == boolType)
				output << "\t\tsipush " << getValue(*info) << endl; 
		}	
		else if(info->type ==intType || info->type == boolType){
			int idx = symbols.getIndex(*$1);
			if(idx== -1) 
				output << "\tgetstatic int " << filename << "." << *$1 <<endl;
			else
				output << "\t\tiload " << idx << endl;
		}
		}
| procedure_statement
;

int_expreesion
: expression '+' expression	{
 							Trace("expression + expression");

                        	if ($1->type != $3->type)
								yyerror("+ type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							if($1->type ==intType) output << "\t\tiadd" << endl;
							}
| expression '-' expression	{
 							Trace("expression - expression");

                        	if ($1->type != $3->type)
								yyerror("- type not match");  /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							if($1->type ==intType) output << "\t\tisub" << endl;
							}
| expression '*' expression	{
 							Trace("expression * expression");

                        	if ($1->type != $3->type)
								yyerror("* type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							if($1->type ==intType) output << "\t\timul" << endl;
							}
| expression '/' expression	{
 							Trace("expression / expression");

                        	if ($1->type != $3->type)
								yyerror("/ type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type  == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							if($1->type ==intType) output << "\t\tidiv" << endl;
							}
| expression '%' expression	{
 							Trace("expression mod expression");

                        	if ($1->type != $3->type)
								yyerror("% type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type  == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							if($1->type ==intType) output << "\t\tirem" << endl;
							}
| '-' expression %prec UMINUS	{
 								Trace("-expression");
                          		if ($2->type == boolType || $2->type == strType || $2->type == charType || $2->type == arrayType)
									yyerror("operator type error"); /* operator check  */

                        	  	idInfo *info = new idInfo();
                    	      	info->flag = variableFlag;
                 	         	info->type = $2->type;
                          		$$ = info;
								if($2->type ==intType) output << "\t\tineg" << endl;
								}
;

bool_expression
: expression '<' expression	{
 							Trace("expression < expression");

                        	if ($1->type != $3->type)
								yyerror("< type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = boolType;
                          	$$ = info;
							if($1->type ==intType||$1->type== boolType) genCondOp(IFLT);
							}
| expression '>' expression	{
 							Trace("expression > expression");

   	                    	if ($1->type != $3->type)
								yyerror("> type not match"); /* type check */
            	          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */
	
    	                  	idInfo *info = new idInfo();
                        	info->flag = variableFlag;
           	              	info->type = boolType;
            	          	$$ = info;
							if($1->type ==intType||$1->type== boolType) genCondOp(IFGT);
							}
| expression LE_OP expression	{
 								Trace("expression <= expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("<= type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								if($1->type ==intType||$1->type== boolType) genCondOp(IFLE);
								}
| expression EQ_OP expression	{
	 							Trace("expression == expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("== type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								if($1->type ==intType||$1->type== boolType) genCondOp(IFEQ);
								}
| expression GE_OP expression	{
	 							Trace("expression >= expression");
	
    	                    	if ($1->type != $3->type)
									yyerror(">= type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								if($1->type ==intType||$1->type== boolType) genCondOp(IFGE);
								}
| expression NE_OP expression	{
	 							Trace("expression != expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("!= type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								if($1->type ==intType||$1->type== boolType) genCondOp(IFNE);
								}
| expression OR_OP expression	{
	 							Trace("expression || expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("|| type not match"); /* type check */
            	              	if ($1->type != boolType)
									yyerror("operator type error"); /* operator check */
	
        	                  	idInfo *info = new idInfo();
            	              	info->flag = variableFlag;
                	          	info->type = boolType;
                    	      	$$ = info;
								if($1->type ==boolType) output << "\t\tior" << endl;
								}
| expression AND_OP expression	{
	 							Trace("expression && expression");
	
	                        	if ($1->type != $3->type)
									yyerror("&& type not match"); /* type check */
	                          	if ($1->type != boolType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								if($1->type ==boolType) output << "\t\tiand" << endl;
								}
| '!' expression	{
					Trace("!expression");
					if($2->type != boolType) yyerror("operator error");
					
					idInfo *info = new idInfo();
					
					info->type = boolType;
					info->flag = variableFlag;
					$$ = info;
					if($2->type != boolType) output << "\t\tldc 1" << endl << "\t\tixor" << endl;
					}
;

/* 2.3.2 block */
compound_statement
: '{'	{
		symbols.push();
		}
 declaration_list statement_list '}'	{
										//symbols.dump();
										symbols.pop();
										}
| '{'	{
		symbols.push();
		}
 statement_list '}'	{
					symbols.pop();
					}
| '{' '}'
;

statement_list
: statement
| statement_list statement
;


/* 2.3.3 conditional */
selection_statement
: IF '(' expression ')' ifstart statement ELSE	{
												output << "\t\tgoto L" << lc.takeLabel(1) << endl;
												output << "\t\tnop" << endl;
												output << "L" << lc.takeLabel(0) << ":" << endl;
												}
statement	{
			Trace("selection condition with else");
			if ($3->type!=boolType) yyerror("condition type error");
			output << "\t\tnop" << endl;
			output << "L" << lc.takeLabel(1) << ":" << endl;
			lc.popLabel();
			}
| IF '(' expression ')' ifstart statement	{
											Trace("selection condition");
											if ($3->type!=boolType) yyerror("condition type error");
											output << "\t\tnop" << endl;
											output << "L" << lc.takeLabel(0) << ":" << endl;
											lc.popLabel();
											}
;
ifstart
: 	{
	lc.pushLabelN(2);
	output << "\t\tifeq L" << lc.takeLabel(0) << endl;
	}
;

/* 2.3.4 loop */
iteration_statement
: WHILE '('	{
			lc.pushLabelN(1);
			output << "\t\tnop" << endl;
			output << "L" << lc.takeLabel(0) << ":" << endl;
			}
expression	{
			lc.LabelN(1);
			output << "\t\tifeq L" << lc.takeLabel(3+lc.getFlag()) << endl;
			}
')' statement	{
				Trace("while loop");
				if ($4->type!=boolType) yyerror("condition type error");
				output << "\t\tgoto L" << lc.takeLabel(lc.getFlag()) << endl;
				output << "\t\tnop" << endl;
				output << "L" << lc.takeLabel(3+lc.getFlag()) << ":" << endl;
				lc.popLabel();
				}
| FOR '(' ID '<' '-' NUM TO NUM ')'	{
									output << "\t\tsipush " << getValue(*intConst($6)) << endl;
									int idx = symbols.getIndex(*$3);
									if(idx == -1) 
										output << "\tputstatic int " << filename << "." << *$3 << endl;
									else
										output << "\t\tistore " << idx <<endl;
									
									lc.pushLabelN(1);
									output << "\t\tnop" << endl;
									output << "L" << lc.takeLabel(0) << ":" << endl;
									
									if(idx== -1) 
										output << "\tgetstatic int " << filename << "." << *$3 <<endl;
									else
										output << "\t\tiload " << idx << endl;
									
									output << "\t\tsipush " << getValue(*intConst($8)) << endl;
									genCondOp(IFLE);	
									
									lc.LabelN(1);
									output << "\t\tifeq L" << lc.takeLabel(3+lc.getFlag()) << endl;
									
									Trace("for loop");
									idInfo *info = symbols.lookup(*$3);
									if (info == NULL) yyerror("undeclared ID");
									}
 statement	{
			output << "\t\tgoto L" << lc.takeLabel(lc.getFlag()) << endl;
			output << "\t\tnop" << endl;
			output << "L" << lc.takeLabel(3+lc.getFlag()) << ":" << endl;
			lc.popLabel();
			}

;

/* 2.3.5 procedure invocation */
procedure_statement
: ID '('	{
		function.push_back(vector<idInfo>());
		} 
 comma_separated_exp ')'	{
							Trace("procedure_statement");

							idInfo *info = symbols.lookup(*$1);
							if (info==NULL) yyerror("undeclared ID");
							if (info->flag!=functionFlag) yyerror("Not a function)");
	
							vector<idInfo> parameter = info->value.aval;
							if (parameter.size() != function[function.size()-1].size()) yyerror("parameter size not match");
							for(int i=0;i<parameter.size();i++)
							{
								if(parameter[i].type!= function[function.size()-1][i].type) yyerror("parameter type not match");
							}
							
							output << "\t\tinvokestatic ";
							output << ((info->type == voidType)? "void" : "int");
							output << " " << filename << "." << info->id << "(";
							for (int i = 0; i<info->value.aval.size();i++) {
								if(i!=0) output <<", ";
								output << "int";
							}
							output << ")" << endl;
							
							$$ = info;
							function.pop_back();
							}
;

comma_separated_exp
: expression ',' comma_separated_exp	{
										function[function.size()-1].push_back (*$1);
										}
| expression	{
				function[function.size()-1].push_back (*$1);
				}
|
;



%%

void yyerror(const char *msg)
{
    fprintf(stderr, "line %d: %s\n", linenum-1, msg);
}

void genCondOp(int op) {
	output << "\t\tisub" << endl;
	int lb1 = lc.getLabel();
	int lb2 = lc.getLabel();
	
	switch(op) {
		case IFLT: output << "\t\tiflt"; break;
		case IFGT: output << "\t\tifgt"; break;
		case IFLE: output << "\t\tifle"; break;
		case IFGE: output << "\t\tifge"; break;
		case IFEQ: output << "\t\tifeq"; break;
		case IFNE: output << "\t\tifne"; break;
	}
	output << " L" << lb1 <<endl;
	output <<"\t\ticonst_0" << endl;
	output << "\t\tgoto L" <<lb2 << endl;
	output << "\t\tnop" <<endl;
	output << "L" << lb1 << ":" << endl;
	output << "\t\ticonst_1" <<endl;
	output << "\t\tnop" <<endl;
	output << "L" << lb2 << ":" << endl;
}

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	string input = string(argv[1]);
	int dot = input.find(".");
	filename = input.substr(0, dot);
	output.open(filename + ".jasm");
	
	yyparse();
	return 0;
}

