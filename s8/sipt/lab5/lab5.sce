function [H, f]= freqz(b, a, Fs)
  N=length(b);
  M=length(a);
  l=max(N,M);
  N_M=N-M;
  if N_M<0 then b=[b,zeros(1,abs(N_M))];
  else
  a=[a,zeros(1,N_M)];
  end
  for f=0:1:Fs/2-1
  w_norm=2*%pi*(f/Fs);
  k=0:1:l-1;
  s1=sum(a.*exp(-k.*%i*w_norm));
  s2=sum(b.*exp(-k.*%i*w_norm));
  H(1,f+1)=s2./s1;
  end
  f=0:1:Fs/2-1;
endfunction

clc;

b = [0.598 0.181 0.018	0	0.298	-0.161];
a = [1 0.670	0.378	-0.185	-0.112	0.050];

A = 1;
f = 10;
fd = 256;
Fs = 256;
T = 1;
T1 = 100 * 0.001; 
dt = 1 / fd;


t = 0:dt:T-dt;
x = A * sin(2 * %pi * f * t);


y0 = filter(b, a, x);

figure(1, 'figure_name', ['завдання 2.1: Реакція системи на вхідний сигнал за нульових початкових умов'], 'BackgroundColor', [1,1,1]);
plot2d(t, x, 3), plot2d(t, y0, 5);
legend('вхідний сигнал', 'реакція системи за нульових початкових умов', ...
       'position', [T/4 - dt, max(max(x, y0)) + 0.5]);


[m_x, n] = max(x);
[m_y, n1] = max(y0);
K = m_y / m_x;
disp("Коефіцієнт підсилення на частоті 10 Гц=", K);
R = t(n1) - t(n);
disp("Різниця фаз становить", R);


l1 = max(length(a), length(b)) - 1;
z0 = rand(l1, 1);
y1 = filter(b, a, x, z0);

figure(2, 'figure_name', ['завдання 2.2: Реакція системи на вхідний сигнал за ненульових початкових умов'], 'BackgroundColor', [1,1,1]);
plot2d(t, x, 3), plot2d(t, y0, 5), plot(t, y1, 'm');
legend('вхідний сигнал', 'реакція системи за нульових початкових умов', ...
       'реакція системи за випадкових почат.умов', ...
       'position', [T/4 - dt, max(max(x, y0, y1)) + 0.7]);


t1 = 0:dt:T1;
x1 = x(1:length(t1));
y11 = y1(1:length(t1));
y01 = y0(1:length(t1));

figure(3, 'figure_name', ['завдання 2.3: Перші 100мс реакції за різних початкових умов'], 'BackgroundColor', [1,1,1]);
plot(t1, x1, 'g+-'), plot(t1, y01, 'r+-'), plot(t1, y11, 'm+-');


u0 = [1, zeros(1, 127)];
h = filter(b, a, u0);

figure(4, 'figure_name', ['завдання 4: Імпульсна характеристика ЛДС'], 'BackgroundColor', [1,1,1]);
subplot(2, 1, 1), plot(0:127, u0, 'green'), title('Одиничний імпульс');
subplot(2, 1, 2), plot(0:127, h, 'red'), title('Імпульсна характеристика');


u0 = [1, zeros(1, 255)];
h = filter(b, a, u0);
ys1_1 = conv(x, h);
t1 = 0:dt:dt * (length(ys1_1) - 1);

figure(5, 'figure_name', ['завдання 5: Відгук системи знайдений через згортку'], 'BackgroundColor', [1,1,1]);
plot2d(t, x, 3), plot2d(t1, ys1_1, 5);
legend('вхідний сигнал', 'реакція системи за нульових початкових умов', ...
       'position', [T/2 - dt, max(max(x), max(ys1_1)) + 0.6]);


[H, f] = freqz(b, a, Fs);
[db, phi] = dbphi(H);
ASH = abs(H);
FSH = atan(imag(H) ./ real(H));

figure(6, 'figure_name', ['завдання 6: КЧХ системи'], 'BackgroundColor', [1,1,1]);
subplot(2, 2, 1), plot(f, db), title('Характеристика спаду, db');
subplot(2, 2, 3), plot(f, ASH), title('АЧХ');
subplot(2, 2, 2), plot(f, phi), title('ФЧХ');
subplot(2, 2, 4), plot(f, FSH), title('ФЧХ1');


u0 = [1, zeros(1, 255)];
h = filter(b, a, u0);
H1 = fft(h);
[db1, phi1] = dbphi(H1);
ASH1 = abs(H1);
FSH1 = atan(imag(H1), real(H1));

figure(7, 'figure_name', ['завдання 7: КЧХ системи'], 'BackgroundColor', [1,1,1]);
subplot(2, 2, 1), plot(db1), title('Повна характеристика спаду, db');
subplot(2, 2, 3), plot(ASH1), title('Повна АЧХ');
subplot(2, 2, 2), plot(phi1), title('Повна ФЧХ');
subplot(2, 2, 4), plot(FSH1), title('Повна ФЧХ1');

figure(8, 'figure_name', ['завдання 7: Аналіз АЧХ системи'], 'BackgroundColor', [1,1,1]);
plot(f, ASH), title('АЧХ');
plot(f, ones(1, length(f)), 'r--');
plot(10 * ones(1, length(f)), min(ASH):((max(ASH) - min(ASH)) / 127):max(ASH), 'g--');


s6 = squarewave(2 * %pi * 3 * t, 30);
ys6 = filter(b, a, s6);

s7 = squarewave(2 * %pi * 10 * t, 50);
ys7 = filter(b, a, s7);

figure(9, 'figure_name', ['завдання 8: Реакція ЛДС на послідовність прямокутних імпульсів різної наповненості'], 'BackgroundColor', [1,1,1]);
subplot(2, 1, 1), plot(t, s6, 'g', t, ys6, 'r');
subplot(2, 1, 2), plot(t, s7, 'g', t, ys7, 'r');

disp('Кінець програми');

