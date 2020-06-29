%{
	#define Trace(t)        if(isP==1)printf(t); if(isP==1) printf("\n")
	#include <iostream>
	#include "lex.yy.cpp"
	#include "symbols.hpp"
	int isP = 0;
	bool havemain =false;
	void yyerror(const char *msg);
	SymbolTableList symbols;
	vector<vector<idInfo>> function;
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
%left '*' '/'
%nonassoc UMINUS

%%

/* 2.2.1 program */
program
: OBJECT ID '{' declaration_list method_list '}'	{
													Trace("program");
													//symbols.dump();
													symbols.pop();
													if(!havemain) yyerror("without main");
													}
| OBJECT ID '{' method_list '}'	{
								Trace("program");
								//symbols.dump();
								symbols.pop();
								if(!havemain) yyerror("without main");
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
										if($4!=$6->type)	yyerror("type not match");
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
			}
| VAR ID ':' var_type	{
						Trace("variable declaration with type");
						idInfo *info = new idInfo();
						info->flag = variableFlag;
						info->type = $4;
						info->init = false;
						if (symbols.insert(*$2, *info) == -1) yyerror("variable redefinition");
						}
| VAR ID '=' expression	{
						Trace("variable declaration with value");
						if (!isConst(*$4)) yyerror("expression not constant");
						$4->flag = variableFlag;
						$4->init =true;
						if (symbols.insert(*$2,*$4)== -1) yyerror("variable redefinition");						
						}
| VAR ID ':' var_type '=' expression	{
										Trace("variable declaration with type and value");										
										if (!isConst(*$6)) yyerror("expression not constant");
										if ($4!=$6->type)	yyerror("type not match");
										$6->flag= variableFlag;
										$6->init = true;
										if (symbols.insert(*$2,*$6)== -1) yyerror("variable redefinition");
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
			if(*$2=="main") havemain=true;
			}
 '(' formal_argument_list ')' method_type compound_statement	{
														Trace("method");
														//symbols.dump();
														symbols.pop();
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
					if (info->type != $3->type) yyerror("type not match");
					}
| ID '['int_expreesion']' '=' expression	{
										Trace("array assignment");
										idInfo *info = symbols.lookup(*$1);
										if (info == NULL) yyerror("undeclared ID");
										if (info->flag != variableFlag) yyerror("not variable");
										if (info->type != arrayType) yyerror("not array");
										if ($3->type != intType) yyerror("index not int");
										if ($3->value.ival >= info->value.aval.size() || $3->value.ival<0) yyerror("index out of range");
										if (info->value.aval[0].type != $6->type)	yyerror("type not match");
										}
| PRINT  expression 	{Trace("print");}
| PRINTLN  expression 	{Trace("println");}
| READ ID	{
			Trace("read ID");
			idInfo *info = symbols.lookup(*$2);
			if(info == NULL) yyerror("undeclared ID");
			}
| RETURN expression {Trace("retrun");}
| RETURN 
;

expression
: int_expreesion
| bool_expression
| '(' expression ')'	{
						Trace("(expression)");
						$$ = $2;
						}
						
| constant_exp
| ID 	{
		idInfo *info = symbols.lookup(*$1);
		if (info == NULL) yyerror("undeclared ID");
		$$ = info;
		}
| procedure_statement
;

int_expreesion
: expression '+' expression	{
 							Trace("expression + expression");

                        	if ($1->type != $3->type)
								yyerror("type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							}
| expression '-' expression	{
 							Trace("expression - expression");

                        	if ($1->type != $3->type)
								yyerror("type not match");  /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							}
| expression '*' expression	{
 							Trace("expression * expression");

                        	if ($1->type != $3->type)
								yyerror("type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							}
| expression '/' expression	{
 							Trace("expression / expression");

                        	if ($1->type != $3->type)
								yyerror("type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type  == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = $1->type;
                          	$$ = info;
							}
| '-' expression %prec UMINUS	{
 								Trace("-expression");
                          		if ($2->type == boolType || $2->type == strType || $2->type == charType || $2->type == arrayType)
									yyerror("operator type error"); /* operator check  */

                        	  	idInfo *info = new idInfo();
                    	      	info->flag = variableFlag;
                 	         	info->type = $2->type;
                          		$$ = info;
								}
;

bool_expression
: expression '<' expression	{
 							Trace("expression < expression");

                        	if ($1->type != $3->type)
								yyerror("type not match"); /* type check */
                          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = boolType;
                          	$$ = info;
							}
| expression '>' expression	{
 							Trace("expression > expression");

   	                    	if ($1->type != $3->type)
								yyerror("type not match"); /* type check */
            	          	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
								yyerror("operator type error"); /* operator check */
	
    	                  	idInfo *info = new idInfo();
                        	info->flag = variableFlag;
           	              	info->type = boolType;
            	          	$$ = info;
							}
| expression LE_OP expression	{
 								Trace("expression <= expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								}
| expression EQ_OP expression	{
	 							Trace("expression == expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								}
| expression GE_OP expression	{
	 							Trace("expression >= expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								}
| expression NE_OP expression	{
	 							Trace("expression != expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
            	              	if ($1->type == boolType || $1->type == strType || $1->type == charType || $1->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
								}
| expression OR_OP expression	{
	 							Trace("expression || expression");
	
    	                    	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
            	              	if ($1->type != boolType)
									yyerror("operator type error"); /* operator check */
	
        	                  	idInfo *info = new idInfo();
            	              	info->flag = variableFlag;
                	          	info->type = boolType;
                    	      	$$ = info;
								}
| expression AND_OP expression	{
	 							Trace("expression && expression");
	
	                        	if ($1->type != $3->type)
									yyerror("type not match"); /* type check */
	                          	if ($1->type != boolType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	$$ = info;
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
					//symbols.dump();
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
: IF '(' expression ')' statement ELSE statement	{
													Trace("selection condition with else");
													if ($3->type!=boolType) yyerror("condition type error");
													}
| IF '(' expression ')' statement	{
									Trace("selection condition");
									if ($3->type!=boolType) yyerror("condition type error");
									}
;

/* 2.3.4 loop */
iteration_statement
: WHILE '(' expression ')' statement	{
										Trace("while loop");
										if ($3->type!=boolType) yyerror("condition type error");
										}
| FOR '(' ID '<' '-' NUM TO NUM ')'	{
									Trace("for loop");
									idInfo *info = symbols.lookup(*$3);
									if (info == NULL) yyerror("undeclared ID");
									}
 statement 
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
    fprintf(stderr, "%s\n", msg);
}

int main()
{
	yyparse();
	return 0;
}

