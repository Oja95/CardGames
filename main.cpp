#include "mainwindow.h"
#include "Card.h"
#include "Deck.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    Card card(DIAMOND, NINE);
    std::cout << card.toString() << std::endl;
    Deck deck;
    std::cout << deck.deckSize() << std::endl;
    for (std::list<Card>::iterator it = deck.cards.begin(); it != deck.cards.end(); ++it) {
        std::cout << it->toString() << std::endl;
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
