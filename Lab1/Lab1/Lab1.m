% % %% Plot Pos
% figure; plot(position,'b','LineWidth',2);
% hold on; plot(pos_sim,'r','LineWidth',2);
% xlabel('Time (sec)'); ylabel('Position (degrees)');
% title('Position vs Time');
% legend('Hardware result','Simulation result');

%% Bode Plot
% % Initial Parameters
Cp = [9, 2, 2]; % change this Cp(1) --> first Cp etc.
% LPF = K_LPF/(t_LPF*s+1)
K_LPF = [0.01, 0.1, 0.1]; % change this
t_LPF = [0.08, 0.6, 0.05]; % change this
% P = Km/(tm*s+1)
Km = [23.766047, 47.422093, 8.998988]; % change this
tm = [0.054364, 0.031993, 0.132173]; % change this
% % Plot Bode Diagram of all 3 CLs
figure;
for k=1:3
[w,Tp] = freq_data(Cp(k),K_LPF(k),t_LPF(k),Km(k),tm(k));
subplot(2,1,1);
semilogx(w,20*log10(abs(Tp))); grid on; hold on;
subplot(2,1,2);
semilogx(w,unwrap(angle(Tp))*180/pi); grid on; hold on;
end
subplot(2,1,1); ylabel('Mag (dB)');
title('Bode Plots of estimated closed loop TFs');
subplot(2,1,1); ylabel('Phase (deg)');
xlabel('Frequency (rad/s)');

%% Function
function [w,Tp] = freq_data(Cp,K_LPF,t_LPF,Km,tm)
no_of_samples = 500;
w = logspace(-2,2,no_of_samples);
s = 1j*w;
Pv = Km./(tm*s+1);
Cv = K_LPF./(t_LPF*s+1);
Tv = (Pv.*Cv)./(1+Pv.*Cv);
Tp = Cp*Tv./(1+Cp*Tv);
end