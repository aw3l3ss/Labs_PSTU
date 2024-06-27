#include <SFML/Graphics.hpp>
#include "BST.h"

void displayMenu() {
    std::cout << "Binary Search Tree Operations:\n";
    std::cout << "1. Insert node\n";
    std::cout << "2. Delete node\n";
    std::cout << "3. Search node\n";
    std::cout << "4. Pre-order traversal\n";
    std::cout << "5. In-order traversal\n";
    std::cout << "6. Post-order traversal\n";
    std::cout << "7. Print tree (2D)\n";
    std::cout << "8. Visualize tree (SFML)\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BST tree;
    int choice, key;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                tree.insert_node(key);
                std::cout << "Node inserted.\n";
                break;
            case 2:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                tree.delete_node(key);
                std::cout << "Node deleted.\n";
                break;
            case 3:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                if (tree.search_node(key))
                    std::cout << "Node found.\n";
                else
                    std::cout << "Node not found.\n";
                break;
            case 4:
                std::cout << "Pre-order traversal: ";
                tree.preorder();
                break;
            case 5:
                std::cout << "In-order traversal: ";
                tree.inorder();
                break;
            case 6:
                std::cout << "Post-order traversal: ";
                tree.postorder();
                break;
            case 7:
                std::cout << "Tree (2D):\n";
                tree.print2D();
                break;
            case 8:
                std::cout << "Visualizing tree with SFML...\n";
                {
                    sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Search Tree Visualization");

                    while (window.isOpen()) {
                        sf::Event event;
                        while (window.pollEvent(event)) {
                            if (event.type == sf::Event::Closed)
                                window.close();
                        }

                        window.clear(sf::Color::Black);
                        tree.draw(window);
                        window.display();
                    }
                }
                break;
            case 9:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}