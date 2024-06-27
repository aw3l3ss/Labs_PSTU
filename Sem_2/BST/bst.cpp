#include "bst.h"

#define SPACE 10

int BST::height(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

int BST::max(int a, int b) {
    return (a > b) ? a : b;
}

int BST::get_balance(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

Node *BST::right_rotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *BST::left_rotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *BST::min_value_node(Node *node) {
    Node *current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node *BST::insert_node(Node *node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert_node(node->left, key);
    } 
    
    else if (key > node->key) {
        node->right = insert_node(node->right, key);
    } 
    
    else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key) {
        return right_rotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        return left_rotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void BST::insert_node(int key) {
    root = insert_node(root, key);
}

Node *BST::delete_node(Node *root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } 
    
    else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } 
    
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } 
            
            else {
                *root = *temp;
            }

            delete temp;
        } 
        
        else {
            Node *temp = min_value_node(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0) {
        return right_rotate(root);
    }

    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0) {
        return left_rotate(root);
    }

    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void BST::delete_node(int key) {
    root = delete_node(root, key);
}

Node *BST::search_node(Node *root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search_node(root->left, key);
    }

    return search_node(root->right, key);
}

Node *BST::search_node(int key) {
    return search_node(root, key);
}

void BST::preorder(Node *root) {
    if (root != nullptr) {
        std::cout << root->key <<  " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key <<  " ";
        inorder(root->right);
    }
}

void BST::postorder(Node *root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->key <<  " ";
    }
}

void BST::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void BST::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BST::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void BST::print2D_util(Node *root, int space) {
    if (root == nullptr) {
        return;
    }

    space += SPACE;

    print2D_util(root->right, space);

    std::cout << std::endl;
    for (int i = SPACE; i < space + root->height; i++) {
        std::cout << " ";
    }

    std::cout << root->key << "\n";

    print2D_util(root->left, space);
}

void BST::print2D() {
    print2D_util(root, 0);
}

void BST::draw_tree(sf::RenderWindow &window, Node *root, int x, int y, int horizontal_spacing, int level) {
    if (root == nullptr) {
        return;
    }

    int node_radius = 20;
    sf::CircleShape circle(node_radius);

    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x - node_radius, y - node_radius);
    window.draw(circle);

    sf::Font font;
    if (!font.loadFromFile("arialmt.ttf")) {
        std::cout << "Error loading font" << std::endl;
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(root->key));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(x - 10, y - 15);
    window.draw(text);

    if (root->left != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y + node_radius)),
            sf::Vertex(sf::Vector2f(x - horizontal_spacing, y + 100 - node_radius))
        };

        window.draw(line, 2, sf::Lines);
        draw_tree(window, root->left, x - horizontal_spacing, y + 100, horizontal_spacing / 2, level + 1);
    }

    if (root->right != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y + node_radius)),
            sf::Vertex(sf::Vector2f(x + horizontal_spacing, y + 100 - node_radius))
        };

        window.draw(line, 2, sf::Lines);
        draw_tree(window, root->right, x + horizontal_spacing, y + 100, horizontal_spacing / 2, level + 1);
    }
}

void BST::draw(sf::RenderWindow &window) {
    draw_tree(window, root, window.getSize().x / 2, 50, window.getSize().x / 4, 0);
}