% This buffer is for notes you don't want to save.
% If you want to create a file, visit that file with C-x C-f,
% then enter the text in that file's own buffer.

mdc(X, Y, X):- Y == 0, !.
mdc(X, Y, R):- Y > 0, R1 is mod(X,Y), mdc(Y, R1, R), !.
mdc(X, Y, R):- Y < 0, Y1 is -Y, mdc(X, Y1, R), !.

fib(N,A,_,A):- N == 0, !.
fib(N,_,B,B):- N == 1, !.
fib(N,A,B,R):- N > 0, N1 is N-1,C is B, B1 is A+B, A1 is C, fib(N1,A1,B1,R).


fat(N,1):- N == 0, !.
fat(N,F):- N1 is N-1, fat(N1,R1), F is N*R1.
ex(_,0,1).
ex(N,E,0):- N == 0, E =\= 0, !.
ex(N,E,R):- E > 0, E1 is E-1, ex(N,E1,R1), R is N*R1, !.
ty(_,N,1):- N == 0, !.
ty(X,N,T):- ex(X,N,R), fat(N,F), T1 is R/F, N1 is N-1, ty(X,N1,R3), T is R3+T1.

