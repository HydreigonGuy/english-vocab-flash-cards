/*
** EPITECH PROJECT, 2022
** vocab
** File description:
** Word
*/

#ifndef WORD_HPP_
#define WORD_HPP_

#include <string>

#include <iostream>

class Word {
    public:
        Word()
        {
            _word = "";
            _definition = "";
            _guessed = true;
        }
        Word(std::string word, std::string definition)
        {
            _word = word;
            _definition = definition;
            _guessed = false;
        }
        std::string get_word()
        {
            return (this->_word);
        }
        std::string get_definition()
        {
            return (this->_definition);
        }
        bool is_guessed()
        {
            return (this->_guessed);
        }
        void guess()
        {
            this->_guessed = true;
        }
        ~Word() = default;

    protected:
    private:
        std::string _word;
        std::string _definition;
        bool _guessed;
};

#endif /* !WORD_HPP_ */
