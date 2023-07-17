// kelompok 16
// M. Reza Rahadi
// M. Wafiyulloh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void login()
{
	int a=0,i=0;
	int j = 10;
    char uname[10],c=' '; 
    char pword[10], code[10];
    char user[10]="reza";
    char pass[10]="wafi";
do
{
	
    printf("\n  =======================  Harap Login Terlebih Dahulu  =======================\n  ");
    printf(" \n                       MASUKAN USERNAME:-");
	scanf("%s", &uname); 
	
	printf(" \n                       MASUKAN PASSWORD:-");
	
	while(i<10)//Membuat password terlihat menjadi bintang
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	printf("\n  ==============================================================================\n ");
	
	 
//		if(strcmp(uname,"reza")==0 && strcmp(pword,"wafi")==0)
//	{
	printf("\n\n\nSELAMAT DATANG DI PROGRAM TAXI ONLINE!");
	printf("\n\n\n\t\tTekan Tombol apa saja untuk melanjutkan");
	getch();
	break;
//	}
	
//	else
//	{
//		printf("\n\nMAAF KAMU SALAH MEMASUKAN USER/PASSWORD");
//		a++;
//		
//		getch();
//		system("cls");
//	}
}

	while(a<=2);
	if (a>2)
	{
		printf("\nKAMU TERLALU BANYAK MELAKUKAN PERCOBAAN!, Tunggu Beberapa saat lagi!");
		printf("\nTunggu Selama 10 detik untuk melanjutkan kembali\n");
		sleep(1);
		while(j != 0){
			printf("%d", j);
			j--;
			sleep(1);
			system("cls");
		}
		
		printf("\nTekan Tombol apa saja untuk melanjutkan");
		getch();
		system("cls");
		login();
		}

}

// linked list berisi data-data 
struct online
{
  int no;
  int argo;
  int jarak;
  char berangkat[50];
  char nama[20];
  int data;
  struct online *next;
};
struct online *head, *akhir = NULL, *tengah = NULL;

// fungsi untuk mengurutkan secara turun data jarak
int urutjarak_turun() 
{ 

	system("cls");
	printf("\n========================================================================\n");
	printf("\n                              H I S T O R Y");
	printf("\n========================================================================\n");
    struct online* tengah = head, *ind;  
    char temps[50];
	int tempdata;
	
    //setiap node 'tengah' akan dibaca 
    while (tengah != NULL) {
	//membagi 2 list agar saling dibandingkan
	ind = tengah->next;
		//setiap node 'ind' akan dibaca 
		while(ind!= NULL){
			// urutkan jarak terpendek ke terjauh
        	if (tengah->jarak > ind->jarak){
				//data 'berangkat' akan saling ditukarkan
				strcpy(temps, tengah->berangkat);
				strcpy(tengah->berangkat, ind->berangkat);
				strcpy(ind->berangkat, temps);
				//data 'argo' akan saling ditukarkan
				tempdata = tengah->argo;
				tengah->argo = ind->argo;
				ind->argo = tempdata;
				//data 'jarak' akan saling ditukarkan
				tempdata = tengah->jarak;
				tengah->jarak = ind->jarak;
				ind->jarak = tempdata;
			}
		//pergantian node
		ind = ind->next;
		} 
	//pergantian node	
    tengah = tengah->next; 
    } 
    //mencetak hasil 
    jejak();
	    
    getch();
    return main(); 
} 
// fungsi untuk mengurutkan secara naik data jarak 
int urutjarak_naik() 
{ 
    struct online* tengah = head, *ind;  
    char temps[50];
	int tempdata;
	
	system("cls");
	printf("\n========================================================================\n");
	printf("\n                              H I S T O R Y");
	printf("\n========================================================================\n");	
    //setiap node 'tengah' akan dibaca 
    while (tengah != NULL) {
	//membagi 2 list agar saling dibandingkan
	ind = tengah->next;
		//setiap node 'ind' akan dibaca 
		while(ind!= NULL){
			// urutkan jarak terjauh ke terpendek
        	if (tengah->jarak < ind->jarak){
				//data 'berangkat' akan saling ditukarkan
				strcpy(temps, tengah->berangkat);
				strcpy(tengah->berangkat, ind->berangkat);
				strcpy(ind->berangkat, temps);
				//data 'argo' akan saling ditukarkan
				tempdata = tengah->argo;
				tengah->argo = ind->argo;
				ind->argo = tempdata;
				//data 'jarak' akan saling ditukarkan
				tempdata = tengah->jarak;
				tengah->jarak = ind->jarak;
				ind->jarak = tempdata;
			}
		//pergantian node
		ind = ind->next;
		} 
	//pergantian node	
    tengah = tengah->next; 
    } 
    //mencetak hasil 
    jejak();
	    
    getch();
    return main(); 
} 

// fungsi yang digunakan untuk menampilkan history
int jejak()
{
	system("cls");
	printf("\n========================================================================\n");
	printf("\n                              H I S T O R Y");
	printf("\n========================================================================\n");	
  struct online *tengah = head;
  //mengecek apabila list kosong
  if (head == NULL){
  printf("\nTidak terdapat jejak pemesanan sebelumnya");
  }
  //mencetak hasil pemesanan sebelumnya sampai 'taksi' menjadi NULL
  while (tengah != NULL)
  {
  	printf("\n");
    printf(" Harga argo: %d \n Titik keberangkatan: %s \n Jarak yang ditempuh: %d km\n", tengah->argo, tengah->berangkat, tengah->jarak);
    puts("");
    puts("");
    //melanjutkan ke node berikutnya.
    tengah = tengah->next; 
  }
  printf("\nTekan apa saja untuk kembali");

  getch();
  return main();
}

//fungsi yang menghimpun data
int data() {
	struct online *taksi = (struct online*) malloc(sizeof(struct online));
	char *nama = (char*) malloc(20 * sizeof(char));
	int harga;
	int tarif = 4100;
	
	system("cls");
	printf("\n========================================================================\n");
	printf("\n                              R E S E R V A S I");
	printf("\n========================================================================\n");
	//untuk memasukkan nama
	printf("\nSilahkan masukkan Nama anda: ");
	scanf("%s", taksi->nama);
	//untuk memasukkan titik penjemputan
	printf("\nSilahkan masukkan titik keberangkatan: ");
	scanf("%s", taksi->berangkat);
	//untuk mengetahui jarak yang ditempuh
	printf("\nSilahkan masukkan jarak yang ditempuh (km) : ");
	scanf("%d", &(taksi->jarak));
	//node ditambahkan di depan
	taksi->next = head; 
	head = taksi; 
	
    //untuk menghitung tarif harga
	harga = taksi->jarak;
	tarif = tarif*harga;
	taksi->argo = tarif;
    printf("\nPembayaran transportasi adalah: %d", tarif);
    
    printf("\n\nPemesanan telah selesai silahkan ditunggu.");
    printf("\nTekan apa saja untuk kembali");
    
	getch();
	return main();
}
//fungsi keluar
int keluar(int x){
	printf("\nTerima kasih :)");
	if(x==5){
		exit(0);
	}
}
int T=0;
void form(){
	
	  	system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|            TAXOL ( TAXI ONLINE )              |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                Dibuat Oleh                    |\n");
	printf("\t\t|           |  Wafi Reza Corporat |             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	
	printf("Tekan apa saja untuk melanjutkan !");
	getch();
	system("cls");
	T=1;
	login();
	

}

int main()
{	
  if (T != 1){form();}
  struct online* head = NULL;
  int input;
  

	system("cls");
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");      
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");                       
	printf(" -------------------------------------------------------------------------\n");
	printf("\nSELAMAT DATANG DI APLIKASI TAXI ONLINE KAMI BERIKUT TERDAPAT MENU YANG DAPAT KALIAN PILIH");
	
	printf("\n========================================================================\n");
	printf("\n<---TAKSI ONLINE--->\n");
	printf("\n1. Reservasi");
	printf("\n2. Pemesanan sebelumnya");
	printf("\n3. Mencari pemesanan sebelumnya (terjauh)");
	printf("\n4. Mencari pemesanan sebelumnya (terpendek)");
	printf("\n5. Keluar");
	puts("");
	printf("\n========================================================================\n");
	
	scanf("%d", &input);

	switch(input) {
		case 1:
            data();
            break;
		case 2:
            jejak();
            break;
        case 3:
			urutjarak_naik(); 
        	break;
        case 4:
			urutjarak_turun(); 
			break;
        case 5:
            keluar(input);
            break;
	}
}
