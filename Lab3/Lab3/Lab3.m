%% Part 1
% 0.5 43
% 5.93 53
A1 = 44.1942;
B1 = 3.33541;

% 0.34 58
% 5.36 84
A2 = 55.706;
B2 = 3.16511597;

K1 = A1/B1;
tau1 = 1/B1;
K2 = A2/B2;
tau2 = 1/B2;
K = (K1 + K2) / 2;
tau = sqrt(tau1*tau2);

format long
close all
h = 0.005;
plnt_poles = [(tau*h) (tau+h) 1];
plnt_zeros = [(-h*K) (K)];
plnt = tf(plnt_zeros,plnt_poles);
int = -100:0.1:-1;

d_vals = [];
for z = int
    contr_poles = [1 0];
    contr_zeros = [-1/z 1];
    contr = tf(contr_zeros, contr_poles);
    [roots,ks] = rlocus(plnt*contr);
    max_re = max(real(roots));
    min_max_root = min(max_re);
    d_vals = [d_vals min_max_root];
end

[minimum_d,min_index] = min(d_vals);
z1 = int(min_index);
contr_poles = [1 0];
contr_zeros = [-1/z1 1];
contr = tf(contr_zeros, contr_poles);
figure();
bode(contr*plnt);
title('Bode for z1');

GM = 35.8;
PM = 43;
figure();
margin(contr*plnt)
allmargin(contr*plnt)

%      GainMargin: 64.714521292571277
%     GMFrequency: 1.850850582462882e+02
%     PhaseMargin: 42.584807404238298
%     PMFrequency: 6.993497614477682
%     DelayMargin: 0.106276593130307
%     DMFrequency: 6.993497614477682
%          Stable: 1