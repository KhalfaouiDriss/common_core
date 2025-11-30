#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct node
{
    enum
    {
        ADD = 4,
        MULTI,
        VAL
    } type;
    int val;
    struct node *l;
    struct node *r;
} node;

node *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (0);
    *ret = n;
    return (ret); 
}

void destroy_tree(node *tree)
{
    if (!tree)
        return ;
    if(tree->type != VAL)
    {
        destroy_tree(tree->l);
        destroy_tree(tree->r);
    }
    free(tree);
}

void unexpected(char c)
{
    if(c)
        printf("");
    else
        printf("");
    exit(1);
}

int accept(char**s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

node *parse_factor(char **s)
{
    if (isdigit(*s))
    {
        node n = {VAL, **s - '0', NULL, NULL};
        (*s)++;
        return (new_node(n));
    }
    if (accept(s, '('))
    {
        node *n = parse_expr(s);
        if (!expect(s, ')'))
        {
            destroy_tree(n);
            return (0);
        }
        return (n);
    }
    unexpected(**s);
    return (0);
}

node *parse_term(char **s)
{
    node *left = parse_factor(s);
    if (!left)
        return (0);
    while(accept(s, '*'))
    {
        node *right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return (0);
        }
        node n = {MULTI, 0, left, right};
        left = new_node(n);
        if (!left)
        {
            destroy_tree(right);
            return (0);
        }
    }
    return (left);
}

node *parse_expr(char **s)
{
    node *left = parse_term(s);
    if (!left)
        return (0);
    while(accept(s, '+'))
    {
        node *right = parse_term(s);
        if (!right)
        {
            destroy_tree(left);
            return (0);
        }
        node n = {ADD, 0 , left, right};
        left = new_node(n);
        if (!left)
        {
            destroy_tree(right);
            return (0);
        }
    }
    return (left);
}

int main(int ac, char **av)
{
    char *s;
    node *tree;

    if (ac != 2)
        return (1);
    tree = parse_expr(&s);
}