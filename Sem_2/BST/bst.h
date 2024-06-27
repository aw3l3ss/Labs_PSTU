#ifndef BST_H
#define BST_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class BST {
    private:
        Node *root;

        Node *insert_node(Node *node, int key);
        Node *delete_node(Node *root, int key);
        Node *min_value_node(Node *node);
        Node *search_node(Node *node, int key);

        int height(Node *node);
        int max(int a, int b);
        int get_balance(Node *node);
        Node *right_rotate(Node *y);
        Node *left_rotate(Node *x);

        void preorder(Node *root);
        void inorder(Node *root);
        void postorder(Node *root);

        void print2D_util(Node *root, int space);
        void draw_tree(sf::RenderWindow &window, Node *root, int x, int y, int horizontal_spacing, int level);

    public:
        BST() : root(nullptr) {}

        void insert_node(int key);
        void delete_node(int key);
        Node *search_node(int key);

        void preorder();
        void inorder();
        void postorder();

        void print2D();
        void draw(sf::RenderWindow &window);
};

#endif