%% Deliverable 1
%% forefront stuff
clc; clear all; close all;

% constants
global E
E = 2;
F = 0.2239;
w = 2*pi/10;
u = E/w;

% Calling the ODE Solver
[t,v] = ode45(@VanDerPolEq,[0 2000],[2; 0]);

% Extracting y and x values
x = v(:,1);
y = v(:,2);

% calculating derivative values
dxdt = y - u*(x.^3/3 - x);

% Plotting
figure(1)
hold on
plot(x,dxdt);
xlabel('x');
ylabel('dxdt')
title('Particular solution dx/dt vs x for E = 2, w = 2pi/10');
hold off
      




function dxdt = VanDerPolEq(t,x)
    F = 0.2239;
    w = 2*pi/10;
    global E
    b = E*F;
    u = E/w;    
    dxdt = [x(2) - u*(x(1).^3/3 - x(1)); -1 * x(1)+ b * cos(w*t)];
end