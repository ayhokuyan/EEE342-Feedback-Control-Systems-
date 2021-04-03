syms tau tau_x K zeta w
t_set = 0.69;
m_p = 100;
ss_sol = 90;
k_LPF = 0.1;
tau_LPF = 0.05;
G_c = 2;
G_rpm = 6;

%% Zeta Calc
% Crude Approximation
%eqn_zeta = (m_p-ss_sol)/ss_sol == 1-(zeta/0.6);
eqn_zeta = (m_p-ss_sol)/ss_sol == exp((-1*pi*zeta)/sqrt(1-zeta^2));
res_zeta = solve(eqn_zeta, zeta);
fprintf("zeta = %f\n",res_zeta(1));
zeta1 = res_zeta(1);

%% w Calc
eqn_w = t_set == 4/(w*zeta1);
res_w = solve(eqn_w, w);
fprintf("omega = %f\n",res_w(1));
w1 = res_w(1);

%% tau, tau_x, K Calc
eqn1 = (k_LPF*G_c*G_rpm*K)/(1+k_LPF*K) == (w1^2)/(2*zeta1*w1 + w1^2*tau_x);
eqn2 = (k_LPF*G_c*G_rpm*K)/(tau_LPF+tau) == (w1^2)/(1+2*zeta1*w1*tau_x);
eqn3 = (k_LPF*G_c*G_rpm*K)/(tau_LPF*tau) == (w1^2)/(tau_x);
[res_k, res_tau, res_tau_x] = solve(eqn1,eqn2,eqn3, K, tau, tau_x);
fprintf("K = %f\n",res_k)
fprintf("tau = %f\n",res_tau)
fprintf("tau_x = %f\n",res_tau_x)

