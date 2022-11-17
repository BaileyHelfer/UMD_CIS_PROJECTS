min([A],X):-X is A*A.
min([Head|Tail],M):-min(Tail,M), F is Head*Head, M<F.
min([Head|Tail],F):-min(Tail,M), F is Head*Head, M>=F.