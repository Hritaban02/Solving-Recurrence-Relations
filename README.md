# Solving-Recurrence-Relations

Write a program to find the solution of recurrence relations of the form
an = ran−1 +san−2 +t,
where r,s,t and the first two terms a0,a1 of the sequence are supplied by the user as integer constants. We
assume that s 6= 0. The characteristic equation of this recurrence is x
2 − rx − s = 0. You need to compute
the roots of this equation, and handle all the cases like integer roots with possible repetitions, and noninteger (real or complex) roots occurring in conjugate pairs. Moreover, for the non-homogeneous part, you
should consider all the possibilities of 1 being a root of the characteristic equation with multiplicity 0, 1, or
2.
