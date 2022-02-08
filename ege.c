 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <locale.h>
 #include <windows.h>
 #include <unistd.h>
 #include <conio.h>
 #include <ctype.h>
 #include <MMsystem.h>
 
 struct testoyunu {
	char metin[100];
	int ID;
	char A[100];
	char B[100];
	char C[100];
	char D[100];
	char dogrucevap[100];
};
struct game{
	char ad[10];
	int skor;
};

 int enterChoice( void );
 void yaz( FILE *readPtr );
 void guncelle( FILE *fPtr );
 void soruekle( FILE *fPtr );
 void sorusil( FILE *fPtr );
 void oyunoyna( FILE *fPtr );
 void skorlarigoster();
 void loadingsc();
 void color_text(int color);

 int main( void )
 {
	
      setlocale(LC_ALL, "Turkish"); 
 	  srand(time(NULL));
 	  
 FILE *cfPtr; 
 int choice; 

 if ( ( cfPtr = fopen( "quiz.txt", "rb+" ) ) == NULL ) {
 printf( "Dosya açýlamadý.\n" );
 } 

 else {

  while ( ( choice = enterChoice() ) != 7 ) {

 switch ( choice ) {

 case 1:
 guncelle( cfPtr );
 break;

 case 2:
 soruekle( cfPtr );
 break;

 case 3:
 sorusil( cfPtr );
 break;
 
 case 4:
 oyunoyna( cfPtr );
 break;
 
 case 5:
 skorlarigoster();
 break;
 
 case 6:
 yaz( cfPtr );
 break;
  
 default:
 	system("cls");
 	color_text(1);
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tGEÇERSÝZ SEÇÝM!\n" );
 PlaySound(TEXT("D:\\werror.wav"),NULL,SND_SYNC); 
    color_text(-1);
    system("cls");
 break;

 } 

 }

 fclose( cfPtr ); 
 } 
 system("cls");
 color_text(4);
 printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tProgram Sonlandýrýlýyor");
 printf(".");
 Sleep(200);
 printf(".");
 Sleep(200);
 printf(".");
 Sleep(200);
 return 0;

 } 

 void yaz( FILE *readPtr )
 {
 FILE *writePtr; 

 struct testoyunu test = { "",0,"","","","",""};


 if ( ( writePtr = fopen( "sorular.txt", "wb+" ) ) == NULL ) {
 printf( "Dosya açýlamadý.\n" );
 } 

 else {
 rewind( readPtr ); 

 
 while ( !feof( readPtr ) ) {
 fread( &test, sizeof( struct testoyunu ), 1, readPtr );

 
 if ( test.ID != 0 ) {
 fprintf( writePtr, "%d) %s\n   A)%s  B)%s  C)%s  D)%s   doðru cevap:%s \n\n",
 test.ID, test.metin, test.A,test.B,test.C,test.D, test.dogrucevap);
 } 

 }

 fclose( writePtr ); 
 system("cls");
 printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tBilgiler Sorular.txt dosyasýna aktarýlýyor.");
 sleep(2);
 } 
 
system("cls");
 } 
 void guncelle( FILE *fPtr )
 {
 	 
 struct testoyunu test = { "",0,"","","","",""};
 
 int soruid; 
 
 rewind(fPtr);
 system("cls");
 	while ( !feof( fPtr)){
 		
 			fread( &test, sizeof( struct testoyunu ), 1, fPtr );
 			if(test.ID!=0){
 				 printf("\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t     B)%s\n   \t\t\t\t C)%s\t     D)%s\n\t\t\t\t\t\t Doðru cevap: %s\n", 
				  test.ID, test.metin,test.A,test.B,test.C,test.D,test.dogrucevap);
              
			  Sleep(200);
			 }
	 }


 printf( "\n\t\t\t\tGüncellemek istediðiniz soruyu seçiniz: " );
 scanf( "%d", &soruid );

 
 fseek( fPtr, ( soruid - 1 ) * sizeof( struct testoyunu ),
 SEEK_SET );


 fread( &test, sizeof( struct testoyunu ), 1, fPtr );

 
 if ( test.ID == 0 ) {
 system("cls");
 color_text(1);
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tAradýðýnýz soru bulunamadý.\n", soruid );
 sleep(2);
 system("cls");
 }
 else {

 printf( "\t\t\t\tSoruyu giriniz:\n" );
 printf("\t\t\t\t");
 gets(  test.metin);
 gets(test.metin);
 printf( "\t\t\t\tÞýklarý giriniz:\n" );
 printf("\t\t\t\tA)");
 gets(test.A);
 printf("\t\t\t\tB)");
 gets(test.B);
 printf("\t\t\t\tC)");
 gets(test.C);
 printf("\t\t\t\tD)");
 gets(test.D);
 printf( "\t\t\t\tDoðru cevabý giriniz:\n" );
 printf("\t\t\t\t");
 scanf("%s",&test.dogrucevap);
 
 

	
 
 fseek( fPtr, ( soruid - 1 ) * sizeof( struct testoyunu ),
 SEEK_SET );

 
 fwrite( &test, sizeof( struct testoyunu ), 1, fPtr );
 system("cls");
 color_text(2);
 printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSoru baþarýyla güncellendi!");
 sleep(2);
 system("cls");
 } 
color_text(-1);
 } 

 
 void sorusil( FILE *fPtr )
 {
 	system("cls");
  int i;
 struct testoyunu test; 
 struct testoyunu bostest = { "",0,"","","","",""}; 

 int sorunumarasi; 
 
 	
 rewind(fPtr);
   printf("\n\n");
 	while ( !feof( fPtr)){
 		
 			fread( &test, sizeof( struct testoyunu ), 1, fPtr );
 			if(test.ID!=0){
 				 printf("\t\t\t  %d)  %s\n", test.ID, test.metin);

			 }
	 }
 
 
 

 
 
 printf( "\n\t\t\t Silmek istediðiniz soru numarasýný giriniz: " );
 scanf( "%d", &sorunumarasi );


 
 fseek( fPtr, ( sorunumarasi - 1 ) * sizeof( struct testoyunu ),
 SEEK_SET );

 
 fread( &test, sizeof( struct testoyunu ), 1, fPtr );


 if ( test.ID == 0 ) {
 	system("cls");
 	color_text(1);
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSoru %d mevcut deðil.\n", sorunumarasi );
 PlaySound(TEXT("D:\\error.wav"),NULL,SND_SYNC);  
 Sleep(750);
 } 
 else { 

 
 fseek( fPtr, ( sorunumarasi - 1 ) * sizeof( struct testoyunu ),
 SEEK_SET );

 
 fwrite( &bostest,
 sizeof( struct testoyunu ), 1, fPtr );
 system("cls");
 color_text(2);
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSoru baþarýyla silindi!\n");
 sleep(1);
 } 
 color_text(-1);
  system("cls");
 } 
 
 void soruekle( FILE *fPtr )
 {
 system("cls");
 struct testoyunu test = { "",0,"","","","",""};

 int sorunumarasi; 

 
 printf( "\n\n\t\t\t   Eklemek istediðiniz sorunun numarasýný giriniz: " );
 scanf( "%d", &sorunumarasi );


 fseek( fPtr, ( sorunumarasi - 1 ) * sizeof( struct testoyunu ),
 SEEK_SET );


 fread( &test, sizeof( struct testoyunu ), 1, fPtr );

 
 if ( test.ID != 0 ) {
 	system("cls");
 	color_text(6);
 	
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSoru %d zaten var.\n",
 test.ID );
 PlaySound(TEXT("D:\\error.wav"),NULL,SND_SYNC);  
     color_text(-1);
     sleep(2);
     system("cls");
 } 

 else { 
 
 printf("\t\t\t   Soruyu giriniz:\n" );
 printf("\t\t\t\t");
 
 gets(test.metin);
 gets(test.metin);
 printf("\t\t\t\tÞýklarý giriniz:\n" );
 printf("\t\t\t\tA)");
 gets(test.A);
 printf("\t\t\t\tB)");
 gets(test.B);
 printf("\t\t\t\tC)");
 gets(test.C);
 printf("\t\t\t\tD)");
 gets(test.D);
 printf( "\t\t\t\tDoðru cevabý giriniz:\n" );
 printf("\t\t\t\t");
 gets(test.dogrucevap);
 

 test.ID = sorunumarasi;

 
 fseek( fPtr, ( test.ID - 1 ) *
 sizeof( struct testoyunu ), SEEK_SET );

 
 fwrite( &test,
 sizeof( struct testoyunu ), 1, fPtr );
    system("cls");
 	color_text(2);
 printf( "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSoru %d baþarýyla eklendi.\n",test.ID );
     color_text(-1);
     sleep(2);
     system("cls");
 } 

 } 

void oyunoyna( FILE *fPtr)
{
  system("cls");
	struct testoyunu test;
	int i=0, p=0, z=0,t=0,r=0;
	int n=0;
	int count = 0;
    char c;
    char renk[]="A",renk1[]="B",renk2[]="C",renk3[]="D";
	int soruid[10];
	char cevaplar[5];
	char cevap[2];
	int puan,position=0;
    int x = 0, y = 0, input[5], current, temp;

    srand(time(NULL));
    
    while(test.ID==0){
    fseek(fPtr, (t)* sizeof(struct testoyunu), SEEK_END);
    fread(&test, sizeof( struct testoyunu ), 1, fPtr);
    t--;
	}
	r=test.ID;	

    for (x = 0; x < 5 ;x++){
        input[x] = rand() % r + 1;

        for (y = 0; y < 5; y++){
            if (input[x] == input[y]){
                if (y != x){
                    input[x] = rand() % r + 1;
                    y = 0;
                }
            }
        }
    }
    
    /*for (x = 0; x < 5 ; x++){
        printf("Input[%d]: %d\n", x + 1, input[x]);
    }
    printf("\n"); */
    puan=0; 
    
    
    FILE* score =fopen("skorlar.txt","r");
    if(score==NULL){
    	printf("dosya bulunamadý\n");
	}
	char buffer[200];
	fgets(buffer,200,score);
	
	struct game final[10];
	int j=0;
	while(!feof(score)){
		
	struct game* f =final +j;
	sscanf(buffer,"%s %d", f->ad, &f->skor);
	
	fgets(buffer,200,score);
	j++;			
	}
	n=j;
	
	fclose(score);
	
	printf("\n\n\n\n\n\n\t\t\t\t-------------\x1B[1;%dmYARIÞMAYA HOÞGELDÝNÝZ!!!\x1B[0;39m--------------",36);
	PlaySound(TEXT("D:\\start.wav"),NULL,SND_SYNC); 
	system("cls");
	    
	rewind(fPtr);	
	    puan=0;
	    while(i!=5){
			
		    fseek(fPtr, (input[i])* sizeof(struct testoyunu), SEEK_SET);
			fread(&test, sizeof( struct testoyunu ), 1, fPtr);	
			if(test.ID==0){
				z=i;
                  input[z] = rand() % 10 + 1;

                for (y = 0; y < 5; y++){
                  if (input[z] == input[y]){
                      if (y != z){
                        input[z] = rand() % 10 + 1;
                    y = 0;
                }
            }
        }
    	         
				
			}
			if(test.ID!=0){
				  			
				printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID, test.metin,test.A,test.B,test.C,test.D);	
				printf("\t\t\t\t\t\t");
				scanf("%s",&cevap); 			
		    	system("cls");
		    	
		    	if(strcmp(cevap,renk)==0){
		    		printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t \x1B[1;%dmA)%s\t\t\x1B[0;39mB)%s\n\t\t\t\t C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,43,test.A,test.B,test.C,test.D);   
				}
				if(strcmp(cevap,renk1)==0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\t\x1B[1;%dmB)%s\n\t\t\t\t\x1B[0;39m C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,43,test.B,test.C,test.D);
				}
				if(strcmp(cevap,renk2)==0){
				printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t \x1B[1;%dmC)%s\t\t\x1B[0;39mD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,test.B,43,test.C,test.D);
				}
				if(strcmp(cevap,renk3)==-0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t C)%s\t\t\x1B[1;%dmD)%s\n\t\t\t\t\t\t\n\x1B[0;39m", 
				test.ID,test.metin,test.A,test.B,test.C,43,test.D);
				}
				PlaySound(TEXT("D:\\suspense.wav"),NULL,SND_SYNC);				
				//printf("\x1B[1;%dm", 30 + color);
				//printf("\x1B[0;39m");
				
				color_text(-1);
	        
			if(strcmp(cevap, test.dogrucevap)==0){

				puan++; 
				system("cls");
				if(strcmp(cevap,renk)==0){
		    		printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t \x1B[1;%dmA)%s\t\t\x1B[0;39mB)%s\n\t\t\t\t C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,42,test.A,test.B,test.C,test.D);   
				}
				if(strcmp(cevap,renk1)==0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\t\x1B[1;%dmB)%s\n\t\t\t\t\x1B[0;39m C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,42,test.B,test.C,test.D);
				}
				if(strcmp(cevap,renk2)==0){
				printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t \x1B[1;%dmC)%s\t\t\x1B[0;39mD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,test.B,42,test.C,test.D);
				}
				if(strcmp(cevap,renk3)==-0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t C)%s\t\t\x1B[1;%dmD)%s\n\t\t\t\t\t\t\n\x1B[0;39m", 
				test.ID,test.metin,test.A,test.B,test.C,42,test.D);
				}	
				PlaySound(TEXT("D:\\ding.wav"),NULL,SND_SYNC); 
				Sleep(600);
				system("cls");
					
			}
			else{
				system("cls");
				if(strcmp(cevap,renk)==0){
		    		printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t \x1B[1;%dmA)%s\t\t\x1B[0;39mB)%s\n\t\t\t\t C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,41,test.A,test.B,test.C,test.D); 
				PlaySound(TEXT("D:\\wrong.wav"),NULL,SND_SYNC);  
				}
				if(strcmp(cevap,renk1)==0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\t\x1B[1;%dmB)%s\n\t\t\t\t\x1B[0;39m C)%s\t\tD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,41,test.B,test.C,test.D);
				PlaySound(TEXT("D:\\baaap.wav"),NULL,SND_SYNC);  
				}
				if(strcmp(cevap,renk2)==0){
				printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t \x1B[1;%dmC)%s\t\t\x1B[0;39mD)%s\n\t\t\t\t\t\t\n", 
				test.ID,test.metin,test.A,test.B,41,test.C,test.D);
				PlaySound(TEXT("D:\\wrong.wav"),NULL,SND_SYNC);  
				}
				if(strcmp(cevap,renk3)==-0){
					printf("\n\n\n\n\t\t\t\t %d) %s\n   \t\t\t\t A)%s\t\tB)%s\n\t\t\t\t C)%s\t\t\x1B[1;%dmD)%s\n\t\t\t\t\t\t\n\x1B[0;39m", 
				test.ID,test.metin,test.A,test.B,test.C,41,test.D);
				PlaySound(TEXT("D:\\baaap.wav"),NULL,SND_SYNC);  
				}	
				
				Sleep(600);
				system("cls");
	
				
			}
			i++;
			
		}	
		color_text(-1);		
		
	}
	    loadingsc();
	    
     	printf("\n\n\n\n\n\t\t\t\t\tSkorunuz:");
     	color_text(2);
     	printf(" %d\n",puan);
        color_text(-1);
		printf("\t\t\t\t\tKullanici adi giriniz: ");
		scanf("%s",&final[n].ad);
		
		final[n].skor=puan;
         
         score =fopen("skorlar.txt","a");
    if(score==NULL){
    	printf("dosya bulunamadý\n");
	}
	fprintf(score,"%s %d\n",final[n].ad,final[n].skor);
	
    fclose(score);
    system("cls");
} 
void loadingsc()
{
	int i,j;
	char arr[]={'.','.','.'};
	

    for(i=0; i<3; i++){
    	printf("\n\n\n\n\n\n\n\n");
       	printf("\t\t\t\t\t\t  ");
 	   for(j=0; j<3; j++){
 	   	
 	    printf("%c", arr[i]);
 	     Sleep(100);	   
		    
    }	
    system("cls");
 }
	
}
void color_text(int color)
{
	if(color == -1)
	{
		printf("\x1B[0;39m");
		return;
	}
	printf("\x1B[1;%dm", 30 + color);
}
void skorlarigoster()
{	
struct game temp;
int i=0, n=0;


FILE* score =fopen("skorlar.txt","r");
    if(score==NULL){
    	printf("dosya bulunamadý\n");
	}
	char buffer[200];
	fgets(buffer,200,score);
	
	struct game final[10];
	int j=0;
	while(!feof(score)){
		
	struct game* f =final +j;
	sscanf(buffer,"%s %d", f->ad, &f->skor);
	
	fgets(buffer,200,score);
	j++;			
	}
	n=j;
	/*for(j=0; j<n; j++){
		printf("%s %d\n",final[j].ad,final[j].skor);
	}  */
	

 			
    for (i = 0; i < n-1; i++)  {
    	
    	   for (j = 0; j < n-i-1; j++)  {
    	   	
    	   	if (final[j+1].skor > final[j].skor)  {
    	   		temp=final[j];
    	   		
    	   		final[j]=final[j+1];
    	   		final[j+1]=temp;
			   }
		   } 
	}   
	system("cls");
	loadingsc();
	color_text(1);
	printf("\n\n\n\n\n\n\n\t\t\t\t\t----EN YÜKSEK SKORLAR----");
	PlaySound(TEXT("D:\\swoosh.wav"),NULL,SND_SYNC);  
	color_text(-1);
	printf("\n\n\n");
	Sleep(500);
	for(j=0; j<n; j++){		
		printf("%50s",final[j].ad);
		printf("-");
		Sleep(100);
		printf("-");
		Sleep(100);
		printf(">");
		color_text(2);
		printf("%3d\n",final[j].skor);
		Sleep(300);
		color_text(-1);
		if(j==2)
		break;
		
	}
	Sleep(1300);
	system("cls");

	
fclose(score);
}


 int enterChoice( void )
 { 
 int menuChoice; 
 system("color 2");
 color_text(4);
 
 printf( "\n\n\n\n\n\n\t\t\t ---------Yapmak istediðiniz iþlemi seçiniz---------\n");
 color_text(3);
 printf( "\t\t\t           1 - Sorularý göster ve güncelle\n");
 printf( "\t\t\t           2 - Yeni soru ekle\n");                             
 printf( "\t\t\t           3 - Soru sil\n");   
 printf( "\t\t\t           4 - Oyun oyna\n");                                 
 printf( "\t\t\t           5 - En yüksek skorlarý göster\n");                               
 printf( "\t\t\t           6 - Dosyayi \"sorular.txt\" yazýn\n");  
 printf( "\t\t\t           7 - Uygulamayý sonlandýr\n");                             

 printf("\t\t\t\t");
 scanf( "%d", &menuChoice ); 
 color_text(-1);
 return menuChoice;

 }
