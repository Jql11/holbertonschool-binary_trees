#include "binary_trees.h"

/**
 * is_node_a_leaf - checks if node is leaf
 * @node: pointer to the node to check
 * Return: 1 if leaf and 0 if not
 */
int is_node_a_leaf(const binary_tree_t *node)
{
	if ((node) && (node->left == NULL) && (node->right == NULL))
		return (1);
	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full or 0 if not.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_sub_full, right_sub_full;

	if (!tree)
		return (0);
	if (is_node_a_leaf(tree))
		return (1);

	left_sub_full = binary_tree_is_full(tree->left);
	right_sub_full = binary_tree_is_full(tree->right);

	if (left_sub_full == 0 || right_sub_full == 0)
		return (0);

	return (1);
}
