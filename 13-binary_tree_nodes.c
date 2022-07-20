#include "binary_trees.h"

/**
 * node_is_leaf - checks if node is leaf
 * @node: pointer to the node to check
 * Return: 1 if leaf and 0 if not
 */
int node_is_leaf(const binary_tree_t *node)
{
	if ((node) && (node->left == NULL) && (node->right == NULL))
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || node_is_leaf(tree))
		return (count);

	count = binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count + 1);
}
