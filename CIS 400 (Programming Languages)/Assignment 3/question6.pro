len([],0).
len([Head|Tail],X):-len(Tail,Y), X is 1+Y.

sumList([], 0).
sumList([Head|Tail], X):- sumList(Tail,Y), X is Head+Y.

out_list(A,B,0):-len(A,L1), len(B,L2), L1<L2.
out_list(A,B,2):-len(A,L1), len(B,L2), L1>L2.
out_list(A,B,1):-sumList(A,S1), sumList(B,S2), S1=<S2.
out_list(A,B,4).