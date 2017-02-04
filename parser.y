%{
/*
 * Parts of this file were taken from the examples at http://aquamentus.com/flex_bison.html
 */

#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int lineNumber;
extern int yyparse(); 

void yyerror(const char *s);
int condition = 0;
%}

%union {
	int ival;
	char* sval;
	bool bval;
	char sym;
  	struct node_struct* nodeval; 

}

%token CLASS
%token DEF
%token EXTENDS
%token IF
%token ELIF
%token ELSE
%token WHILE
%token RETURN

%left PLUS
%left MINUS
%left MULT
%left DIVIDE

%left AND
%left OR
%left NOT

%left DOT

%token IDENT
%token <ival> INT_LIT
%token <sval> STRING_LIT
%left <sym> EQ GEQ LEQ GT LT

%type <nodeval> start program class class_declarations class_signature formal_args class_body method statement_block statement r_expr l_expr elseif actual_args testFinal
%%

start: program {cout << "Successfully parsed the program!";};

program: class_declarations statements {;} ;
		 /*class statement*/ 

class_declarations:
		 /*Zero or more class declarations*/ {;}
		| class class_declarations {;} 
		;

statements:
		/*Zero or more statements*/ {;}
		| statement statements {;}
		;

class:
		 class_signature class_body {;} ;

class_signature:
		 CLASS IDENT '(' formal_args ')' EXTENDS IDENT {;} ;
		| CLASS IDENT '(' formal_args ')' {;} ;

formal_args:
		/*empty*/ {;}
		| IDENT ':' IDENT {;} 
		| IDENT ':' IDENT ',' formal_args {;}
		;

class_body:
		 '{' statements methods '}' {;} ;

methods:
		/*Zero or more methods*/ {;}
		| method methods {;}
		;

method:
		  DEF IDENT '(' formal_args ')' ':' IDENT statement_block {;}
		| DEF IDENT '(' formal_args ')' statement_block {;}
		;

statement_block:
		 '{' statements '}' {;}


statement:
		  IF r_expr statement_block elseif {;}
		| WHILE '(' r_expr ')' statement_block {;}
		| RETURN r_expr ';' {;}
		| l_expr '=' r_expr ';' {;}
		| l_expr ':' IDENT '=' r_expr ';' {;}
		| r_expr ';' {;}
		;

elseif:
		  /*Else if*/ {;}
		| ELIF r_expr statement_block elseif {;}
		| ELSE statement_block {;}
		;


l_expr:	IDENT {;}
		| r_expr DOT IDENT {;}
		;


r_expr:  r_expr OR r_expr {;}
		| r_expr AND r_expr {;}
		| r_expr EQ r_expr {;}
		| r_expr GEQ r_expr {;}
		| r_expr LEQ r_expr {;}
		| r_expr GT r_expr {;}
		| r_expr LT r_expr {;}
		| r_expr PLUS r_expr {;}
		| r_expr MINUS r_expr {;}
		| r_expr MULT r_expr {;}
		| r_expr DIVIDE r_expr {;}
		| testFinal {;}
		;

testFinal: /*Empty*/ {;} 
	| IDENT {;}
	| r_expr dotMatcher {;}
	| IDENT '(' actual_args ')' {;}
	| STRING_LIT {;}
	| INT_LIT {;}
	|  '(' r_expr ')' {;}
	;

dotMatcher: DOT IDENT '(' actual_args ')' {;}
		|	DOT IDENT {;}

 /*	
booleanExpression1: final
				| booleanExpression1 OR final {;}
				  ;


booleanExpression1: booleanExpression1 OR booleanExpression2 {;}
				  | booleanExpression2
				  ;

booleanExpression2: booleanExpression2 AND booleanExpression3 {;}
				  | booleanExpression3 {;}
				  ;	

booleanExpression3: NOT booleanExpression4 {;}
				  | booleanExpression4 {;}
				  ;	

booleanExpression4: booleanExpression4 EQ booleanExpression5 {;}
				  | booleanExpression5 {;}
				  ;

booleanExpression5: booleanExpression5 GEQ booleanExpression6 {;}
				  | booleanExpression6 {;}
				  ;

booleanExpression6: booleanExpression6 LEQ booleanExpression7 {;}
				  | booleanExpression7 {;}
				  ;

booleanExpression7: booleanExpression7 GT booleanExpression8 {;}
				  | booleanExpression8 {;}
				  ;

booleanExpression8: booleanExpression8 LT arithmeticExpression1 {;}
				  | arithmeticExpression1 {;}
				  ;

arithmeticExpression1: arithmeticExpression1 PLUS arithmeticExpression2 {;}
				  | arithmeticExpression2 {;}
				  ;

arithmeticExpression2: arithmeticExpression2 MINUS arithmeticExpression3 {;}
				  | arithmeticExpression3 {;}
				  ;

arithmeticExpression3: arithmeticExpression3 MULT arithmeticExpression4 {;}
				  | arithmeticExpression4 {;}
				  ;

arithmeticExpression4: arithmeticExpression4 DIVIDE final {;}
				  | final {;}
				  ;
 */
				  /*
final: /*Empty {;} 
	| IDENT {;}
	| IDENT DOT r_expr {;}
	| IDENT '(' actual_args ')' {;}
	| STRING_LIT {;}
	| INT_LIT {;}
	//|  '(' booleanExpression1 ')' {;}
	|  '(' r_expr ')' {;}
	;
*/

actual_args:
		 /*No arguments {;}
		|*/ r_expr ',' actual_args {;}
		| r_expr {;}
%%

int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc != 2){
		cout << "The parser must be run in the format:   ./parser <filename>";
		return 0;
	}

	FILE *myfile = fopen(argv[1], "r");
	int condition;
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open a quack file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		condition = yyparse();
		cout << " Condition: " << condition << endl;
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << "Condition: " << condition << endl;
	cout << "Parse error on line " << lineNumber << "!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}