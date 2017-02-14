#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#define MAX_OPERANDS 250
using namespace std;



typedef enum node_type_tag 
{
    TN_NOTYPE = 0,
    TN_PROGRAM = 1,
    TN_CLASSDEF = 2,
    TN_CLASS = 3,
    TN_PARAMETER = 4,
    TN_PARAMLIST = 5,
    TN_CLASSBODY = 6,
    TN_METHOD = 7,
    TN_IF = 8,
    TN_WHILE = 9,
    TN_RETURN = 10,
    TN_ASSIGNMENT = 11,
    TN_EXPR_STATEMENT = 12,
    TN_LEFT_EXPRESSION = 13,
    TN_BOOLEAN_EXPRESSION = 14,
    TN_ARITHMETIC_EXPRESSION = 15,
    TN_INTERMEDIATE_EXPRESSION = 16,
    TN_IDENT_EXPRESSION = 17,
    TN_DEREF = 18,
    TN_FUNCTION_CALL_EXPRESSION = 19,
    TN_STRING_EXPRESSION = 20,
    TN_INTEGER_EXPRESSION = 21,
    TN_DEREFERENCE_FUNC = 22,
    TN_DEREFERENCE_VAR = 23,
    TN_ARGLIST = 24




} node_type;

char* whichEnum(node_type_tag e);
void createMapping(char* subclass, char* superclass);
void printMap();

typedef enum identifier_type_tag
{
	INTEGER_LITERAL,
	STRING_LITERAL,
	NONE_TYPE
} identifier_type;

struct tree_node
{
    // The parser will assign this variable one of the enumerated type values
    // above according to the kind of node it was created to be.
    node_type type; 

    // This connects to the next statement or class in the program
    struct tree_node* pNextStatement;

	// Node id
	int id;

	// Number of operands used in this node
	int numOperands;


	// String value of this tree node, if needed
	char* sval;
    char* dataType;

	// String value of superclass, if needed
	/*char* superval;*/

	// Operand pointers
    struct tree_node** operands;
};

struct classInfo{
    char* className;
    char* superClassName;
    struct tree_node* ptrToSuperclass;
};

void printTree(struct tree_node* node);
extern vector<classInfo*> mappings;
struct tree_node* newTreeNode();
bool checkWellFormedness();
bool constructorWrapper(struct tree_node* root);