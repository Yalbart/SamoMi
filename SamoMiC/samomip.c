/*Tanasije Milanovic RT-25/21*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
void header();
void hrana();
void stampa(char imedatoteke[100]);


/*struktura tebe, ovo si ti u celoj ovoj prici*/
struct ti{
	char ime[30+1];
	int god;
};
void upoznavanje();

/*glavna funkcija u kojoj se pozivaju ostale funkcije u zavisnosti od izabrane opcije*/
main(){
	char unos[150];
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED); /*ova funkcija maksimizuje prozor na pokretanju*/
	
	/*poziv menu funkcije*/	
		stampa("menu.txt");	
		gets(unos);
		fflush(stdin);
		/*petlja provere unosa reci za prekid rada programa i ujedno i pokretac ostatka programa*/
		if((strcmp(unos,"izlaz"))==0)
			{	system("cls");
				puts("\n\n\n\t\t\t\tDovidjenja!\n");
				exit(1);
			}
			/*ovde zapravo pocinje izvrsavanje programa, kada unesemo bilo sta sem izlaz pokrenuce se dve funkcije koje stampaju ekran i treca tj hrana koja ocekuje unos gore ponudjene opcije */
		else{	system("cls");
				header();
				stampa("taxt.txt");
				hrana();
				system("pause");
				upoznavanje();
				
				
				
			}
	}
		


/*header je funkcija koja ce uvek posle svakog ciscenja ekrana da pise na vrhu i sluzi kao uputstvo*/
void header(){
	puts("\n														UPUTSVA:");
	puts("\n										Da nahranite coveka napisite broj jednog od predmeta koje imate u dzepu!");
	puts("\n														 Dzep:");
	puts("\n									  1. krem bananica, 2. kifla, 3. jabuka, 4. IKEA olovka, 5. maramica, 6. izlaz");
	puts("\n");
}



/*Ovo je funkcija hrana koja se poziva u mainu posle stampanja headera i prvog stanja coveka, ona proverava unos i prosledjuje ga funkciji stampa koja bas i to radi, stampa odgovarajuci fajl*/
void hrana(){
	
	int opcija;
	puts("Unesite broj predmeta (i bas broj, bez tacke) koji imate u dzepu da date coveku: \n");
	scanf("%d",&opcija);
	switch (opcija){
		/*Ovde u zavisnosti od unete opcije u string datoteka se upisuje tekst koji se prosledjuje funkciji stampa i sluzi za otvaranje odredjene datoteke*/
	case 1:	
				system("cls");
				header();
				stampa("1.txt");
				break;

	case 2:		system("cls");
				header();
				stampa("2.txt");
				break;

	case 3:	 system("cls");
				header();
				stampa("3.txt");
				break;

	case 4:		system("cls");
				header();
				stampa("4.txt");
				break;

	case 5:		system("cls");
				header();
				stampa("5.txt");
				break;

	case 6:		system("cls");
				puts("\n\n\n\t\tDok vas jadan covek gleda u oci, vi kompletno ignorisete njegovo prisustvo i nonsalantno se okrecete i odlazite u nepoznatom pravcu.\n");
				puts("\n\n\n\t\tNormalan Zavrsetak: Odlazak\n\n\n");
				puts("\n\n\n\t\t\t\tDovidjenja!\n");
				exit(1);

	default: 	system("cls");
				puts("\n\n\n\tPromumlali ste nesto i covek vas nije razumeo pa se okrenuo i otisao. Bravo.\n\n\n\tLos Zavrsetak: Pogresan Unos\n\n\n");
				break;
	}
	
	
}

/*Ovo je funkcija stampa, ona se koristi za stampu svih fajlova , prima podatak iz neke funkcije i stampa odredjeni txt fajl*/
void stampa(char imedatoteke[100]){
	FILE *pok;
	char* crta = (char *)malloc(1500*sizeof(char));

if((pok = fopen(imedatoteke,"r"))==NULL){
		puts("\nUPS, nesto nece da ucita crtez, ne znam sta mu je ali program sam pisao ja a ja sam nivo ispod amatera...\n");
		exit(1);
	}
	/*provera dodele, nmp mozda nes nije uspelo PRAVILA LEPOG PROGRAMIRANJA NALAZU*/
	if(crta == NULL){
	puts("\nGRESKA! Nesto se zeznulo, nije se dodelila memorija ili nesto\n");
	exit(1);
	}
	/*crtanje txt linija*/
	while(fgets(crta, 1500, pok)){
		printf("%s",crta);
	}
	puts("\n");
	free(crta);
	fclose(pok);
	

}	
/*Funkcija upoznavanje, ona se izvrsava do kraja samo ako je unet broj godina u opsegu 18-60.*/
void upoznavanje(){
	struct ti osoba;
	system("cls");
	stampa("godine.txt");
	puts("\nOdgovorite coveku na pitanje:\n\n");
	scanf("%d",&osoba.god);
	if(osoba.god<18){
		system("cls");
		stampa("klinac.txt");
	}
	else if(osoba.god>60){
		system("cls");
		stampa("matori.txt");
	}
	else{	system("cls");
			stampa("ime.txt");
			puts("\nPredstavite se coveku:\n\n");
			scanf("%s",&osoba.ime);
			if((strcmp(osoba.ime,"Taxt")==0)){
				system("cls");
				stampa("tajna.txt");
				printf("\a");
				puts("\n\t\tPritisnite bilo koje dugme.\n\n");
				system("pause");
				system("cls");
				stampa("istina.txt");
				puts("\n\t\tPritisnite bilo koje dugme.\n\n");
				system("pause");
				system("cls");
				puts("\n\n\t\t\tU cudnom spletu okolnosti, ispostavilo se da vas misteriozni covek poznaje.\n\t\t\t\n\n\t\t\tDa li je bio u pravu? Zar smo mi slicni , samo pacovi? \n\n\n\n\t\t\tTajni Zavrsetak: Istina.\n\n\n\n");
			}
			else{
				system("cls");
				stampa("nmp.txt");
				system("pause");
				system("cls");
				puts("\n\t\tCovek se okrenuo i otisao.\n\t\t \n\nDobar Zavrsetak: Covek Nahranjen.\n\n\n");
			
			}
	}
}



