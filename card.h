#ifndef CARD_H
#define CARD_H


class Card
{
public:
    Card();
    ~Card();
    long getCardID();
    void setCardID(Card card);

private:
    long cardID;
};

#endif // CARD_H
