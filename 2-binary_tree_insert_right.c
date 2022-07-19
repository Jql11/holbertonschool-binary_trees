#include <stdio.h>
#include "binary_trees.h"


/**
 * create_null_point_node_right - creates an empty node to insert
 * @value: value to put in the new node
 * Return: pointer to empty node or NULL if failure
 */
binary_tree_t *create_null_point_node_right(int value)
{
	binary_tree_t *null_point_node = NULL;

	null_point_node = malloc(sizeof(binary_tree_t));
	if (!null_point_node)
		return (NULL);

	null_point_node->n = value;
	null_point_node->parent = NULL;
	null_point_node->left = NULL;
	null_point_node->right = NULL;

	return (null_point_node);
}

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value:  value to put in the new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = create_null_point_node_right(value);
	if (!new_node)
		return (NULL);

	new_node->parent = parent;

	if (parent->right)
	{
		new_node->right = parent->right;
		new_node->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
