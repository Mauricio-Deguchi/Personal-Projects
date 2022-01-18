     
%% deliverable 2
for i = 1:.01:5
    global E
    E = i;
    x_initial = [-1 1];
    time = 0:10:1000;
    [t,x] = ode45(@VanDerPolEq,time,x_initial);
    e_c = zeros(size(time)) + E;
    figure(4)
    hold on
    plot(e_c,x(:,1),'b.');
    hold off
end
xlabel('E in [1,5]');
ylabel('x');
title('Bifurcation Diagram');





function dxdt = VanDerPolEq(t,x)
    F = 0.2239;
    w = 2*pi/10;
    global E
    b = E*F;
    u = E/w;    
    dxdt = [x(2) - u*(x(1).^3/3 - x(1)); -1 * x(1)+ b * cos(w*t)];
end







