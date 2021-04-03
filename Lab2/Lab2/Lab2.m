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
%% Part 2
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

% plot the d-values
figure();
plot(int,d_vals)
title('d Values');
xlabel('z');
ylabel('min(max(real(roots)))');
% min=== z=-23.5 d=-57.49

[minimum_d,min_index] = min(d_vals);
z1 = int(min_index);
contr_poles = [1 0];
contr_zeros = [-1/z1 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title('Root Locus for z1');

%%
margin(contr*plnt);
%%
% plt the root locus for z2 and z3
z2 = z1 / 2;
z3 = z1 / 3;
contr_poles = [1 0];
contr_zeros = [-1/z2 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title('Root Locus for z2')
contr_poles = [1 0];
contr_zeros = [-1/z3 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title('Root Locus for z3');
% gain for z1=2.62, z2=1.07, z3=0.677
kz1 = 15.2;
kz2 = 4.22;
kz3 = 1.73;
%%
figure();
plot(sim_Z1);
hold on;
plot(sim_Z2);
plot(sim_Z3);
title('Step Responses for z1, z2, z3');
legend('Step Response for z1', 'Step Response for z2', 'Step Response for z3');

%% 
figure();
plot(filtered_z1);
hold on;
plot(filtered_z2);
plot(filtered_z3);
title('Low Pass Filtered z1, z2, z3');
legend('Filtered for z1', 'Filtered for z2', 'Filtered for z3');

%%
figure();
plot(positionz1);
hold on;
plot(positionz2);
plot(positionz3);
title('Output of z1, z2, z3');
legend('z1', 'z2', 'z3');