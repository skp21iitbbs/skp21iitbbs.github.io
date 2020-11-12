clear all;
clc;
%% Any parametric input can be taken
% Our Test Case
W=0;
x=0.12;
y=0.08;
m=2.5;
h1=0.015;
h2=0;
S1=1128;
S2=831;
r0=0.12;




%% Case1: varying c fixing phi
c2=linspace(0,300,10000);
Phi2=70; % Can take any arbitrary value
c=c2;
Phi=Phi2;
r1=r0-(x.*(1-(1./c)).*(y.*cosd(Phi)-h1.*sind(Phi))/y);
r2=r0-(x.*(1-(1./c)).*(y.*cosd(Phi)+h2.*sind(Phi))/y);
Fc1=(m*9.81.*(y.*cosd(Phi)-h1.*sind(Phi))./(h1.*cosd(Phi)+y.*sind(Phi)))+((W+S1)*y*y.*c)./(2*x.*(c-ones(size(c))).*(h1.*cosd(Phi)+y.*sind(Phi)));
Fc2=(m*9.81.*(y.*cosd(Phi)+h2.*sind(Phi))./(-h2.*cosd(Phi)+y.*sind(Phi)))+((W+S2)*y*y.*c)./(2*x.*(c-ones(size(c))).*(-h2.*cosd(Phi)+y.*sind(Phi)));
N1=sqrt(abs(Fc1./(m*r1)))*60/(2*3.14);
N2=sqrt(abs(Fc2./(m*r2)))*60/(2*3.14);
w=N1-N2;

%% Search for critical Values
for i=1:length(w)
    if w(i)==max(w)
        for j=i:length(w)
            if w(j+1)<0 || j+1==length(w)
                tol=min(w(i:j));
                break;
            end
        end
    end
end
%%
c_critical=c(find(w==tol));
q=figure;
subplot(1,2,1);
plot(c,N1,'-b');
xlabel('c');
ylabel('Speed');
title('c_{critical}=',num2str(c_critical));
hold on;
plot(c,N2,'-r');
axis auto
hold off;
clear Phi;
clear c;

%% Case2: varying phi fixing c
Phi1=linspace(1,180,10000);
c1=299.97*ones(size(Phi1)); %Can take any arbirary value
c=c1;
Phi=Phi1;
r1=r0-(x.*(1-(1./c)).*(y.*cosd(Phi)-h1.*sind(Phi))/y);
r2=r0-(x.*(1-(1./c)).*(y.*cosd(Phi)+h2.*sind(Phi))/y);
Fc1=(m*9.81.*(y.*cosd(Phi)-h1.*sind(Phi))./(h1.*cosd(Phi)+y.*sind(Phi)))+((W+S1)*y*y.*c)./(2*x.*(c-ones(size(c))).*(h1.*cosd(Phi)+y.*sind(Phi)));
Fc2=(m*9.81.*(y.*cosd(Phi)+h2.*sind(Phi))./(-h2.*cosd(Phi)+y.*sind(Phi)))+((W+S2)*y*y.*c)./(2*x.*(c-ones(size(c))).*(-h2.*cosd(Phi)+y.*sind(Phi)));
N1=sqrt(abs(Fc1./(m*r1)))*60/(2*3.14);
N2=sqrt(abs(Fc2./(m*r2)))*60/(2*3.14);
w=N1-N2;
tol=min(abs(w));
index=abs(w)<=tol;
indexNumeric = find(index);
Phi_critical=Phi(indexNumeric(1));
subplot(1,2,2);
plot(Phi,N1,'-b');
xlabel('Phi');
ylabel('Speed');
title('Phi_{critical} (in degrees)= ',num2str(Phi_critical));
hold on;
plot(Phi,N2,'-r');
axis auto;
hold off;