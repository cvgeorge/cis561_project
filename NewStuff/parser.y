%{
/*
 * Parts of this file were taken from the examples at http://aquamentus.com/flex_bison.html
 */

#include <cstdio>
#include <iostream>
#include "abstract_syntax_tree.h"
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
  	struct tree_node* treeNode; 

}

%token CLASS
%token DEF
%token EXTENDS
%token IF
%token ELIF
%token ELSE
%token WHILE
%token RETURN


%left DOT


/*%left <ival> INT_LIT INTEGER */
%left <sval> STRING_LIT IDENT STRING    INT_LIT INTEGER
%left <sval> EQ GEQ LEQ GT LT AND OR NOT PLUS MINUS MULT DIVIDE

%type <treeNode> start program class dotMatcher parameter class_declarations class_signature formal_args class_body method statements methods
%type <treeNode> statement_block statement r_expr l_expr actual_args testFinal if_header if_statement elseif_header elseif_block else_clause boolean_operator arithmetic_operator

%%

start: program {cout << "Finished parse with no errors" << endl;};

program: class_declarations statements {$$ = newTreeNode(); cout << "a" << endl;
										$$->type = TN_PROGRAM;
										$$->numOperands = 2;
										$$->operands[0] = $1;
										$$->operands[0] = $2;} ;
		 /*class statement*/ 

class_declarations:
		 /*Zero or more class declarations*/  {;}
		| class class_declarations {$1->pNextStatement = $2;
									$$ = $1;}
		;

statements:
		/*Zero or more statements*/ {cout << "empty statement" << endl;}
		| statement statements {cout << "statements" << endl;
								$1->pNextStatement = $2;
								$$ = $1;}
		;

class:
		 class_signature class_body {$$ = newTreeNode(); cout << "b" << endl;
		 							 $$->type = TN_CLASS;
		 							 $$->numOperands = 2;
		 							 $$->operands[1] = $1;
		 							 $$->operands[2] = $2;} ;

class_signature:
		 CLASS IDENT '(' formal_args ')' EXTENDS IDENT {$$ = newTreeNode();
		 												
		 												$$->type = TN_CLASSDEF;
		 												/*$$->sval = ($2); cout << "2" << endl;*/
		 												
		 												$$->sval = ($2);
		 												
		 												$$->numOperands = 1;
		 												
		 												$$->operands[0] = $4;
		 												} ;
		| CLASS IDENT '(' formal_args ')' { $$ = newTreeNode(); cout << "d" << endl;
											$$->type = TN_CLASSDEF;
											$$->sval = ($2);
											$$->numOperands = 1;
											$$->operands[0] = $4;} ;
/*
type: INTEGER { $$ = INTEGER_LITERAL;}
	| STRING {$$ = STRING_LITERAL;}
	| {$$ = NONE_TYPE;}
	;
*/
parameter: IDENT ':' IDENT {	$$ = newTreeNode(); cout << "e" << endl;
							$$->type = TN_PARAMETER;
							$$->sval = ($1);

							$$->dataType = ($3);
							/*$$->ival = $3;*/}
							;

formal_args:
		/*empty*/ {cout << "fa" << endl;}
		| parameter {   
						$$ = newTreeNode(); cout << "f" << endl;
						$$->type = TN_PARAMLIST;
						$$->numOperands = 1;
						$$->operands[0] = $1;
					} 
		| parameter ',' formal_args {cout << "more formal args" << endl;
									 $$ = $3;
									 $$->operands[$$->numOperands++] = $1;
									}
		;

class_body:
		 '{' statements methods '}' {$$ = newTreeNode(); cout << "g" << endl;
		 							 $$->type = TN_CLASSBODY;
		 							 $$->numOperands = 2;
		 							 $$->operands[0] = $2;
		 							 $$->operands[1] = $3;
		 							 } ;

methods:
		/*Zero or more methods*/ {cout << "empty methods";}
		| method methods {cout << "method" << endl;
							$1->pNextStatement = $2;
						  $$ = $1;}
		;

method:
		  DEF IDENT '(' formal_args ')' ':' IDENT statement_block {$$ = newTreeNode(); cout << "h" << endl;
		  															$$->type = TN_METHOD;
		  															$$->sval = ($2);
		  															$$->dataType = $7;
		  															$$->numOperands = 2;
		  															/*$$->ival = $7;*/
		  															$$->operands[0] = $4;
		  															$$->operands[1] = $8;}
		| DEF IDENT '(' formal_args ')' statement_block {$$ = newTreeNode(); cout << "i" << endl;
														$$->type = TN_METHOD;
														$$->sval = ($2);
														$$->dataType = (char *) "void";
														$$->numOperands = 2;
														/*$$->ival = NONE_TYPE;*/
														$$->operands[0] = $4;
														$$->operands[1] = $6;}
		;

statement_block:
		 '{' statements '}' {$$ = $2;}

else_clause:
		 ELSE statement_block { $$ = $2;}
		 ;

elseif_header:
		 ELIF r_expr {$$ = $2;}
		 ;

elseif_block:
		  elseif_header statement_block {$$ = newTreeNode(); cout << "j" << endl;
										$$->type = TN_IF;
										$$->numOperands = 2;
										$$->operands[0] = $1;
										$$->operands[1] = $2;}
		| elseif_header statement_block else_clause {$$ = newTreeNode(); cout << "k" << endl;
													$$->type = TN_IF;
													$$->numOperands = 3;
													$$->operands[0] = $1;
													$$->operands[1] = $2;
													$$->operands[2] = $3;}
		| elseif_header statement_block elseif_block {$$ = newTreeNode(); cout << "l" << endl;
													$$->type = TN_IF;
													$$->numOperands = 3;
													$$->operands[0] = $1;
													$$->operands[1] = $2;
													$$->operands[2] = $3;}
		;

if_statement: 
		  if_header statement_block {$$ = newTreeNode(); cout << "m" << endl;
		  							 $$->type = TN_IF;
		  							 $$->numOperands = 2;
		  							 $$->operands[0] = $1;
		  							 $$->operands[1] = $2;
		  							}
		| if_header statement_block else_clause {$$ = newTreeNode(); cout << "n" << endl;
												 $$->type = TN_IF;
												 $$->numOperands = 3;
												 $$->operands[0] = $1;
												 $$->operands[1] = $2;
												 $$->operands[2] = $3;
												}
		| if_header statement_block elseif_block {$$ = newTreeNode(); cout << "o" << endl;
												  $$->type = TN_IF;
										 		  $$->numOperands = 3;
												  $$->operands[0] = $1;
												  $$->operands[1] = $2;
												  $$->operands[2] = $3;}
		;
if_header:
		IF r_expr {$$ = $2;}
		;

statement: if_statement {$$ = $1;}
		| WHILE '(' r_expr ')' statement_block {$$ = newTreeNode(); cout << "p" << endl;
												$$->type = TN_WHILE;
												$$->numOperands = 2;
												$$->operands[0] = $3;
												$$->operands[1] = $5;}

		| RETURN r_expr ';' {$$ = newTreeNode(); cout << "q" << endl;
							 $$->type = TN_RETURN;
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

		| l_expr '=' r_expr ';' {$$ = newTreeNode(); cout << "r" << endl;
								 $$->type = TN_ASSIGNMENT;
								 $$->numOperands = 2;
								 $$->operands[0] = $1;
								 $$->operands[1] = $3;
								 cout << "bnm" << endl;
								 }

		| l_expr ':' IDENT '=' r_expr ';' {
								 $$ = newTreeNode(); cout << "s" << endl;
								 $$->type = TN_ASSIGNMENT;
								 $$->sval = $3;
								 $$->numOperands = 2;
								 $$->operands[0] = $1;
								 $$->operands[1] = $5;}

		| r_expr ';' {$$ = newTreeNode(); cout << "t" << endl;
					  $$->type = TN_EXPR_STATEMENT;
					  $$->numOperands = 1;
					  $$->operands[0] = $1;}
		;
/*
elseif:
		  /*Else if {;}
		| ELIF r_expr statement_block elseif {;}
		| ELSE statement_block {;}
		;
*/

l_expr:	IDENT { $$ = newTreeNode(); cout << "u" << endl;
				$$->type = TN_LEFT_EXPRESSION;

				$$->sval = ($1);
				}
		| r_expr DOT IDENT {$$ = newTreeNode(); cout << "v" << endl;
							$$->type = TN_LEFT_EXPRESSION;
							$$->numOperands = 1;
							$$->operands[0] = $1;}
		;

boolean_operator: OR r_expr {$$ = newTreeNode(); cout << "w" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| AND r_expr {$$ = newTreeNode(); cout << "x" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| EQ r_expr {$$ = newTreeNode(); cout << "y" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| GEQ r_expr {$$ = newTreeNode(); cout << "z" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| LEQ r_expr {$$ = newTreeNode(); cout << "A" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| GT r_expr {$$ = newTreeNode(); cout << "B" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| LT r_expr {$$ = newTreeNode(); cout << "C" << endl;
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}
				;


arithmetic_operator:  PLUS r_expr {  $$ = newTreeNode(); cout << "D" << endl;
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| MINUS r_expr {$$ = newTreeNode(); cout << "E" << endl;
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| MULT r_expr {$$ = newTreeNode(); cout << "F" << endl;
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| DIVIDE r_expr {$$ = newTreeNode(); cout << "G" << endl;
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					; 


r_expr:  r_expr boolean_operator{$$ = newTreeNode(); cout << "H" << endl;
										 $$->type = TN_BOOLEAN_EXPRESSION;
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $2;}


		| r_expr arithmetic_operator {$$ = newTreeNode(); cout << "I" << endl;
										 $$->type = TN_ARITHMETIC_EXPRESSION;
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $2;}
		| testFinal {$$ = newTreeNode(); cout << "J" << endl;
					 $$->type = TN_INTERMEDIATE_EXPRESSION;
					 $$->numOperands = 1;
					 $$->operands[0] = $1;
					}
		;

testFinal: /*Empty*/  {;}
	| IDENT {$$ = newTreeNode(); cout << "K" << endl;
			$$->type = TN_IDENT_EXPRESSION;
			$$->sval = ($1);}
	| r_expr dotMatcher {$$ = newTreeNode(); cout << "L" << endl;
						$$->type = TN_DEREF;
						$$->numOperands = 2;
						$$->operands[0] = $1;
						$$->operands[1] = $2;}
	| IDENT '(' actual_args ')' {$$ = newTreeNode(); cout << "M" << endl;
								$$->type = TN_FUNCTION_CALL_EXPRESSION;
								$$->sval = ($1);
								$$->numOperands = 1;
								$$->operands[0] = $3;}
	| STRING_LIT {$$ = newTreeNode(); cout << "N" << endl;
			$$->type = TN_STRING_EXPRESSION;
			$$->sval = ($1);}
	| INT_LIT {$$ = newTreeNode(); cout << "O" << endl;
			$$->type = TN_INTEGER_EXPRESSION;
			/*$$->ival = $1;*/}
	| '(' r_expr ')' {$$ = $2;}
	;

dotMatcher: DOT IDENT '(' actual_args ')' {$$ = newTreeNode(); cout << "P" << endl;
										   $$->type = TN_DEREFERENCE_FUNC;
										   $$->sval = ($2);
										   $$->numOperands = 1;
										   $$->operands[0] = $4;}
		|	DOT IDENT {$$ = newTreeNode(); cout << "Q" << endl;
					   $$->type = TN_DEREFERENCE_VAR;
					   $$->sval = ($2);
					   }


actual_args:
		 /*No arguments {;}
		|*/ r_expr ',' actual_args {$$ = $3;
									$$->operands[$$->numOperands++] = $1;}
		| r_expr {$$ = newTreeNode(); cout << "R" << endl;
				  $$->type = TN_ARGLIST;
				  $$->numOperands = 1;
				  $$->operands[0] = $1;}




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
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << lineNumber << ": " << s << endl;
	// might as well halt now:
	exit(-1);
}