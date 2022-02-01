/*
** EPITECH PROJECT, 2022
** vocab
** File description:
** main
*/

#include "../include/WordList.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>

void event_handelling(sf::RenderWindow *window, WordList &list, Word *next)
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.key.code == sf::Keyboard::Space) {
                list.get_word(list.get_i())->guess();
                list.set_display_definition(false);
                next = list.get_next_word();
            }
            if (event.key.code == sf::Keyboard::S) {
                list.set_display_definition(false);
                next = list.get_next_word();
            }
            if (event.key.code == sf::Keyboard::D)
                list.set_display_definition(true);
        }
    }
}

void draw_window(sf::RenderWindow *window, Word *next_word, bool def)
{
    sf::Font font;
    font.loadFromFile("assets/arial.ttf");
    sf::Text text(next_word->get_word(), font, 50);

    if (def)
        text.setString(next_word->get_definition());
    text.setPosition(100, 100);
    window->clear();
    window->draw(text);
    window->display();
}

void draw_end(sf::RenderWindow *window)
{
    sf::Font font;
    font.loadFromFile("assets/arial.ttf");
    sf::Text text("You Guessed All The Words", font, 50);

    text.setPosition(100, 100);
    window->clear();
    window->draw(text);
    window->display();
}

int main(int ac, char **av)
{
    srand (time(NULL));

    WordList list;
    sf::RenderWindow window(sf::VideoMode(800, 300), "Vocab");
    Word *next_word = list.get_next_word();

    while (window.isOpen()) {
        event_handelling(&window, list, next_word);
        next_word = list.get_word(list.get_i());
        if (next_word->is_guessed())
            draw_end(&window);
        else
            draw_window(&window, next_word, list.get_display_definition());
    }
}