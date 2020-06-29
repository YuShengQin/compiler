%{

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; if(pt==1) printf("<%s>\n",t);}
#define deli(t) {LIST; if(pt==1) printf("<'%s'>\n",t);}
#define tokenInteger(t,i) {LIST; if(pt==1) printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST; if(pt==1) printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256
using namespace std;
#include "y.tab.hpp"
extern void yyerror(const char *);  

int pt = 0;
int linenum = 1;
char buf[MAX_LINE_LENG];
void comment();
void append(char*, char);
int dealStr();

%}


ID	[A-Za-z][A-Za-z0-9]*
digit	[0-9]

STRING                  (\"(\"\"|[^"\n])*\")
SINGLE_COMMENT          (\/\/[^\n]*)
BEGIN_COMMENT           (\/\*)
END_COMMENT             (\*\/)
%x COMMENT

%%
"//".*	{
       	LIST;
       	}

{STRING}		{
				char s[MAX_LINE_LENG] = {0};
                int idx = 0;
                for (int i = 1; i < yyleng - 1; ++i) {
	                if (yytext[i] == '"') ++i;
                    s[idx++] = yytext[i];
                }
                yylval.sval = new string(s);
                return STR;
				}

boolean {token("BOOLEAN"); return BOOLEAN;}
break	{token("BREAK"); return BREAK;}
char	{token("CHAR"); return CHAR;}
case	{token("CASE"); return CASE;}
class	{token("CLASS"); return CLASS;}
continue	{token("CONTINUE"); return CONTINUE;}
def		{token("DEF"); return DEF;}
do 		{token("DO"); return DO;}
else	{token("ELSE"); return ELSE;}
exit	{token("EXIT"); return EXIT;}
false 	{yylval.bval=false; token("FALSE");	return FALSE;}
float 	{token("FLOAT");return FLOAT;}
for 	{token("FOR"); return FOR;}
if 		{token("IF"); return IF;}
int	 	{token("INT"); return INT;}
null 	{token("NULL"); return NUL;}
object 	{token("OBJECT"); return OBJECT;}
print 	{token("PRINT"); return PRINT;}
println {token("PRINTLN"); return PRINTLN;}
repeat 	{token("REPEAT"); return REPEAT;}
return	{token("RETURN"); return RETURN;}
read 	{token("READ"); return READ;}
string 	{token("STRING"); return STRING;}
to 		{token("TO"); return TO;}
true 	{yylval.bval=true; token("TURE");	return TRUE;}
type 	{token("TYPE"); return TYPE;}
val 	{token("VAL"); return VAL;}
var 	{token("VAR"); return VAR;}
while 	{token("WHILE"); return WHILE;}

"="		{tokenString("op","="); return '=';}
"+"		{tokenString("op","+"); return '+';}
"-" 	{tokenString("op","-"); return '-';}
"*"		{tokenString("op","*"); return '*';}
"/"		{tokenString("op","/"); return '/';}
"%"		{tokenString("op","%"); return '%';}
"<"		{tokenString("op","<"); return '<';}
"<="	{tokenString("op","<="); return LE_OP;}
">="	{tokenString("op",">="); return GE_OP;}
">"		{tokenString("op",">"); return '>';}
"=="	{tokenString("op","=="); return EQ_OP;}
"!="	{tokenString("op","!="); return NE_OP;}
"&&"	{tokenString("op","&&"); return AND_OP;}
"||"	{tokenString("op","||"); return OR_OP;}
"!"		{tokenString("op","!"); return '!';}

"("		{deli("("); return '(';}
")"		{deli(")"); return ')';}
"["		{deli("[");return '[';}
"]"		{deli("]");return ']';}
"{"		{deli("{");return '{';}
"}"		{deli("}");return '}';}
";"		{deli(";");return ';';}
"."		{deli(".");return '.';}
","		{deli(",");return ',';}
":"		{deli(":");return ':';}

{digit}+	{yylval.ival=atoi(yytext);	tokenInteger("int",atoi(yytext)); return NUM;}
{digit}+"."{digit}+|{digit}+"."{digit}+[Ee][+-]?{digit}+	{yylval.dval=atof(yytext);	tokenString("real",yytext)return DOUBLE;}
{ID}	{yylval.sval= new string(yytext); tokenString("ID",yytext);	return ID;}

{BEGIN_COMMENT}         {
                          LIST;
                          BEGIN COMMENT;
                        }
<COMMENT>[^\n]          {
                          LIST;
                        }

<COMMENT>\n             {
                          LIST;
                          linenum++;
                          buf[0] = '\0';
                        }

<COMMENT>{END_COMMENT}  {
                          LIST;
                          BEGIN INITIAL;
                        }

\n      {
        LIST;
		if(pt==1)
			printf("%d: %s", linenum++, buf);
	//	linenum++;
		buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        exit(-1);
        }


%%

int yywrap(void)   
{ 
    return 1;   
} 
