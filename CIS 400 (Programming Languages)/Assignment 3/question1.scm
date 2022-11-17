(define(power A B)
(cond
((= B 0) 1)
((> B 0) (* A (power A (- B 1))))))