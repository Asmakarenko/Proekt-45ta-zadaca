#include<iostream>
#include<cstring>
using namespace std;
//definicija na funkcija za kodiranje 
void funkcija1(char VnesenTekst[],int DolVnesenText,int brPomesti)
{
	//deklaracija i inicijalizacija na promenlivi
	int min1=65,min2=97,max1=90,max2=122;
	for(int i=0;i<DolVnesenText;i++)
	{
		//odreduvanje na ascii kodovi 
		int ascibroj=(int)VnesenTekst[i];
			//mali ascii
			if(ascibroj>=min2 && ascibroj<=max2)
			{
				if(ascibroj+brPomesti<=max2)
	VnesenTekst[i]=(char)((int)VnesenTekst[i]+brPomesti);
				else
			VnesenTekst[i]=(char)(min2+((int)VnesenTekst[i]+brPomesti)-1-max2);
			}	
		//golemi ascii
			if(ascibroj>=min1 && ascibroj<=max1)
			{
				
				if(ascibroj+brPomesti<=max1)
					VnesenTekst[i]=(char)((int)VnesenTekst[i]+brPomesti);
				else
			VnesenTekst[i]=(char)(min1+((int)VnesenTekst[i]+brPomesti)-1-max1);
			}
	}
	cout<<endl;
	//pecatenje na kodiran string
	for(int i=0;i<DolVnesenText;i++)
		cout<<VnesenTekst[i];
	cout<<endl;
}
//definicja na funkcija za dekodiranje
void funkcija2(char VnesenTekst[],int DolVnesenText,int brPomesti)
{
	//deklaracija i inicijalizacija na promenlivite
	int min1=65,min2=97,max1=90,max2=122;
	for(int i=0;i<DolVnesenText;i++)
	{
		//odderuvanje na ascii kod
		int ascibroj=(int)VnesenTekst[i];
		//golemi bukvi 
	    if((ascibroj>=min1 && ascibroj<=max1)||(ascibroj>=min2 && ascibroj<=max2))
		{
			//mali bukvi 
			if(ascibroj>=min2 && ascibroj<=max2)
			{
				if(ascibroj-brPomesti>=min2)
				VnesenTekst[i]=(char)((int)VnesenTekst[i]-brPomesti);
				else
		VnesenTekst[i]=(char)(max2-(min2-((int)VnesenTekst[i]-brPomesti))+1);
			}	
			//golemi bukvi 
			if(ascibroj>=min1 && ascibroj<=max1)
			{
				if(ascibroj-brPomesti>=min1)
					VnesenTekst[i]=(char)((int)VnesenTekst[i]-brPomesti);
				else
			VnesenTekst[i]=(char)(max1-(min1-((int)VnesenTekst[i]-brPomesti))+1);
			}
		}
	}
	cout<<endl;
	//pecatenje na dekodiran tekst 
	for(int i=0;i<DolVnesenText;i++)
		cout<<	VnesenTekst[i];
	cout<<endl;	
}
int main()
{
	char VnesenTekst[400];
	char brPomesti[20];
	int izb,brbroj;
	int DolVnesenText,cifra,brcifri=0,brPomestiac=0;
	//ciklus za kontorla na vnesen tekst 
	do
	{
		cout<<"\n Vnesete tekst za obrabotka ->>> ";
		cin.getline(VnesenTekst,400);
		DolVnesenText=strlen(VnesenTekst);
		brPomestiac=0;
		for(int i=0;i<DolVnesenText;i++)
		if(!isalpha(VnesenTekst[i]) && !isdigit(VnesenTekst[i]) && VnesenTekst[i]!=' ')
				brPomestiac=brPomestiac+1;
		if(brPomestiac!=0)
			cout<<"\n GRESKA POVTORNO VNESETE  !!!! ";
	}while(brPomestiac!=0);
	int pombrPomesti=0;
	//ciklus za kontorla na vnesne broj 
	do
	{
		cout<<"\n Vnesete broj  ->>> ";
		cin.getline(brPomesti,20);
		brbroj=strlen(brPomesti);
		pombrPomesti=0;
		for(int i=0;i<brbroj;i++)
		if(isdigit(brPomesti[i]))
			pombrPomesti++;
		if(!(pombrPomesti==brbroj && brbroj<=10))
			cout<<"\n GRESKA OBIDETE SE POBTORNO !!!! "<<endl;	
	}while(!(pombrPomesti==brbroj && brbroj<=10));
	//meni za izbor 
	do
	{
		cout<<"\n 1. Kodiranje ";
		cout<<"\n 2. Dekodiranje ";
		cout<<"\n 3. Izlez ";
		cout<<"\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
		cout<<"\n Vnesete izbor : ";
		cin>>izb;
		cout<<"\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
		switch(izb)
		{
			case 1: funkcija1(VnesenTekst,DolVnesenText,brbroj);
					 break;
			case 2: funkcija2(VnesenTekst,DolVnesenText,brbroj);
					 break;
			case 3: break;
			default:cout<<"\n POGRESEN IZBOR "<<endl;
		}
	}while(izb!=3);
	cout<<"\n KODIRANJETO I DEKODIRANJETO SE ZAVRSENI ---- PROGRAMATA ZAVRSI "<<endl;
	return 0;
}

