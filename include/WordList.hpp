/*
** EPITECH PROJECT, 2022
** vocab
** File description:
** WordList
*/

#ifndef WORDLIST_HPP_
#define WORDLIST_HPP_

#include "Word.hpp"
#include <stdlib.h>

#include <iostream>

#define WORD_COUNT  16

class WordList {
    public:
        WordList()
        {
            _words[0] = new Word("Accountability", "Responsabilité");
            _words[1] = new Word("(to) Allocate", "Allouer, Distribuer");
            _words[2] = new Word("(to) Audit", "Auditer, Vérifier");
            _words[3] = new Word("Barter", "Troc");
            _words[4] = new Word("Bill", "Facture");
            _words[5] = new Word("Blockade", "Blocus");
            _words[6] = new Word("Charity", "Association Caritative");
            _words[7] = new Word("Child Labour", "Travail des enfents");
            _words[8] = new Word("Commitment", "Engagement");
            _words[9] = new Word("Corporate", "d'entreprise");
            _words[10] = new Word("Corporation", "Société, Entreprise");
            _words[11] = new Word("Counter-Productive", "Contre Productif");
            _words[12] = new Word("Customs Tarifs", "Tarifs Douaniers");
            _words[13] = new Word("Cuts", "Réductions");
            _words[14] = new Word("Decline", "Déclin");
            _words[15] = new Word("Downturn / Downswing", "Baisse d'activité");
            _display_definition = false;
            _i = 0;
        }
        Word *get_word(int i)
        {
            return (this->_words[i]);
        }
        ~WordList() = default;
        Word *get_next_word()
        {
            bool is_ended = true;
            Word *ret;
            int i = 0;

            for (int j = 0; j < WORD_COUNT; j++)
                if (!this->_words[j]->is_guessed())
                    is_ended = false;
            if (is_ended)
                return (new Word());
            while (ret->is_guessed()) {
                i = rand() % WORD_COUNT;
                ret = this->_words[i];
            }
            this->_i = i;
            return (ret);
        }
        bool get_display_definition()
        {
            return (this->_display_definition);
        }
        void set_display_definition(bool def)
        {
            this->_display_definition = def;
        }
        int get_i()
        {
            return (this->_i);
        }

    protected:
    private:
        Word *_words[WORD_COUNT];
        bool _display_definition;
        int _i;
};

#endif /* !WORDLIST_HPP_ */
