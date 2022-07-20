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
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);

	if (node_is_leaf(tree))
		return (1);

	count = binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);

	return (count);
}
