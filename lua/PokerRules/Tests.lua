-- CardTest --
-- Author: Danny Hadley
-- Date: Winter 2013

print( )
print( )
print( )
print("===== Loading Cards.lua =====")

DEBUG = nil

dofile("Cards.lua")


print( )
print( )
print("===== Shuffling the cards =====")
shuffleCards( )

-- print("===== Redealing cards =====")
-- dealCards(4, true)


print( )
print( )
print("===== Running individual tests =====")
print("---> Should be a straight flush")
rateCards({
    { suit = "Diamonds", value = 13, rank = "Ace" },
    { suit = "Diamonds", value = 12, rank = "King" },
    { suit = "Diamonds", value = 11, rank = "Queen" },
    { suit = "Diamonds", value = 10, rank = "Jack" },
    { suit = "Diamonds", value = 9, rank = "Ten" },
    { suit = "Diamonds", value = 2, rank = "Three" },
    { suit = "Diamonds", value = 1, rank = "Two" }
}, true ) 

print( )
print("---> Should be a straight flush")
rateCards({
    { suit = "Diamonds", value =  13, rank = "Ace" },
    { suit = "Diamonds", value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  9, rank = "Ten" },
    { suit = "Diamonds", value =  4, rank = "Five" },
    { suit = "Diamonds", value =  3, rank = "Four" },
    { suit = "Diamonds", value =  2, rank = "Three" },
    { suit = "Diamonds", value =  1, rank = "Two" }
}, true )

print( )
print("---> Should be a four of a kind")
rateCards({
    { suit = "Diamonds", value =  11, rank = "Queen" },
    { suit = "Hearts",   value =  11, rank = "Queen" },
    { suit = "Clubs",    value =  11, rank = "Queen" },
    { suit = "Spades",   value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  7, rank = "Eight" },
    { suit = "Diamonds", value =  6, rank = "Seven" },
    { suit = "Diamonds", value =  5, rank = "Six" }
}, true )

print( )
print("---> Should be a full house")
rateCards({
    { suit = "Diamonds", value =  11, rank = "Queen" },
    { suit = "Hearts",   value =  11, rank = "Queen" },
    { suit = "Hearts",   value =  12, rank = "King" },
    { suit = "Clubs",    value =  12, rank = "King" },
    { suit = "Spades",   value =  12, rank = "King" },
    { suit = "Clubs",    value =  13, rank = "Ace" },
    { suit = "Spaces",   value =  13, rank = "Ace" },
}, true )


print( )
print("---> Should be a Flush")
rateCards({
    { suit = "Diamonds", value =  13, rank = "Ace" },
    { suit = "Diamonds", value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  9, rank = "Ten" },
    { suit = "Diamonds", value =  7, rank = "Eight" },
    { suit = "Diamonds", value =  4, rank = "Five" },
    { suit = "Clubs",    value =  3, rank = "Four" },
    { suit = "Spaces",   value =  1, rank = "Two" },
}, true )


print( )
print("---> Should be a Straight")
rateCards({
    { suit = "Clubs",    value =  13, rank = "Ace" },
    { suit = "Hearts",   value =  12, rank = "King" },
    { suit = "Spades",   value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  10, rank = "Jack" },
    { suit = "Diamonds", value =  9, rank = "Ten" },
    { suit = "Clubs",    value =  3, rank = "Four" },
    { suit = "Spaces",   value =  1, rank = "Two" },
}, true )


print( )
print("---> Should be three of a kind")
rateCards({
    { suit = "Clubs",    value =  12, rank = "King" },
    { suit = "Hearts",   value =  12, rank = "King" },
    { suit = "Spades",   value =  12, rank = "King" },
    { suit = "Diamonds", value =  10, rank = "Jack" },
    { suit = "Diamonds", value =  9, rank = "Ten" },
    { suit = "Clubs",    value =  3, rank = "Four" },
    { suit = "Spaces",   value =  1, rank = "Two" },
}, true )

print( )
print("---> Should be two pair")
rateCards({
    { suit = "Clubs",    value =  12, rank = "King" },
    { suit = "Hearts",   value =  12, rank = "King" },
    { suit = "Spades",   value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  9, rank = "Ten" },
    { suit = "Clubs",    value =  3, rank = "Four" },
    { suit = "Spades",   value =  3, rank = "Four" },
}, true )


print( )
print("---> Should be a pair")
rateCards({
    { suit = "Clubs",    value =  12, rank = "King" },
    { suit = "Hearts",   value =  12, rank = "King" },
    { suit = "Spades",   value =  11, rank = "Queen" },
    { suit = "Diamonds", value =  10, rank = "Jack" },
    { suit = "Diamonds", value =  9, rank = "Eight" },
    { suit = "Clubs",    value =  3, rank = "Four" },
    { suit = "Spades",   value =  2, rank = "Three" },
}, true )

print( )




