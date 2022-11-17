(define (remove ls)
    (cond ((null? ls) ls)
    ((null? (cdr ls)) '())
    ((= 0 0) (cons (car ls) (remove (cdr ls))))))