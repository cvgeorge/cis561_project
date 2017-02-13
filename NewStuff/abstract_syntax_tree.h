#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAX_OPERANDS 250

typedef enum node_type_tag 
{
    TN_NOTYPE,
    TN_PROGRAM,
    TN_CLASSDEF,
    TN_CLASS,
    TN_PARAMETER,
    TN_PARAMLIST,
    TN_CLASSBODY,
    TN_METHOD,
    TN_IF,
    TN_WHILE,
    TN_RETURN,
    TN_ASSIGNMENT,
    TN_EXPR_STATEMENT,
    TN_LEFT_EXPRESSION,
    TN_BOOLEAN_EXPRESSION,
    TN_ARITHMETIC_EXPRESSION,
    TN_INTERMEDIATE_EXPRESSION,
    TN_IDENT_EXPRESSION,
    TN_DEREF,
    TN_FUNCTION_CALL_EXPRESSION,
    TN_STRING_EXPRESSION,
    TN_INTEGER_EXPRESSION,
    TN_DEREFERENCE_FUNC,
    TN_DEREFERENCE_VAR,
    TN_ARGLIST




} node_type;

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

	// Integer value of this tree node, if needed
	int ival;

	// String value of this tree node, if needed
	char* sval;

	// String value of superclass, if needed
	char* superval;

	// Operand pointers
    struct tree_node** operands;
};

struct tree_node* newTreeNode();