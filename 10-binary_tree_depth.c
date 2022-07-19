#include "binary_trees.h"

/**
 * is_node_root - checks if node is root
 * @node: pointer to the node to check
 * Return: 1 if root and 0 if not
 */
int is_node_root(const binary_tree_t *node)
{
	if ((node) && (node->parent == NULL))
		return (1);
	return (0);
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth.
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree || is_node_root(tree))
		return (0);

	depth = binary_tree_depth(tree->parent);

	return (1 + depth);
}

/**
 * other possible solution - we just wanteed to keep with the recursion theme.
 * --------------------
 * int count = 0;
 *
 * while (node->parent != NULL)
 * {
 *	count++;
 *	node = node->parent;
 * }
 *
 * return (count)
 */
