clc; clear; close all;

pomiary = readtable("pomiary.xlsx");

%1GHz
Pin1 = pomiary.Pin1;
Pout1 = pomiary.Pout1;
Gain1 = abs( Pout1 - Pin1);

figure(1)
plot(Pin1, Pout1, 'b.', 'DisplayName','Moc wyjściowa')
grid on, hold on
title('Charakterystyki dla sygnału 1 GHz')
xlabel('Moc wejściowa [dBm]') 
ylabel('Moc wyjściowa [dBm], wzmocnienie [dB]')
axis([-30 5 -20 20])
plot(Pin1, Gain1, 'r.', 'DisplayName','Wzmocnienie')
plot([-1, -1], [-15, 20], 'g--','DisplayName','Linia rozdzielająca zakresy pracy')
legend('Location','southeast')
matlab2tikz('przejsciowa1.tex','standalone',true);

%1GHz
Pin2 = pomiary.Pin2;
Pout2 = pomiary.Pout2;
Gain2 = abs( Pout2 - Pin2);

figure(2)
plot(Pin2, Pout2, 'b.', 'DisplayName','Moc wyjściowa')
grid on, hold on
title('Charakterystyki dla sygnału 2 GHz')
xlabel('Moc wejściowa [dBm]') 
ylabel('Moc wyjściowa [dBm], wzmocnienie [dB]')
axis([-30 5 -20 20])
plot(Pin2, Gain2, 'r.', 'DisplayName','Wzmocnienie')
plot([-1, -1], [-15, 20], 'g--','DisplayName','Linia rozdzielająca zakresy pracy')
legend('Location','southeast')
matlab2tikz('przejsciowa2.tex','standalone',true);


