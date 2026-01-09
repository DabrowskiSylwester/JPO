clc; clear; close all;

Pin=[-5 0 5];
Poutm=[5.9 8.6 9.4];
Pout3=[-25.3 -6.4 0.5];

a=0.6; b =8.6;
x=-5:0.1:13;
y=a.*x+b;

coeff = polyfit(Pin, Pout3, 1);
a3 = coeff(1);   % slope
b3 = coeff(2);   % intercept
y3=a3.*x+b3;

figure(1)

plot(Pin, Poutm, 'b.','Marker','x','MarkerSize',12, ...
    'DisplayName','Punkty pomiarowe')
grid on, hold on
plot(x,y,'b.', 'DisplayName','Prosta pierwszego rzędu','MarkerSize',4)

plot(Pin, Pout3, 'r.', 'Marker','x','MarkerSize',12, ...
    'DisplayName','Punkty pomiarowe')
plot(x,y3,'r.','DisplayName','Prosta trzeciego rzędu','MarkerSize',4)

title('Charakterystyki do wyznaczenia IP3')
xlabel('Moc wejściowa [dBm]') 
ylabel('Moc wyjściowa [dBm]')
legend('Location','southeast')

matlab2tikz('wykIP3.tex','standalone',true);