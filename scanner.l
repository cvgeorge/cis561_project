%{
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
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

"class"            { cout << lineNumber << " CLASS \"" << yytext << "\"" << endl;   }
"def"              { cout << lineNumber << " DEF \"" << yytext << "\"" << endl;   }
"extends"          { cout << lineNumber << " EXTENDS \"" << yytext << "\"" << endl;   }
"if"               { cout << lineNumber << " IF \"" << yytext << "\"" << endl;   }
"elif"             { cout << lineNumber << " ELIF \"" << yytext << "\"" << endl;   }
"else"             { cout << lineNumber << " ELSE \"" << yytext << "\"" << endl;   }
"while"            { cout << lineNumber << " WHILE \"" << yytext << "\"" << endl;   }
"return"           { cout << lineNumber << " RETURN \"" << yytext << "\"" << endl;  }



"+"                { cout << lineNumber << " + \"" << yytext << "\"" << endl;   }
"-"                { cout << lineNumber << " - \"" << yytext << "\"" << endl;   }
"*"                { cout << lineNumber << " * \"" << yytext << "\"" << endl;   }
"/"                { cout << lineNumber << " / \"" << yytext << "\"" << endl;   }

"=="                { cout << lineNumber << " == \"" << yytext << "\"" << endl;   }
"<="                { cout << lineNumber << " <= \"" << yytext << "\"" << endl;   }
"<"                { cout << lineNumber << " < \"" << yytext << "\"" << endl;   }
">="                { cout << lineNumber << " >= \"" << yytext << "\"" << endl;   }
">"                { cout << lineNumber << " > \"" << yytext << "\"" << endl;   }

"and"                { cout << lineNumber << " AND \"" << yytext << "\"" << endl;   }
"or"                { cout << lineNumber << " OR \"" << yytext << "\"" << endl;   }
"not"                { cout << lineNumber << " NOT \"" << yytext << "\"" << endl;   }

"{"                { cout << lineNumber << " { \"" << yytext << "\"" << endl;   }
"}"                { cout << lineNumber << " } \"" << yytext << "\"" << endl;   }
"="                { cout << lineNumber << " = \"" << yytext << "\"" << endl;   }
"("                { cout << lineNumber << " ( \"" << yytext << "\"" << endl;   }
")"                { cout << lineNumber << " ) \"" << yytext << "\"" << endl;   }
","                { cout << lineNumber << " , \"" << yytext << "\"" << endl;   }
";"                { cout << lineNumber << " ; \"" << yytext << "\"" << endl;   }
"."                { cout << lineNumber << " . \"" << yytext << "\"" << endl;   }
":"                { cout << lineNumber << " : \"" << yytext << "\"" << endl;   }



[a-zA-Z_][a-zA-Z0-9_]*     { cout << lineNumber << " IDENT \"" << yytext << "\"" << endl;   }




[0-9]+      { cout << lineNumber << " INT_LIT \"" << yytext << "\"" << endl;   }




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


["](\\[0btnrf"\\]|[^"])*["]	{ cout << lineNumber << " STRING_LIT \"" << yytext << "\"" << endl; }
["](\\[0btnrf"\\]|[^"])*[;]  { cerr << lineNumber << " Unclosed string encountered near \"" << yytext << "\"" << endl;}








<TRIPLEQUOTESTRINGS>{

	["]["]["]   { BEGIN(INITIAL);  cout << lineNumber << " STRING_LIT \"" << commentString << "\"" <<  endl;  }
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
