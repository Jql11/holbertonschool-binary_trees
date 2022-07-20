#include "binary_trees.h"

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
