sum([], 0).
sum([Head |Tail], TotalSum) :-sum(Tail, Sum1),TotalSum is Sum1+abs(Head).
