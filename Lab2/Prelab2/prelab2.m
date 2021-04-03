format long
close all
plnt_poles = [0.0003642065 0.0778413 1];
plnt_zeros = [-0.13361655 26.7233];
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
title("d Values");
xlabel("z");
ylabel("min(max(real(roots)))");
% min=== z=-23.5 d=-57.49
% plot the root locus for z1
[minimum_d,min_index] = min(d_vals);
z1 = int(min_index);
contr_poles = [1 0];
contr_zeros = [-1/z1 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title("Root Locus for z1");

%z2==-11.75 z3=-7.8333333
z2=z1/2
z3=z1/3

% plt the root locus for z2 and z3
contr_poles = [1 0];
contr_zeros = [-1/z2 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title("Root Locus for z2")
contr_poles = [1 0];
contr_zeros = [-1/z3 1];
contr = tf(contr_zeros, contr_poles);
figure();
rlocus(contr*plnt);
title("Root Locus for z3");
%%
% plot the step responses
figure();
plot(s1_step_resp);
hold on
plot(s2_step_resp2);
plot(s3_step_resp3);
title("Step responses for z1,z2 and z3");
legend("Step Response for z1","Step Response for z2","Step Response for z3");




    