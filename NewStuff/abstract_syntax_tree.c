#include "abstract_syntax_tree.h"

int nodeIdCounter = 1;

struct tree_node* newTreeNode()
{
	struct tree_node* n = (struct tree_node*) malloc(sizeof(struct tree_node));
	n->type = TN_NOTYPE;
	n->id = nodeIdCounter++;
	n->numOperands = 0;
	/*n->ival = 0;*/
	n->sval = NULL;
	n->dataType = NULL;
	//n->superval = NULL;
	n->pNextStatement = NULL;
	n->operands = (struct tree_node**) malloc(sizeof(struct tree_node*) * MAX_OPERANDS);
	int i;
	for (i = 0; i < MAX_OPERANDS; i++)
		n->operands[i] = NULL;
	return n;
}

char* whichEnum(node_type_tag e){
	switch(e)
	{
		case TN_NOTYPE: return (char*) "TN_NOTYPE";
		break;
		case TN_PROGRAM: return (char*) "TN_PROGRAM";
		break;
		case TN_CLASSDEF: return (char*) "TN_CLASSDEF";
		break;
		case TN_CLASS: return (char*) "TN_CLASS";
		break;
		case TN_PARAMETER: return (char*) "TN_PARAMETER";
		break;
		case TN_PARAMLIST: return (char*) "TN_PARAMLIST";
		break;
		case TN_CLASSBODY: return (char*) "TN_CLASSBODY";
		break;
		case TN_METHOD: return (char*) "TN_METHOD";
		break;
		case TN_IF: return (char*) "TN_IF";
		break;
		case TN_WHILE: return (char*) "TN_WHILE";
		break;
		case TN_RETURN: return (char*) "TN_RETURN";
		break;
		case TN_ASSIGNMENT: return (char*) "TN_ASSIGNMENT";
		break;
		case TN_EXPR_STATEMENT: return (char*) "TN_EXPR_STATEMENT";
		break;
		case TN_LEFT_EXPRESSION: return (char*) "TN_LEFT_EXPRESSION";
		break;
		case TN_BOOLEAN_EXPRESSION: return (char*) "TN_BOOLEAN_EXPRESSION";
		break;
		case TN_ARITHMETIC_EXPRESSION: return (char*) "TN_ARITHMETIC_EXPRESSION";
		break;
		case TN_INTERMEDIATE_EXPRESSION: return (char*) "TN_INTERMEDIATE_EXPRESSION";
		break;
		case TN_IDENT_EXPRESSION: return (char*) "TN_IDENT_EXPRESSION";
		break;
		case TN_DEREF: return (char*) "TN_DEREF";
		break;
		case TN_FUNCTION_CALL_EXPRESSION: return (char*) "TN_FUNCTION_CALL_EXPRESSION";
		break;
		case TN_STRING_EXPRESSION: return (char*) "TN_STRING_EXPRESSION";
		break;
		case TN_INTEGER_EXPRESSION: return (char*) "TN_INTEGER_EXPRESSION";
		break;
		case TN_DEREFERENCE_FUNC: return (char*) "TN_DEREFERENCE_FUNC";
		break;
		case TN_DEREFERENCE_VAR: return (char*) "TN_DEREFERENCE_VAR";
		break;
		case TN_ARGLIST: return (char*) "TN_ARGLIST";
		break;
	}
}