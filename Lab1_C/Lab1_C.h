#pragma once
#include <vector>
#include <random>
#include <algorithm>

class Card {
private:
    int suit;      // масть 
    int rank;      // значення карти 

public:
    Card(int s, int r);
    
    int getSuit() const; 
    int getRank() const; 
    auto operator<=>(const Card& other) const = default;
};


class Deck {
private:
    std::vector<Card> cards;  // масив карт
    int index;                // поточна позиція в колоді
    int cardsPerSuit;         // кількість карт кожної масті
    std::mt19937 rng;         // генератор випадкових чисел

    void shuffle(); // Перетасувати карти

public:
    Deck(int cardsPerSuit);
    Card operator()();// Ввзяти наступну карту
    void reset();  // Скинути й перетасувати нову колоду
};


