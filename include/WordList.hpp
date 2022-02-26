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

#define WORD_COUNT  72

class WordList {
    public:
        WordList()
        {
            _words[0] = new Word("Accountability", "Responsabilite");
            _words[1] = new Word("(to) Allocate", "Allouer, Distribuer");
            _words[2] = new Word("(to) Audit", "Auditer, Verifier");
            _words[3] = new Word("Barter", "Troc");
            _words[4] = new Word("Bill", "Facture");
            _words[5] = new Word("Blockade", "Blocus");
            _words[6] = new Word("Charity", "Association Caritative");
            _words[7] = new Word("Child Labour", "Travail des enfents");
            _words[8] = new Word("Commitment", "Engagement");
            _words[9] = new Word("Corporate", "d'entreprise");
            _words[10] = new Word("Corporation", "Societe, Entreprise");
            _words[11] = new Word("Counter-Productive", "Contre Productif");
            _words[12] = new Word("Customs Tarifs", "Tarifs Douaniers");
            _words[13] = new Word("Cuts", "Reductions");
            _words[14] = new Word("Decline", "Declin");
            _words[15] = new Word("Downturn / Downswing", "Baisse d'activite");
            _words[16] = new Word("Duty Free", "Detaxe");
            _words[17] = new Word("Efficient", "Efficace");
            _words[18] = new Word("(to) Empower", "Donner de l'autonomie a");
            _words[19] = new Word("Entrepreneur", "Chef d'entreprise");
            _words[20] = new Word("Ethical", "ethique");
            _words[21] = new Word("Ethics", "ethique");
            _words[22] = new Word("Export", "exporter");
            _words[23] = new Word("(to) face a problem", "etre confronte a un probleme");
            _words[24] = new Word("fairtrade", "commerce equitable");
            _words[25] = new Word("(to) fight for a cause", "defendre une cause");
            _words[26] = new Word("fraudulent", "frauduleux");
            _words[27] = new Word("global", "mondial");
            _words[28] = new Word("(to) haggle", "marchander");
            _words[29] = new Word("health coverage", "assurence santé");
            _words[30] = new Word("idealistic", "idealiste");
            _words[31] = new Word("imbalance", "desequilibre");
            _words[32] = new Word("impact on", "impacter");
            _words[33] = new Word("import", "importer");
            _words[34] = new Word("impoverish", "appauvrir");
            _words[35] = new Word("(to) improve", "amelirorer");
            _words[36] = new Word("insolvent", "insolvable");
            _words[37] = new Word("integrity", "integrite");
            _words[38] = new Word("investment", "investissement");
            _words[39] = new Word("issue", "probleme");
            _words[40] = new Word("life expectancy", "esperance de vie");
            _words[41] = new Word("management", "gestion");
            _words[42] = new Word("(to) need", "avoir besoin");
            _words[43] = new Word("niche", "creneau");
            _words[44] = new Word("overheads", "frais generaux");
            _words[45] = new Word("policy", "regles");
            _words[46] = new Word("poor", "pauvre");
            _words[47] = new Word("poverty", "pauvrete");
            _words[48] = new Word("principled", "de principe");
            _words[49] = new Word("priority", "priorite");
            _words[50] = new Word("(to) promote", "promouvoir");
            _words[51] = new Word("protectionism", "protectionnisme");
            _words[52] = new Word("(to) provide", "fournir");
            _words[53] = new Word("(to) raise an issue", "relever un probleme");
            _words[54] = new Word("recognise", "reconnaitre");
            _words[55] = new Word("recognition", "reconnaissance");
            _words[56] = new Word("recovery", "reprise");
            _words[57] = new Word("reputable", "de bonne reputation");
            _words[58] = new Word("responsibility", "responsabilite");
            _words[59] = new Word("slowdown", "ralentissement");
            _words[60] = new Word("(to) support", "soutenir");
            _words[61] = new Word("sweatshop", "atelier clandestin de travailleurs exploites");
            _words[62] = new Word("talks", "negociations");
            _words[63] = new Word("tariff barriers", "barrieres tarifiaires");
            _words[64] = new Word("underserved", "defavorise");
            _words[65] = new Word("unethical", "contraire a la morale");
            _words[66] = new Word("values", "les valeurs");
            _words[67] = new Word("well-being", "bien etre");
            _words[68] = new Word("whistle-blower", "denonceur");
            _words[69] = new Word("win-win", "gagnant-gagnant");
            _words[70] = new Word("withhold information", "faire de la retention d'information");
            _words[71] = new Word("workplace", "lieu de travail");
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
