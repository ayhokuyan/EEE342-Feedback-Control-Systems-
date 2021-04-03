close all
h_pr = 9;
h_0 = 5;
A = 361;
a = 2.375;
g = 9.81;
% f = dh/dt = alpha*h(t) + beta*rin(t)
alpha = (a*sqrt(2*g)/(2*A))*(-power(h_pr,-1/2)-power(h_pr-h_0,-1/2));
beta =  1/A;
% H(s)/RIN(s) = beta/(s-alpha)
num = [beta];
denum = [1 -alpha];
G_p = tf(num,denum);
% define Gc coefficients
Kc = 10;
a_c = 10;
b_c = 20;
% Controller 
c_num = [Kc Kc*a_c];
c_denum = [1 b_c 0];
G_c = tf(c_num, c_denum);
% draw the bode plot
figure();
bode(G_p*G_c)
% margins 
figure()
margin(G_p*G_c)
allmargin(G_p*G_c)