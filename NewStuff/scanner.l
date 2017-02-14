%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
#include "parser.tab.h"

# define MAX_STRING_LENGTH 4097
int lineNumber = 1;
char commentString[MAX_STRING_LENGTH];
char* commentStringPtr;

%}

%x TRIPLEQUOTESTRINGS
%x MULTILINECOMMENT
%x STRING
%%


[\t]         	;
\n 				{ lineNumber++; }
" "				;

"class"            { return CLASS; }
"def"              {  return DEF;  }
"extends"          {  return EXTENDS;  }
"if"               {  return IF;  }
"elif"             {  return ELIF;  }
"else"             {  return ELSE;  }
"while"            {  return WHILE;  }
"return"           {  return RETURN; }



"+"                {  return PLUS;  }
"-"                {  return MINUS;  }
"*"                {  return MULT;  }
"/"                {  return DIVIDE;  }

"=="                {  return EQ;  }
"<="                {  return LEQ;  }
"<"                {  return LT;  }
">="                {  return GEQ;  }
">"                {  return GT;  }

"and"                {  return AND;  }
"or"                {  return OR;  }
"not"                {  return NOT; }

"{"                {  return yytext[0];  }
"}"                {  return yytext[0];  }
"="                {  return yytext[0];  }
"("                {  return yytext[0];  }
")"                {  return yytext[0];  }
","                {  return yytext[0];  }
";"                {  return yytext[0];  }
"."                {  return DOT;  }
":"                {  return yytext[0];   }


[a-zA-Z_][a-zA-Z0-9_]*     { return IDENT;   }




[0-9]+      {  return INT_LIT;   }




[/][/][^\n]*\n		{ lineNumber++; }

<INITIAL>{
"/*" BEGIN(MULTILINECOMMENT); 
}

<MULTILINECOMMENT>{ 
"*"+"/" BEGIN(INITIAL);
\n      { lineNumber++; }
"*"+[^*/\n]* {;}
[^*\n]*      {;}
}

["]["]["]		{ commentStringPtr = commentString; BEGIN(TRIPLEQUOTESTRINGS); }


["](\\[0btnrf"\\]|[^"\n])*["]	{  return STRING_LIT; }
\"[^\"\n]*$  {  cerr << "Error tokenizing on line: " << lineNumber << " Unclosed string encountered near \"" << yytext << "\"" << endl;}








<TRIPLEQUOTESTRINGS>{

	["]["]["]   { BEGIN(INITIAL);  return STRING_LIT;  }
	\n   { *commentStringPtr++ = '\n'; lineNumber++; }
	\t   { *commentStringPtr++ = '\t'; }
	\r   { *commentStringPtr++ = '\r'; }
	\b   { *commentStringPtr++ = '\b'; }
	\f   { *commentStringPtr++ = '\f'; }
	
	
	[^\n\"]+ { char* myChar = yytext;
				 while( *myChar)
				 	*commentStringPtr++ = *myChar++;
				 
				}

}


%%
/*
int main(int argc, char** argv) {
	
	if(argc != 2)
	{
		cout << "Please enter the file name as a command line argument.";
	}
	else
	{
		FILE *myFile = fopen(argv[1], "r");
		if(!myFile)
		{
			cout << "File " << argv[1] << " was not found!";
			return -1;
		}

		yyin = myFile;
		yylex();
	}
}
*/