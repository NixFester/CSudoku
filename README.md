# 🧩 Sudoku CLI Game (C) | 🎮 Game Sudoku Terminal (C)

A terminal-based Sudoku generator and interactive game written in C.  
Game Sudoku interaktif berbasis terminal, ditulis dengan bahasa C.

---

## 📦 Features | 📦 Fitur

| English                                         | Bahasa Indonesia                                 |
|------------------------------------------------|--------------------------------------------------|
| ✅ Generates a valid Sudoku board              | ✅ Membuat papan Sudoku yang valid               |
| 🔄 Randomized each run                         | 🔄 Diacak setiap kali dijalankan                 |
| 👤 Lets player input answers                   | 👤 Pemain dapat mengisi sel kosong              |
| ⛔ Prevents editing original clues             | ⛔ Tidak bisa ubah angka asli                   |
| 📊 Score out of 81                             | 📊 Skor dari total 81 sel                       |
| 📺 ASCII grid, terminal friendly               | 📺 Tampilan kotak ASCII, ramah terminal         |

---

## 🚀 How to Compile | 🚀 Cara Kompilasi

```bash
# English
gcc advProgC.c -o sudoku.exe

# Indonesia
# Pastikan sudah install gcc
gcc advProgC.c -o sudoku.exe
```

---

## ▶️ How to Run | ▶️ Cara Menjalankan

```bash
./sudoku.exe
```

> English: The program will pause before closing.  
> Indonesia: Program akan menunggu input Enter sebelum keluar.

---

## 📷 Sample Output | 📷 Contoh Output

```
    1 2 3   4 5 6   7 8 9
  -------------------------------
1 | 5 . 7 | . . 2 | 8 1 9 |
2 | 1 4 3 | . 6 . | 7 . . |
3 | . 6 . | . 8 . | 5 2 4 |
  -------------------------------
4 | . . 8 | 5 . . | 6 7 1 |
5 | 6 2 1 | . 7 . | 4 . . |
6 | . 7 5 | 1 . . | 2 9 . |
  -------------------------------
7 | . 1 6 | . . 8 | 3 . 7 |
8 | 3 . 9 | 7 . . | . . 6 |
9 | 2 5 4 | 6 3 . | 1 . . |
  -------------------------------
```

---

## 🎮 Instructions | 🎮 Petunjuk

| English                                           | Bahasa Indonesia                                 |
|--------------------------------------------------|--------------------------------------------------|
| Enter `x` (column) and `y` (row) for a cell      | Masukkan `x` (kolom) dan `y` (baris)            |
| Cannot change original numbers (`≠ 0`)           | Tidak bisa ubah angka asli (`≠ 0`)              |
| After finishing, it shows your score             | Setelah selesai, akan tampil skor Anda          |
| Game ends with correct answer shown              | Game berakhir dengan solusi yang benar          |

---

## 🧠 File Structure | 🧠 Struktur File

| File         | Description (EN)                 | Deskripsi (ID)                       |
|--------------|----------------------------------|--------------------------------------|
| `advProgC.c` | Main C file with all logic       | File utama berisi logika Sudoku     |
| `sudoku.exe` | Compiled executable (Windows)    | Program hasil kompilasi (Windows)   |

---

## 🛠️ License

This project is for learning and non-commercial use.  
Proyek ini untuk pembelajaran dan penggunaan non-komersial.

