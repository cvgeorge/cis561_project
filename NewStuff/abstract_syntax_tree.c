#include "abstract_syntax_tree.h"

int nodeIdCounter = 1;

struct tree_node* newTreeNode()
{
	struct tree_node* n = (struct tree_node*) malloc(sizeof(struct tree_node));
	n->type = TN_NOTYPE;
	n->id = nodeIdCounter++;
	n->numOperands = 0;
	n->ival = 0;
	n->sval = NULL;
	n->superval = NULL;
	n->pNextStatement = NULL;
	n->operands = (struct tree_node**) malloc(sizeof(struct tree_node*) * MAX_OPERANDS);
	int i;
	for (i = 0; i < MAX_OPERANDS; i++)
		n->operands[i] = NULL;
	return n;
}