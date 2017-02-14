#include "abstract_syntax_tree.h"
using namespace std;

int nodeIdCounter = 1;


vector<classInfo*> mappings;

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

void createMapping(char* subclass, char* superclass){

	for(int i = 0; i < mappings.size(); i++)
	{
		if(strcmp(mappings[i]->className, subclass) == 0)
		{
			cout << "You cannot add a class of a particular name more than once" << endl;
			return;
		}
	}

	struct classInfo* n = (struct classInfo*) malloc(sizeof(struct classInfo));

	n->className = subclass;
	n->superClassName = superclass;

	mappings.push_back(n);
}

void printMap(){
	for(int i = 0; i < mappings.size(); i++){
		cout << mappings[i]->className << " " << mappings[i]->superClassName << endl;
	}
}




bool checkPair(char* subclass, char* superclass, int depth, vector<char*> visited)
{

	if(strcmp(subclass, (char*) "Obj") == 0){
		return true;
	}
	bool inMap = false;

	for(int i = 0; i < mappings.size(); i++){
			
		if(strcmp(mappings[i]->className, superclass) == 0)
			inMap = true;
	}
	if(!inMap)
	{
		return inMap;
	}


	for(int i = 0; i < visited.size(); i++)
	{
		if(strcmp(subclass, visited[i]) == 0)
		{
			return false;
		}
	}


	 {
		visited.push_back(subclass);
		char* nextSuper;
		for(int i = 0; i < mappings.size(); i++)
		{	
			if(strcmp(superclass, mappings[i]->className) == 0)
			{
				nextSuper = mappings[i]->superClassName;
			}
		}
		return checkPair(superclass, nextSuper, ++depth, visited);
	}

}




bool checkWellFormedness(){
	for(int i = 0; i < mappings.size(); i++)
	{
		vector<char*> visited;
		int d = 0;
		if(!checkPair(mappings[i]->className, mappings[i]->superClassName, d, visited))
			return false;
	}
	return true;
}

bool checkAllConstructors(struct tree_node* root)
{
	//Constructors will look just like function calls but it's ok because right here we know that we are only searching through the statements, which cannot be function calls

	if(root->type == TN_FUNCTION_CALL_EXPRESSION)
	{
		cout << "Found a constructor..." << endl;
		for(int i = 0; i < mappings.size(); i++)
		{
			cout << "Checking all mappings...  Current mapping is:   SUB: " << mappings[i]->className << endl;
			if(strcmp(mappings[i]->className, root->sval) == 0){
				return true;
			}
		}
		return false;
	}
	else{

		bool myBool = true;

		for(int i = 0; i < root->numOperands; i++)
		{
			myBool &= checkAllConstructors(root->operands[i]);
		}
		return myBool;
	}
}

bool constructorWrapper(struct tree_node* root)
{
	if(root->type == TN_PROGRAM)
	{
		cout << "Checking statements..." << endl;
		return checkAllConstructors(root->operands[1]);
	}
	else
	{
		cout << "This only works on root nodes" << endl;
		return false;
	}
}


void printTree(struct tree_node* node)
{
	if (!node)
	{
		cout << "null value, returning..." << endl;
		return;
	}
	else
	{
		cout << "node not null" << endl;
		if(node->type){
			cout << "abc" << endl;
			
			cout << "node type: " << whichEnum(node->type) << endl;
		}
		cout << "asdf" << endl;
		if(node->sval)
		{
			cout << "string value: " << node->sval << endl;
		}
		cout << "printing children" << endl;
		if(node->numOperands > 0)
		{
			for(int i = 0; i < node->numOperands; i++)
			{
				cout << "num ops: " << node->numOperands << endl;
				printTree(node->operands[i]);
			}
		}
	}
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