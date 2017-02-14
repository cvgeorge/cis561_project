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
extern struct tree_node* treeRoot;

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

start: program {treeRoot = $1; cout << "Finished parse with no errors" << endl;};

program: class_declarations statements {$$ = newTreeNode(); 
										$$->type = TN_PROGRAM;
										$$->numOperands = 2;
										$$->operands[0] = $1;
										$$->operands[1] = $2;} ;
		 /*class statement*/ 

class_declarations:
		 /*Zero or more class declarations*/  {;}
		| class class_declarations {$1->pNextStatement = $2;
									$$ = $1;}
		;

statements:
		/*Zero or more statements*/ {;}
		| statement statements {
								$1->pNextStatement = $2;
								$$ = $1;}
		;

class:
		 class_signature class_body {$$ = newTreeNode(); 
		 							 $$->type = TN_CLASS;
		 							 $$->numOperands = 2;
		 							 $$->operands[0] = $1;
		 							 $$->operands[1] = $2;} ;

class_signature:
		 CLASS IDENT '(' formal_args ')' EXTENDS IDENT {$$ = newTreeNode();
		 												
		 												$$->type = TN_CLASSDEF;
		 												/*$$->sval = ($2); */
		 												//
		 												$$->sval = ($2);
		 												
		 												$$->numOperands = 1;
		 												
		 												$$->operands[0] = $4;


		 												createMapping((char*) $2, (char*) $7);
		 												} ;
		| CLASS IDENT '(' formal_args ')' { $$ = newTreeNode(); 
											$$->type = TN_CLASSDEF;
											$$->sval = ($2);
											$$->numOperands = 1;
											$$->operands[0] = $4;

											createMapping((char*) $2, (char*)"Obj");} ;
/*
type: INTEGER { $$ = INTEGER_LITERAL;}
	| STRING {$$ = STRING_LITERAL;}
	| {$$ = NONE_TYPE;}
	;
*/
parameter: IDENT ':' IDENT {	$$ = newTreeNode(); 
							$$->type = TN_PARAMETER;
							$$->sval = ($1);

							$$->dataType = ($3);
							/*$$->ival = $3;*/}
							;

formal_args:
		/*empty*/ {$$ = newTreeNode();
					$$->type = TN_PARAMLIST;}
		| parameter {   
						$$ = newTreeNode(); 
						$$->type = TN_PARAMLIST;
						$$->numOperands = 1;
						$$->operands[0] = $1;
					} 
		| parameter ',' formal_args {
									 $$ = $3;
									 $$->operands[$$->numOperands++] = $1;
									}
		;

class_body:
		 '{' statements methods '}' {$$ = newTreeNode(); 
		 							 $$->type = TN_CLASSBODY;
		 							 $$->numOperands = 2;
		 							 $$->operands[0] = $2;
		 							 $$->operands[1] = $3;
		 							 } ;

methods:
		/*Zero or more methods*/ {;}
		| method methods {
							$1->pNextStatement = $2;
						  $$ = $1;}
		;

method:
		  DEF IDENT '(' formal_args ')' ':' IDENT statement_block {$$ = newTreeNode(); 
		  															$$->type = TN_METHOD;
		  															$$->sval = ($2);
		  															$$->dataType = $7;
		  															$$->numOperands = 2;
		  															/*$$->ival = $7;*/
		  															$$->operands[0] = $4;
		  															$$->operands[1] = $8;}
		| DEF IDENT '(' formal_args ')' statement_block {$$ = newTreeNode(); 
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
								 $$->sval = $3;
								 $$->numOperands = 2;
								 $$->operands[0] = $1;
								 $$->operands[1] = $5;}

		| r_expr ';' {$$ = newTreeNode(); 
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

l_expr:	IDENT { $$ = newTreeNode(); 
				$$->type = TN_LEFT_EXPRESSION;

				$$->sval = ($1);
				}
		| r_expr DOT IDENT {$$ = newTreeNode(); 
							$$->type = TN_LEFT_EXPRESSION;
							$$->numOperands = 1;
							$$->operands[0] = $1;}
		;

boolean_operator: OR r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| AND r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| EQ r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| GEQ r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| LEQ r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| GT r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}

				| LT r_expr {$$ = newTreeNode(); 
							 $$->type = TN_BOOLEAN_EXPRESSION;
							 $$->sval = ($1);
							 $$->numOperands = 1;
							 $$->operands[0] = $2;}
				;


arithmetic_operator:  PLUS r_expr {  $$ = newTreeNode(); 
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| MINUS r_expr {$$ = newTreeNode(); 
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| MULT r_expr {$$ = newTreeNode(); 
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					| DIVIDE r_expr {$$ = newTreeNode(); 
									 $$->type = TN_ARITHMETIC_EXPRESSION;
									 $$->sval = ($1);
									 $$->numOperands = 1;
									 $$->operands[0] = $2;}
					; 


r_expr:  r_expr boolean_operator{$$ = newTreeNode(); 
										 $$->type = TN_BOOLEAN_EXPRESSION;
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $2;}
		| NOT r_expr {$$ = newTreeNode();
						$$->type = TN_BOOLEAN_NOT;
										 $$->numOperands = 1;
										 $$->operands[0] = $2;
										 }								 

		| r_expr arithmetic_operator {$$ = newTreeNode(); 
										 $$->type = TN_ARITHMETIC_EXPRESSION;
										 $$->numOperands = 2;
										 $$->operands[0] = $1;
										 $$->operands[1] = $2;}
		| testFinal {$$ = newTreeNode(); 
					 $$->type = TN_INTERMEDIATE_EXPRESSION;
					 $$->numOperands = 1;
					 $$->operands[0] = $1;
					}
		;

testFinal: /*Empty  {;}
	|*/ IDENT {$$ = newTreeNode(); 
			$$->type = TN_IDENT_EXPRESSION;
			$$->sval = ($1);}
	| r_expr dotMatcher {$$ = newTreeNode(); 
						$$->type = TN_DEREF;
						$$->numOperands = 2;
						$$->operands[0] = $1;
						$$->operands[1] = $2;}
	| IDENT '(' actual_args ')' {$$ = newTreeNode(); 
								$$->type = TN_FUNCTION_CALL_EXPRESSION;
								$$->sval = ($1);
								$$->numOperands = 1;
								$$->operands[0] = $3;}
	| STRING_LIT {$$ = newTreeNode(); 
			$$->type = TN_STRING_EXPRESSION;
			$$->sval = ($1);}
	| INT_LIT {$$ = newTreeNode(); 
			$$->type = TN_INTEGER_EXPRESSION;
			$$->sval = $1;
			/*$$->ival = $1;*/}
	| '(' r_expr ')' {$$ = $2;}
	;

dotMatcher: DOT IDENT '(' actual_args ')' {$$ = newTreeNode(); 
										   $$->type = TN_DEREFERENCE_FUNC;
										   $$->sval = ($2);
										   $$->numOperands = 1;
										   $$->operands[0] = $4;}
		|	DOT IDENT {$$ = newTreeNode(); 
					   $$->type = TN_DEREFERENCE_VAR;
					   $$->sval = ($2);
					   }


actual_args:
		 /*No arguments*/ {$$ = newTreeNode();
							$$->type;
							}
		| r_expr ',' actual_args {$$ = $3;
									$$->operands[$$->numOperands++] = $1;}
		| r_expr {$$ = newTreeNode(); 
				  $$->type = TN_ARGLIST;
				  $$->numOperands = 1;
				  $$->operands[0] = $1;}




%%
int counter = 0;


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

	createMapping((char*) "Obj", (char*) "Obj");
	createMapping((char*) "Integer", (char*) "Obj");
	createMapping((char*) "String", (char*) "Obj");
	createMapping((char*) "Nothing", (char*) "Obj");

	// parse through the input until there is no more:
	do {
		condition = yyparse();
	} while (!feof(yyin));
	

	

	// Uncomment to print the known classes
	/* printMap();*/


	// Uncomment to check class heirarchy for well-formedness
	/*
		if(checkWellFormedness()){
			cout << "Tree is well formed!" << endl;
		}
		else{
			cout << "Tree is NOT well formed!" << endl;
		}
	*/

	//Uncomment to print tree
	/*printTree(treeRoot);*/

	//Uncomment to check if constructor calls are valid
	/*
	if(constructorWrapper(treeRoot))
	{
		cout << "Constructors look good" << endl;
	}
	else{
		cout << "Constructors look not so good..." << endl;
	}
	*/
	
}

void yyerror(const char *s) {
	cout << lineNumber << ": " << s << endl;
	// might as well halt now:
	exit(-1);
}