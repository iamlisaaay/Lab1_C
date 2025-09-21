#pragma once
#include <vector>
#include <random>
#include <algorithm>

class Card {
private:
    int suit;      // ����� 
    int rank;      // �������� ����� 

public:
    Card(int s, int r);
    
    int getSuit() const; 
    int getRank() const; 
    auto operator<=>(const Card& other) const = default;
};


class Deck {
private:
    std::vector<Card> cards;  // ����� ����
    int index;                // ������� ������� � �����
    int cardsPerSuit;         // ������� ���� ����� ����
    std::mt19937 rng;         // ��������� ���������� �����

    void shuffle(); // ������������ �����

public:
    Deck(int cardsPerSuit);
    Card operator()();// ������ �������� �����
    void reset();  // ������� � ������������ ���� ������
};


