// Sequential Circuits Truth Table Generator
// Adhirama Dwi Syaputra, 2206024524, Grup 10
// Attafahqi Amirtha Dariswan, 2206029891, Grup 10
// Created: 4 Desember 2023     Last Updated: 21.00
// Version: 1.0

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

struct TruthTable{
	int ps[4];
	int ns[4];
};

struct FlipFlop{
	char s[4];
	char r[4];
	char d[4];
	char j[4];
	char k[4];
	char t[4];
};

void srff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n);
void dff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n);
void jkff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n);
void tff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n);

void merah();
void hijau();
void kuning();
void reset();

int main(){
	int bit;
	int n;
	int ff;
	int i;
	int l;
	

	printf("Sequential Circuits Truth Table Generator\n\n");
	printf("=========================================\n");
	printf("=== Selamat Datang Mahasiswa DTE FTUI ===\n");
	printf("=========================================\n");
	
	//melakukan looping pada program
	do{
		//input bit untuk menentukan jumah input dan output
		printf("\n\nMasukan jumlah bit (1-4) -> (0 jika ingin menyudahi): ");
		scanf("%d", &bit);
		
		//error handling
		if(bit>4 || bit<0){
			printf("\nTidak dapat menggunakan jumlah bit sebanyak itu, mohon input ulang");
			continue;
		}
		
		//nilai sentinel
		if(bit==0){
			break;
		}
		
		//jumlah data yang diminta sama dengan 2 pangkat jumlah bit
		n = pow(2,bit);
		
		//declare struct dan ukurannya
		struct TruthTable *truthtable = malloc(n * sizeof(struct TruthTable));
		struct FlipFlop *flipflop = malloc(n * sizeof(struct FlipFlop));
		
		//memilih flipflop
		printf("\n1.SR FlipFlop\n2.D FlipFlop\n3.JK FlipFlop\n4.T FlipFlop\nPilihlah FlipFlop yang ingin digunakan (1-4) : ");
		scanf("%d", &ff);
		
		//input present state
		printf("\nMasukanlah Present State :\n");
		
		//input 1 bit
		if(bit == 1){
			printf("A\n");
			for (i=0 ; i<n ; i++){
				scanf("%d", &truthtable[i].ps[0]);
			}
		}
		
		//input 2 bit
		else if(bit == 2){
			printf("A	B\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d", &truthtable[i].ps[0], &truthtable[i].ps[1]);
			}
		}
		
		//input 3 bit
		else if(bit == 3){
			printf("A	B	C\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d	%d", &truthtable[i].ps[0], &truthtable[i].ps[1], &truthtable[i].ps[2]);
			}
		}
		
		//input 4 bit
		else if(bit == 4){
			printf("A	B	C	D\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d	%d	%d", &truthtable[i].ps[0], &truthtable[i].ps[1], &truthtable[i].ps[2], &truthtable[i].ps[3]);
			}
		}
		
		//input next state
		printf("\nMasukanlah Next State :\n");
		
		//input 1 bit
		if(bit == 1){
			printf("A\n");
			for (i=0 ; i<n ; i++){
				scanf("%d", &truthtable[i].ns[0]);
			}
		}
		
		//input 2 bit
		else if(bit == 2){
			printf("A	B\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d", &truthtable[i].ns[0], &truthtable[i].ns[1]);
			}
		}
		
		//input 3 bit
		else if(bit == 3){
			printf("A	B	C\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d	%d", &truthtable[i].ns[0], &truthtable[i].ns[1], &truthtable[i].ns[2]);
			}
		}
		
		//input 4 bit
		else if(bit == 4){
			printf("A	B	C	D\n");
			for (i=0 ; i<n ; i++){
				scanf("%d	%d	%d	%d", &truthtable[i].ns[0], &truthtable[i].ns[1], &truthtable[i].ns[2], &truthtable[i].ns[3]);
			}
		}
		
		//SR FlipFlop
		if(ff == 1){
			srff(truthtable, flipflop,bit, n);
		}
		//D FlipFlop
		else if(ff == 2){
			dff(truthtable, flipflop,bit, n);
		}
		//JK FlipFlop
		else if(ff == 3){
			jkff(truthtable, flipflop,bit, n);
		}
		
		//T FlipFlop
		else if(ff == 4){
			tff(truthtable, flipflop,bit, n);
		}
		
		free(truthtable);
		free(flipflop);
				
	}while(1);
	
	printf("\nThank You For Coming\n- Atta E'22 and Adhi E'22\n");
	
	return 0;	
}

//fungsi sr flipflop
void srff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n){
	int i;
	int l;
	
	//menerapkan tabel eksitasi
	for(i=0 ; i<n; i++){
		for (l=0 ; l<bit ; l++){
			if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 0){
				flipflop[i].s[l] = '0';
				flipflop[i].r[l] = 'X';
			}
			else if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 1){
				flipflop[i].s[l] = '1';
				flipflop[i].r[l] = '0';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 0){
				flipflop[i].s[l] = '0';
				flipflop[i].r[l] = '1';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 1){
				flipflop[i].s[l] = 'X';
				flipflop[i].r[l] = '0';
			}
			//error handing
			else{
				l = bit;
				i = n;
				bit = 0;
			}
		}		
	}
	
	//error handing	
	if(bit>0 && bit<=4){
		printf("\nTruth Table FlipFlop :\n");
		
		if(bit == 1){
			printf("---------\n");
			printf("SA	RA\n");
			printf("---------\n");
		}
		else if(bit == 2){
			printf("--------------------------\n");
			printf("SA	RA	SB	RB\n");
			printf("--------------------------\n");
		}
		else if(bit == 3){
			printf("-----------------------------------------\n");
			printf("SA	RA	SB	RB	SC	RC\n");
			printf("-----------------------------------------\n");
		}
		else if(bit == 4){
			printf("---------------------------------------------------------\n");
			printf("SA	RA	SB	RB	SC	RC	SD	RD\n");
			printf("---------------------------------------------------------\n");
		}
		
		for(i=0 ; i<n ; i++){
			for(l=0 ; l<bit; l++){
				if(flipflop[i].s[l] == '0'){
					merah();
				}
				else if(flipflop[i].s[l] == '1'){
					hijau();
				}
				else if(flipflop[i].s[l] == 'X'){
					kuning();
				}
				
				printf("%c	", flipflop[i].s[l]);
				
				usleep(50 * 1000);
				
				if(flipflop[i].r[l] == '0'){
					merah();
				}
				else if(flipflop[i].r[l] == '1'){
					hijau();
				}
				else if(flipflop[i].r[l] == 'X'){
					kuning();
				}
				printf("%c	", flipflop[i].r[l]);
				
				usleep(50 * 1000);
			}
			printf("\n");
			reset();
		}
		if(bit == 1){
			printf("---------\n");
		}
		else if(bit == 2){
			printf("--------------------------\n");
		}
		else if(bit == 3){
			printf("-----------------------------------------\n");
		}
		else if(bit == 4){
			printf("---------------------------------------------------------\n");
		}
	}
	else{
		printf("\nAda yang salah dari input anda, silahkan input ulang");
	}
}

//fungsi d flipflop
void dff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n){
	int i;
	int l;
	
	//menerapkan tabel eksitasi
	for(i=0 ; i<n; i++){
		for (l=0 ; l<bit ; l++){
			if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 0){
				flipflop[i].d[l] = '0';
			}
			else if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 1){
				flipflop[i].d[l] = '1';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 0){
				flipflop[i].d[l] = '0';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 1){
				flipflop[i].d[l] = '1';
			}
			//error handing
			else{
				l = bit;
				i = n;
				bit = 0;
			}
		}
			
	}
	
	//error handing
	if(bit>0 && bit<=4){
		printf("\nTruth Table FlipFlop :\n");
		
		if(bit == 1){
			printf("-\n");
			printf("DA\n");
			printf("-\n");
		}
		else if(bit == 2){
			printf("---------\n");
			printf("DA	DB\n");
			printf("---------\n");
		}
		else if(bit == 3){
			printf("-----------------\n");
			printf("DA	DB	DC\n");
			printf("-----------------\n");
		}
		else if(bit == 4){
			printf("-------------------------\n");
			printf("DA	DB	DC	DD\n");
			printf("-------------------------\n");
		}
		
		for(i=0 ; i<n ; i++){
			for(l=0 ; l<bit; l++){
				if(flipflop[i].d[l] == '0'){
					merah();
				}
				else if(flipflop[i].d[l] == '1'){
					hijau();
				}
				printf("%c	", flipflop[i].d[l]);
				usleep(50 * 1000);
			}
			printf("\n");
			reset();
		}
		if(bit == 1){
			printf("-\n");
		}
		else if(bit == 2){
			printf("---------\n");
		}
		else if(bit == 3){
			printf("-----------------\n");
		}
		else if(bit == 4){
			printf("-------------------------\n");
		}
	}
	else{
		printf("\nAda yang salah dari input anda, silahkan input ulang");
	}
}

//fungsi jk flipflop
void jkff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n){
	int i;
	int l;
	
	//menerapkan tabel eksitasi
	for(i=0 ; i<n; i++){
		for (l=0 ; l<bit ; l++){
			if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 0){
				flipflop[i].j[l] ='0';
				flipflop[i].k[l] ='X';
			}
			else if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 1){
				flipflop[i].j[l] ='1';
				flipflop[i].k[l] ='X';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 0){
				flipflop[i].j[l] ='X';
				flipflop[i].k[l] ='1';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 1){
				flipflop[i].j[l] ='X';
				flipflop[i].k[l] ='0';
			}
			//error handing
			else{
				l = bit;
				i = n;
				bit = 0;
			}
		}
			
	}
	
	//error handing	
	if(bit>0 && bit<=4){
		printf("\nTruth Table FlipFlop :\n");
		
		if(bit == 1){
			printf("---------\n");
			printf("JA	KA\n");
			printf("---------\n");
		}
		else if(bit == 2){
			printf("-------------------------\n");
			printf("JA	KA	JB	KB\n");
			printf("-------------------------\n");
		}
		else if(bit == 3){
			printf("-----------------------------------------\n");
			printf("JA	KA	JB	KB	JC	KC\n");
			printf("-----------------------------------------\n");
		}
		else if(bit == 4){
			printf("---------------------------------------------------------\n");
			printf("JA	KA	JB	KB	JC	KC	JD	KD\n");
			printf("---------------------------------------------------------\n");
		}
		
				
		for(i=0 ; i<n ; i++){
			for(l=0 ; l<bit; l++){
				if(flipflop[i].j[l] == '0'){
					merah();
				}
				else if(flipflop[i].j[l] == '1'){
					hijau();
				}
				else if(flipflop[i].j[l] == 'X'){
					kuning();
				}
				
				printf("%c	", flipflop[i].j[l]);
				
				usleep(50 * 1000);
				
				if(flipflop[i].k[l] == '0'){
					merah();
				}
				else if(flipflop[i].k[l] == '1'){
					hijau();
				}
				else if(flipflop[i].k[l] == 'X'){
					kuning();
				}
				printf("%c	", flipflop[i].k[l]);
				
				usleep(50 * 1000);
			}
			printf("\n");
			reset();
		}
		if(bit == 1){
			printf("---------\n");
		}
		else if(bit == 2){
			printf("--------------------------\n");
		}
		else if(bit == 3){
			printf("-----------------------------------------\n");
		}
		else if(bit == 4){
			printf("---------------------------------------------------------\n");
		}
	}
	else{
		printf("\nAda yang salah dari input anda, silahkan input ulang");
	}
}


//fungsi t flipflop
void tff(struct TruthTable* truthtable, struct FlipFlop* flipflop, int bit, int n){
	int i;
	int l;
	//menerapkan tabel eksitasi
	for(i=0 ; i<n; i++){
		for (l=0 ; l<bit ; l++){
			if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 0){
				flipflop[i].t[l] ='0';
			}
			else if(truthtable[i].ps[l] == 0 && truthtable[i].ns[l] == 1){
				flipflop[i].t[l] ='1';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 0){
				flipflop[i].t[l] ='1';
			}
			else if(truthtable[i].ps[l] == 1 && truthtable[i].ns[l] == 1){
				flipflop[i].t[l] ='0';
			}
			//error handing
			else{
				l = bit;
				i = n;
				bit = 0;
			}
		}
			
	}
	//error handing
	if(bit>0 && bit<=4){
		printf("\nTruth Table FlipFlop :\n");
		
		if(bit == 1){
			printf("-\n");
			printf("TA\n");
			printf("-\n");
		}
		else if(bit == 2){
			printf("---------\n");
			printf("TA	TB\n");
			printf("---------\n");
		}
		else if(bit == 3){
			printf("-----------------\n");
			printf("TA	TB	TC\n");
			printf("-----------------\n");
		}
		else if(bit == 4){
			printf("-------------------------\n");
			printf("TA	TB	TC	TD\n");
			printf("-------------------------\n");
		}
		
		for(i=0 ; i<n ; i++){
			for(l=0 ; l<bit; l++){
				if(flipflop[i].t[l] == '0'){
					merah();
				}
				else if(flipflop[i].t[l] == '1'){
					hijau();
				}
				printf("%c	", flipflop[i].t[l]);
				usleep(50 * 1000);
			}
			reset();
			printf("\n");
		}
		if(bit == 1){
			printf("-\n");
		}
		else if(bit == 2){
			printf("---------\n");
		}
		else if(bit == 3){
			printf("-----------------\n");
		}
		else if(bit == 4){
			printf("-------------------------\n");
		}
	}
	else{
		printf("\nAda yang salah dari input anda, silahkan input ulang");
	}	
}

void merah(){
	printf("\033[1;31m");
}
void hijau(){
	printf("\033[1;32m");
}
void kuning(){
	printf("\033[1;33m");
}
void reset(){
	printf("\033[0m");
}
