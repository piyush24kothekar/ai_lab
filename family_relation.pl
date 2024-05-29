female(shruti).
female(shreya).

male(piyush).
male(prajwal).
male(karim).

parent(karim,piyush).
parent(karim,prajwal).
parent(abhilasha,shreya).

son(X,Y):-male(X),parent(Y,X).
daughter(X,Y):-female(X),parent(Y,X).
siblings(X,Y):-parent(Z,X),parent(Z,Y),X\=Y.
