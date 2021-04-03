syms tau tau_x K zeta w
t_set = 2.25;
m_p = 151;
ss_sol = 90;

% Crude Approximation
eqn_zeta = (m_p-ss_sol)/ss_sol == 1-(zeta/0.6);
%eqn_zeta = (m_p-ss_sol)/ss_sol == exp((-1*pi*zeta)/sqrt(1-zeta^2));
res_zeta = solve(eqn_zeta, zeta);
fprintf("%f\n",res_zeta(1));
zeta1 = res_zeta(1);

eqn_w = t_set == 4/(w*zeta1);
res_w = solve(eqn_w, w);
fprintf("%f\n",res_w(1));
w1 = res_w(1);

eqn1 = (0.798*K)/(1+0.01*K) == (w1^2)/(2*zeta1*w1 + w1^2*tau_x);
eqn2 = (0.798*K)/(0.08+tau) == (w1^2)/(1+2*zeta1*w1*tau_x);
eqn3 = (0.798*K)/(0.08*tau) == (w1^2)/(tau_x);
[res_k, res_tau, res_tau_x] = solve(eqn1,eqn2,eqn3, K, tau, tau_x);
fprintf("%f\n",res_k)
fprintf("%f\n",res_tau)
fprintf("%f\n",res_tau_x)

