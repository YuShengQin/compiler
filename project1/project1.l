%{

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define deli(t) {LIST; printf("<'%s'>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int linenum = 1;
char buf[MAX_LINE_LENG];
void comment();
void append(char*, char);
void dealStr();

struct node{
	int index;
	char data[MAX_LINE_LENG];
	struct node *next;
};
typedef struct node Node;

Node *node;
Node *createList();
Node printList(Node *); 
void freeList(Node *);
int searchNode(Node *,char *); 
int insertNode(Node *,char *);
%}


ID	[A-Za-z][A-Za-z0-9]*
digit	[0-9]

%%
"("|")"|"["|"]"|"{"|"}"|";"|"."|","|":"     {deli(yytext);}

"/*"    {
        LIST;
        comment();
        }

"//".*	{
       	LIST;
       	}

\"		{
		LIST;
		dealStr();
		}

boolean|break|char|case|class|continue|def|do|else|exit|false|float|for|if|int|null|object|print|println|repeat|return|string|to|true|type|val|var|while	{
		char temp[MAX_LINE_LENG];
		for(int i=0;i<yyleng;i++)
			temp[i]=toupper(yytext[i]);
		temp[yyleng]= '\0';
		token(temp);
		}

{digit}+	{tokenInteger("int",atoi(yytext));}
[+-]?{digit}+"."{digit}+|{digit}+"."{digit}+[Ee][+-]?{digit}+	{tokenString("real",yytext);}
{ID}	{
		if(searchNode(node,yytext)==-1)
			insertNode(node,yytext);
		tokenString("id",yytext);
		}

"="|"+"|"-"|"*"|"/"|"%"|"<"|"<="|">="|">"|"=="|"!="|"&&"|"||"|"!"	{tokenString("op",yytext);}



\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }


%%

void comment(void) {
    char c;
    while((c = input())!=0) {
        append(buf,c);
        if(c=='\n') {
            printf("%d: %s", linenum++, buf);
            buf[0] = '\0';
        }
        if(c=='*') {
            if((c=input())=='/'){
                append(buf,c);
                return;
            }
			unput(c);
        }
    }
}
void append(char* s, char c) {
    int len = strlen(s);
    s[len]=c;
    s[len+1]='\0';
}
void dealStr(void) {
	char c,nc;
	char str[MAX_LINE_LENG];
	str[0]= '\0';
	while((c = input())!=0) {
		if(c=='\n'){	
        	printf("%d:%s\n", linenum, buf);
        	printf("bad character:'%s'\n",yytext);
        	exit(-1);
		}
		append(buf,c);
		if(c=='"')
		{
			nc  = input();	
			if(nc=='"') {
				append(str,c);
				append(buf,c);
			}
			else {
				unput(nc);
				printf("<string>:<%s>\n",str);
				return;
			}
		}
		else
			append(str,c);
	}
}

//串列建立函數 
Node *createList(){
	int i;
	Node *first,*current,*previous;
	current=(Node *) malloc(sizeof(Node));//建立新節點
	current->data[0]='\0';  //設定節點的資料成員
	current->index = -1;
	first=current;  //如果是第一個成員把指標frist指向目前的節點 
	current->next=NULL; //把目前的節點的next指向NULL
	previous=current; //把前一個節點設成目前的節點 
	return first;
}

//串列列印函數
Node printList(Node *first){
	Node *node=first; //將node指向第一個節點
	if(first==NULL){
		printf("List is empty!\n");
	}else{
		printf("\nSymbol Table:");
		while(node!=NULL){
			printf("%s\n",node->data);
			node=node->next;
		}
	}
} 

//釋放串列記憶空間函數
void freeList(Node *first){
	Node *current,*tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->next;
		free(tmp);
	}
}

 //搜尋節點函數 
int searchNode(Node *first,char *id){
	Node *node=first;
	while(node!=NULL){
		if(strcmp(node->data,id)==0){ //如果node的data等於id 
			return node->index;  //傳回node為該節點index 
		}else{
			node=node->next; //否則將指標指向下一個節點 
		}
	}
	return -1; //如果找不到符合的節點，則傳回-1
}

 //插入節點函數 
int insertNode(Node *node,char *id){
	Node *newnode;
	newnode=(Node *) malloc(sizeof(Node));
	strcpy(newnode->data,id);
	while(node->next!=NULL)
		node=node->next;
	newnode->index = node->index + 1;
	newnode->next=node->next;
	node->next=newnode;
	return newnode->index;
}

int main(int argc, char *argv[]) {
	node=createList();
	yylex();
	printList(node);
	fflush(yyout);
	exit(0);
}
