#include "binary_trees.h"
#include <stdio.h>

/**
 * tree_subset_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree
 */
size_t tree_subset_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	left = tree_subset_height(tree->left);
	right = tree_subset_height(tree->right);

	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: Balance Factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_sub_height = 0, right_sub_height = 0;

	if (!tree)
		return (0);

	left_sub_height = tree_subset_height(tree->left);
	right_sub_height = tree_subset_height(tree->right);

	return (left_sub_height - right_sub_height);
}

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_tree_balanced = (binary_tree_balance(tree) == 0) ? 1 : 0;
	int is_tree_full = binary_tree_is_full(tree);

	printf("b: %d\nf: %d\n",is_tree_balanced, is_tree_full);
	if (!tree)
		return (0);
	return (is_tree_balanced & is_tree_full);
}
