%----------StartRealChua.m----------
% simulate for 5 seconds
[t,y] = ode45(@RealChua,[0 5],[-0.5 -0.2 0]);
plot3(y(:,1),y(:,2),y(:,3), '-')
grid
