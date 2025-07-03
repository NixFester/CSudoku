#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printSudoku(int *ptr); // print papan
int pembuat(int *ptr); // fungsi pembuat
char isAman(int *ptr, int x, int y, int angka); // pengecekan
void acakArr(int angka[9]); // Shuffle fisher-Yate
int bwtSelKsng(int *sudoku); // buat sel yang kosong
int rekursifAcakUnik(int *arrPtr); //fungsi rekursif untuk mengisi array dengan
								   //No acak yang unik
int inputUsr(int nlMax); // mengecek input pengguna apakah nilai yang dimasukan terlalu besar
void mulaiGame(int *papan, int *papanAsli); // mulai game


int main() {
	int *ptrPapapn = calloc(81, sizeof(int)); // papanya
	if (ptrPapapn == NULL) {
		fprintf(stderr, "Memory allocation gagal\n");
		return 1;
	}	
    srand(time(NULL)); // bennih random
    if (pembuat(ptrPapapn)) {
		//duplikasi dengan malloc
		int *dupPtr = (int *)malloc(9*9*sizeof(int));
		if (dupPtr == NULL) {
			fprintf(stderr,"Memory allocation gagal\n");
			return 1;
		}
		memcpy(dupPtr,ptrPapapn, 9*9*sizeof(int));
		if (bwtSelKsng(dupPtr)){
			mulaiGame(dupPtr,ptrPapapn);
		} else {
			printf("gagal");
		}
		free(ptrPapapn);
		free (dupPtr);
    } else {
        printf("Gagal :c\n");
    }
    system("pause");
    return 0;
}

void mulaiGame(int *papan,int *papanAsli){
	printSudoku(papan);
	printf("Ingat! letak x dari kiri ke kanan\nLetak y dari atas ke bawah!\n");
	printf("x adalah KOLOM sudoku dan y adalah BARIS sudoku\n");
	printf("Tanda titik (.) menunjukkan sel kosong yang bisa diisi.\n");
	printf("Apakah anda ingin mengubah salah satu nilai dari sudoku diatas?\n1. Ya!\n2. Tidak!\n3. Keluar!\nJawab: ");
	int isi = inputUsr(3);
	if (isi == 1){
		int nilaix, nilaiy, nilaiganti;
		printf("Masukan letak x dari nilai yang ingin diubah: ");
		nilaix = inputUsr(9) -1;
		printf("Masukan letak y dari nilai yang ingin diubah: ");
		nilaiy = inputUsr(9) -1;
		printf("Nilai awal: %d Masukan Nilai baru: ", *(papan + (9*nilaiy) + nilaix));
		nilaiganti = inputUsr(9);

		if (*(papan + (9*nilaiy) + nilaix) != 0) {
			printf("Tidak bisa ubah angka asli!\n");
		} else {
			*(papan + (9*nilaiy) + nilaix) = nilaiganti;
		}
		mulaiGame(papan, papanAsli);
	} else if (isi == 2){
		int skor =0;
		for (int i = 0; i<81; i++){
			if (*(papanAsli + i) == *(papan + i)){
				skor++;
			}
		}
		printf("Skor anda: %d benar dari 81\n", skor);
		printf("\nSolusi yang benar:\n");
		printSudoku(papanAsli);
	}
}


int inputUsr(int nlMax){
	int b;
	scanf("%d",&b);
	if (b > nlMax){
    printf("Error: Tidak ada pilihan %d\nCoba lagi: ", b);
    return inputUsr(nlMax); // Fix: forward the result of recursive call
	} else {
    	return b;
	}
}

int bwtSelKsng(int *sudoku){
	int *emptyCellPtr = calloc(45,sizeof(int));
	if (emptyCellPtr == NULL) {
			fprintf(stderr,"Memory allocation gagal\n");
			return 0;
		}
	if (rekursifAcakUnik(emptyCellPtr)){
		for (int i = 0;i<45;i++){
			//ganti arr sudoku indeks random yang ada di emptycell ke 0
			*(sudoku + *(emptyCellPtr+i)) = 0;
		}
	} else {
		printf("rekursif gagal");
	}
	free(emptyCellPtr);
	return 1;
}

int rekursifAcakUnik(int *arrPtr){
    int i, j;
    int found = 0;
    char sama = 'n';

    // 🔒 Static variable tuntuk menghitung kedalaman percobaan
    static int attempt = 0;
    attempt++;

    // 🛑 Jika terlalu dalam maka stop!
    if (attempt > 10000) {
        printf("Terlalu banyak percobaan rekursif! Gagal.\n");
        return 0;
    }

    // cek ada yang kosong ga?
    for (i = 0; i < 45; i++) {
        if (*(arrPtr + i) == 0) {
            found = 1;
            break;
        }
    }

    // kalau ga ada yang kosong, selesai
    if (!found) {
        attempt = 0; // ✅ Reset attempt counter on successful end
        return 1;
    }

    int noAcak = rand() % 81;

    for (j = 0; j < 45; j++) {
        if (*(arrPtr + j) == noAcak) {
            sama = 'y';
        }
    }

    if (sama == 'n') {
        *(arrPtr + i) = noAcak;
        if (rekursifAcakUnik(arrPtr)) {
            return 1;
        }
    } else {
        *(arrPtr + i) = 0; // backtrack
        if (rekursifAcakUnik(arrPtr)) {
            return 1;
        }
    }

    return 0;
}


int pembuat(int *ptr) {
    int row, col;
    int found = 0;

    // cari yang kosong
    for (col = 0; col < 9; col++) {
        for (row = 0; row < 9; row++) {
            if (*(ptr + (9*col) + row )== 0) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    // ga ada yang kosong pulang
    if (!found) return 1;

    int angka[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    acakArr(angka); // acak ankaaa

    for (int i = 0; i < 9; i++) {
        if (isAman(ptr, col, row, angka[i]) == 'y') {
            *(ptr + (9*col) + row ) = angka[i];
            if (pembuat(ptr)) {
                return 1;
            }
            *(ptr + (9*col) + row ) = 0; // Backtrack
        }
    }

    return 0; // backtracking
}

char isAman(int *ptr, int x, int y, int angka) {
    // Check baris
    for (int row = 0; row < 9; row++) {
        if (*(ptr + (9*x) + row ) == angka) {
            return 'n';
        }
    }
    // Check baris
    for (int col = 0; col < 9; col++) {
        if (*(ptr + (9*col) + y ) == angka) {
            return 'n';
        }
    }
    // Check 1 kotak
    int startCol = x - x % 3, startRow = y - y % 3;
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 3; row++) {
            if (*(ptr + (9*(col + startCol)) + (row + startRow) ) == angka) {
                return 'n';
            }
        }
    }
    return 'y';
}


void acakArr(int angka[9]) {
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1);
        int tempor = angka[i];
        angka[i] = angka[j];
        angka[j] = tempor;
    }
}

void printSudoku(int *ptr) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (i == 0) {
            printf("    1 2 3   4 5 6   7 8 9\n");
        }
        if (i == 0 || (i % 3) == 0) {
            printf("  -------------------------\n");
        }
        for (j = 0; j < 9; j++) {
            if (j == 0) {
                printf("%d ", i + 1);
            }

            if (j == 0 || (j % 3) == 0) {
                printf("| ");
            }

            int val = *(ptr + (9*i) + j);
            if (val == 0)
                printf(". ");
            else
                printf("%d ", val);

            if (j == 8) {
                printf("|\n");
            }
        }
        if (i == 8) {
            printf("  -------------------------\n");
        }
    }
}
