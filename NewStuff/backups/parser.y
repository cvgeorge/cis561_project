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
	char sym;
	string str;
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


%token <ival> INT_LIT INTEGER
%token <sval> STRING_LIT IDENT STRING
%left <str> EQ GEQ LEQ GT LT AND OR NOT PLUS MINUS MULT DIVIDE

%type <treeNode> start program class dotMatcher parameter type class_declarations class_signature formal_args class_body method statements methods
%type <treeNode> statement_block statement r_expr l_expr actual_args testFinal if_header if_statement elseif_header elseif_block else_clause

%type <sval> boolean_operator arithmetic_operator
%%

start: program {cout << "Finished parse with no errors" << endl;};

program: class_declarations statements {$$ = newTreeNode();
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
		/*Zero or more statements*/ {;}
		| statement statements {$1->pNextStatement = $2;
								$$ = $1;}
		;

class:
		 class_signature class_body {$$ = newTreeNode();
		 							 $$->type = TN_CLASS;
		 							 $$->numOperands = 2;
		 							 $$->operands[1] = $1;
		 							 $$->operands[2] = $2;} ;

class_signature:
		 CLASS IDENT '(' formal_args ')' EXTENDS IDENT {$$ = newTreeNode();
		 												$$->type = TN_CLASSDEF;
		 												$$->sval = strdup($2);
		 												$$->superval = strdup($7);
		 												$$->numOperands = 1;
		 												$$->operands[0] = $4} ;
		| CLASS IDENT '(' formal_args ')' { $$ = newTreeNode();
											$$->type = TN_CLASSDEF;
											$$->sval = strdup($2);
											$$->superval = "Obj";
											$$->numOperands = 1;
											$$->operands[0] = $4;} ;

type: INTEGER { $$ = INTEGER_LITERAL;}
	| STRING {$$ = STRING_LITERAL;}
	| {$$ = NONE_TYPE;}
	;

parameter: IDENT ':' type {	$$ = newTreeNode();
							$$->type = TN_PARAMETER;
							$$->sval = strdup($1);
							$$->ival = $3;}
							;

formal_args:
		/*empty*/ {;}
		| parameter {   
						$$ = newTreeNode();
						$$->type = TN_PARAMLIST;
						$$->numOperands = 1;
						$$->operands[0] = $1;
					} 
		| parameter ',' formal_args {$$ = $3;
									 $$->operands[$$->numOperands++] = $1;
									}
		;

class_body:
		 '{' statements methods '}' {$$ = newTreeNode();
		 							 $$->type = TN_CLASSBODY;
		 							 $$numOperands = 2;
		 							 $$->operands[0] = $2;
		 							 $$->operands[1] = $3;
		 							 } ;

methods:
		/*Zero or more methods*/ {;}
		| method methods {$1->pNextStatement = $2;
						  $$ = $1;}
		;

method:
		  DEF IDENT '(' formal_args ')' ':' type statement_block {$$ = newTreeNode();
		  															$$->type = TN_METHOD;
		  															$$->sval = strdup($2);
		  															$$->numOperands = 2;
		  															$$->ival = $7;
		  															$$->operands[0] = $4;
		  															$$->operands[1] = $8;}
		| DEF IDENT '(' formal_args ')' statement_block {$$ = newTreeNode();
														$$->type = TN_METHOD;
														$$->sval = strdup($2);
														$$->numOperands = 2;
														$$->ival = NONE_TYPE;
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
		  elseif_header statement_block {$$ = newTreeNode();
										$$->type = TN_IF;
										$$->numOperands = 2;
										$$->operands[0] = $1;
										$$->operands[1] = $2;}
		| elseif_header statement_block else_clause {$$ = newTreeNode();
													$$->type = TN_IF;
													$$->numOperands = 3;
													$$->operands[0] = $1;
													$$->operands[1] = $2;
													$$->operands[2] = $3;}
		| elseif_header statement_block elseif_block {$$ = newTreeNode();
													$$->type = TN_IF;
													$$->numOperands = 3;
													$$->operands[0] = $1;
													$$->operands[1] = $2;
													$$->operands[2] = $3;}
		;

if_statement: 
		  if_header statement_block {$$ = newTreeNode();
		  							 $$->type = TN_IF;
		  							 $$->numOperands = 2;
		  							 $$->operands[0] = $1;
		  							 $$->operands[1] = $2;
		  							}
		| if_header statement_block else_clause {$$ = newTreeNode();
												 $$->type = TN_IF;
												 $$->numOperands = 3;
												 $$->operands[0] = $1;
												 $$->operands[1] = $2;
												 $$->operands[2] = $3;
												}
		| if_header statement_block elseif_block {$$ = newTreeNode();
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
		| WHILE '(' r_expr ')' statement_block {$$ = newTreeNode();
												$$->type = TN_WHILE;
												$$->numOperands = 2;
												$$->operands[0] = $3;
												$$->operands[1] = $5;}

		| RETURN r_expr ';' {$$ = newTreeNode();
							 $$->type = TN_RETURN;
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

		| l_expr '=' r_expr ';' {$$ = newTreeNode();
								 $$->type = TN_ASSIGNMENT;
								 $$->numOperands = 2;
								 $$->operands[0] = $1;
								 $$->operands[1] = $3;
								 }

		| l_expr ':' IDENT '=' r_expr ';' {
								 $$ = newTreeNode();
								 $$->type = TN_ASSIGNMENT;
								 $$->sval = $3
								 $$->numOperands = 2;
								 $$->operands[0] = $1;
								 $$->operands[1] = $5;}

		| r_expr ';' {$$ = newTreeNode();
					  $$->type = TN_EXPR_STATEMENT;
					  $$->numOperands = 1;
					  $$->operands[0] = $1}
		;
/*
elseif:
		  /*Else if {;}
		| ELIF r_expr statement_block elseif {;}
		| ELSE statement_block {;}
		;
*/

l_expr:	IDENT { $$ = newTreeNode();
				$$->type = TN_LEFT_EXPRESSION;
				$$->sval = strdup($1)}
		| r_expr DOT IDENT {$$ = newTreeNode();
							$$->TN_LEFT_EXPRESSION;
							$$->numOperands = 1;
							$$->operands[0] = $1;}
		;

boolean_operator: OR {$$ = strdup($1);}
				| AND {$$ = strdup($1);}
				| EQ {$$ = strdup($1);}
				| GEQ {$$ = strdup($1);}
				| LEQ {$$ = strdup($1);}
				| GT {$$ = strdup($1);}
				| LT {$$ = strdup($1);}
				;

arithmetic_operator:  PLUS {$$ = strdup($1);}
					| MINUS {$$ = strdup($1);}
					| MULT {$$ = strdup($1);}
					| DIVIDE {$$ = strdup($1);}
					; 



r_expr:  r_expr boolean_operator r_expr {$$ = newTreeNode();
										 $$->type = TN_BOOLEAN_EXPRESSION;
										 $$->sval = strdup($2);
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $3;}


		| r_expr arithmetic_operator r_expr {$$ = newTreeNode();
										 $$->type = TN_ARITHMETIC_EXPRESSION;
										 $$->sval = strdup($2);
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $3;}
		| testFinal {$$ = newTreeNode();
					 $$->type = TN_INTERMEDIATE_EXPRESSION;
					 $$->numOperands = 1;
					 $$->operands[0] = $1;
					}
		;

testFinal: /*Empty*/  {;}
	| IDENT {$$ = newTreeNode();
			$$->type = TN_IDENT_EXPRESSION;
			$$->sval = strdup($1);}
	| r_expr dotMatcher {$$ = newTreeNode();
						$$->type = TN_DEREF;
						$$->numOperands = 2;
						$$->operands[0] = $1;
						$$->operands[1] = $2;}
	| IDENT '(' actual_args ')' {$$ = newTreeNode();
								$$->type = TN_FUNCTION_CALL_EXPRESSION;
								$$->sval = strdup($1);
								$$->numOperands = 1;
								$$->operands[0] = $3;}
	| STRING_LIT {$$ = newTreeNode();
			$$->type = TN_STRING_EXPRESSION;
			$$->sval = strdup($1);}
	| INT_LIT {$$ = newTreeNode();
			$$->type = TN_INTEGER_EXPRESSION;
			$$->ival = $1;}
	| '(' r_expr ')' {$$ = $2;}
	;

dotMatcher: DOT IDENT '(' actual_args ')' {$$ = newTreeNode();
										   $$->type = TN_DEREFERENCE_FUNC;
										   $$->sval = strdup($2);
										   $$->numOperands = 1;
										   $$->operands[0] = $4;}
		|	DOT IDENT {$$ = newTreeNode();
					   $$->type = TN_DEREFERENCE_VAR;
					   $$->sval = strdup($2);
					   }


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
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << lineNumber << ": " << s << endl;
	// might as well halt now:
	exit(-1);
}