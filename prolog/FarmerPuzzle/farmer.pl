/* 
 * Farmer.pl
 * 
 * Author: Danny Hadley
 * Date: January 2013
*/

go(Start,Goal) :-
    empty_stack(Empty_History),
    stack(Start,Empty_History,History),
    path(Start,Goal,History).

/*
 * Path
 *
 * Definitions for the search algorithm
 * and the end state condition
 *
*/

/* end state */
path(Goal,Goal,History) :- write('Solution:'), nl, reverse_print_stack(History).

/* searching */
path(State,Goal,History) :-
    move(State,Attempt),
    not(member_stack(Attempt,History)),
	stack(Attempt,History,New_History),
	path(Attempt,Goal,New_History),!. /* recursion */


/*
 * Move 
 *
 * Definitions for movement functions
 * for each of the objects and possible
 * states
*/

/* farmer-take-wolf */
move(state(X,X,G,C), state(Y,Y,G,C)) :- opposite(X,Y), not(unsafe(state(Y,Y,G,C))).

/* farmer-take-goat */
move(state(X,W,X,C), state(Y,W,Y,C)) :- opposite(X,Y), not(unsafe(state(Y,W,Y,C))).

/* farmer-take-cabbage */
move(state(X,W,G,X), state(Y,W,G,Y)) :- opposite(X,Y), not(unsafe(state(Y,W,G,Y))).

/* farmer-take-self */
move(state(X,W,G,C), state(Y,W,G,C)) :- opposite(X,Y), not(unsafe(state(Y,W,G,C))).

/* farmer-take-self */
move(state(F,W,G,C), state(F,W,G,C)) :- false.


/*
 * unsafe
 *
 * Validity definitions of a state
 * passed in as a parameter 
*/
unsafe(state(X,Y,Y,C)) :- opposite(X,Y). /* unsafe for wolf and goat to be different than farmer */
unsafe(state(X,W,Y,Y)) :- opposite(X,Y). /* unsafe for goat and cabbbage to be different than farmer */

/* 
 * oppsite 
 * 
 * function to check or retrieve
 * the opposite side of a given 
 * position state
*/
opposite(X,Y) :- X = e, Y = w ; X = w, Y = e.

