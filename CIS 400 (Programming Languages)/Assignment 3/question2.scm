(define (numpositive ls)
    (cond ((null? ls) 0)
    ((> (car ls) 0) (+ 1 (numpositive (cdr ls))))
    ((= 0 0) (+ 0 (numpositive (cdr ls))))))
